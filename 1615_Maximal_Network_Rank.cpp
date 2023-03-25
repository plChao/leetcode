#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<sstream>
#include<unordered_set>
#include<algorithm>
#include<cctype>
#include<set>
#include<map> 
using namespace std;

void print_int_vec(vector<int> tar){
    for(auto i: tar){
        cout << i << " ";
    }
    cout << endl;
}

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads){
        int * size_cnt = new int[n + 1];
        fill(size_cnt, size_cnt + n, 0);
        bool** adj_matrix = new bool*[n];
        for(int i = 0; i < n; ++i){
            adj_matrix[i] = new bool[n];
            fill(adj_matrix[i], adj_matrix[i] + n, false);
        }
        int from, to, linked;
        for(int i=0;i<roads.size();i++){
            from = roads[i][0];
            to = roads[i][1];
            size_cnt[from] += 1;
            size_cnt[to] += 1;
            adj_matrix[from][to] = true;
            adj_matrix[to][from] = true;
        }
        int max_rank = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int linked = (adj_matrix[i][j]) ? 1:0;
                max_rank = max(size_cnt[i] + size_cnt[j] - linked, max_rank);
            }
        }
        return max_rank;
    }
};

int main(int argc, char const *argv[])
{   
    Solution solve;
    vector<vector<int>> input{{0,1},{0,3},{1,2},{1,3}};
    // vector<vector<int>> input{};
    // print_int_vec(solve.temp_function(input));
    cout << solve.maximalNetworkRank(4, input) << endl;
    return 0;
}