#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<sstream>
#include<algorithm>

using namespace std;

void print_int_vec(vector<int> tar){
    for(auto i: tar){
        cout << i << " ";
    }
    cout << endl;
}

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> res, new_res;
        for(int i=0;i<nums.size();i++){
            sort(nums[i].begin(), nums[i].end());
            print_int_vec(nums[i]);
        }
        if(nums.size() == 1){
            return nums[0];
        }
        else if(nums.size() == 0){
            return res;
        }
        else{
            res = nums[0];
            auto ptr1 = res.begin();
            for(int i=1;i<nums.size();i++){
                print_int_vec(res);
                int k = 0, m = 0;
                for(;k<res.size() && m<nums[i].size();){
                    if(res[k] == nums[i][m]){
                        new_res.push_back(res[k]);
                        k++;
                        m++;
                    }
                    else if(res[k] < nums[i][m]){
                        k++;
                    }
                    else{
                        m++;
                    }
                }
                print_int_vec(new_res);
                res = new_res;
                new_res.clear();
            }
            return res;
        }

    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> nums = {{3,1,2,4,5},{1,2,3,4},{3,4,5,6}};
    print_int_vec(s.intersection(nums));
    return 0;
}