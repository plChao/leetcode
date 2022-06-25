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
    tuple<int, int> get_vector_max_num(vector<int> & vec){
        // O(n), return the position of max element in vector
        int pos = 0, maxi = vec[0]; 
        for(int i=0;i<vec.size();i++){
            if(vec[i] > maxi){
                pos = i;
                maxi = vec[pos];
            }
        }
        return make_tuple(pos, vec[pos]);
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int l = 0, r = mat.size() - 1;
        while(l != r){
            int mid = l + (r - l) / 2;
            if(get<1>(get_vector_max_num(mat[mid])) < get<1>(get_vector_max_num(mat[mid+1]))){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
        vector<int> res{l, get<0>(get_vector_max_num(mat[l]))};
        return res;   
    }
};

int main(int argc, char const *argv[])
{   
    Solution solve;
    vector<int> input_a{1, 2, 1, 2};
    vector<vector<int>> input{input_a};
    print_int_vec(solve.findPeakGrid(input));
    return 0;
}