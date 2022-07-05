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
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        vector<int> leftmost(4, -1);
        vector<int> rightmost(4, -1);
        vector<int> tmp(colors.size(), INT_MAX);
        vector<vector<int>> near_most_dis(4, tmp);
        for(int i=0;i<colors.size();i++){
            int cur_color = colors[i];
            leftmost[cur_color] = i;
            for(int j=1;j<=3;j++){
                // iterate 3 colors
                if(leftmost[j] != -1){
                    near_most_dis[j][i] = i - leftmost[j];
                }
            }
        }
        for(int i=colors.size()-1;i>=0;i--){
            int cur_color = colors[i];
            rightmost[cur_color] = i;
            for(int j=1;j<=3;j++){
                // iterate 3 colors
                if(rightmost[j] != -1){
                    near_most_dis[j][i] = min(near_most_dis[j][i], rightmost[j] - i);
                }
            }
        }
        // for(int j=1;j<=3;j++){
        //     // iterate 3 colors
        //     print_int_vec(near_most_dis[j]);
        // }
        vector<int> res;
        res.reserve(queries.size());
        for(auto query:queries){
            int tar_color = query[1];
            int tar_index = query[0];
            if(near_most_dis[tar_color][tar_index] == INT_MAX){
                res.push_back(-1);
            }
            else{
                res.push_back(near_most_dis[tar_color][tar_index]);
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{   
    Solution solve;
    // vector<int> input{1,1,2,1,3,2,2,3,3};
    vector<int> input{1,2};
    vector<int> q1{1,3};
    // vector<int> q2{2,2};
    // vector<int> q3{6,1};
    // vector<vector<int>> qerys{q1, q2, q3};
    vector<vector<int>> qerys{q1};
    print_int_vec(solve.shortestDistanceColor(input, qerys));
    return 0;
}