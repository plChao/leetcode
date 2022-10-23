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
    int threeSumClosest(vector<int>& nums, int target) {
        // unordered_set<int> first_seen;
        // unordered_set<int> combine_seen;
        sort(nums.begin(), nums.end());
        int closest_diff = nums[0] + nums[1] + nums[2] - target;
        // cout << closest_diff << endl;
        for(int i=0;i<nums.size()-2;i++){
            // if(!first_seen.insert(nums[i]).second){
            //     // cout << "first seen skip" << endl;
            //     continue;
            // }
            for(int j=i+1;j<nums.size()-1;j++){
                int combine = nums[i] + nums[j];
                // if(!combine_seen.insert(nums[i] + nums[j]).second){
                //     continue;
                // }
                int remain = target - combine;
                int upper_closest_idx = upper_bound(nums.begin()+j+1, nums.end(), remain) - nums.begin();
                int lower_closest_idx = upper_closest_idx - 1;
                if(upper_closest_idx < nums.size()){
                    int up_diff = (combine + nums[upper_closest_idx]) - target;
                    // cout << up_diff << " " << closest_diff << endl;
                    closest_diff = (abs(up_diff) < abs(closest_diff))?up_diff:closest_diff;
                }
                if(lower_closest_idx > j){
                    int lo_diff = (combine + nums[lower_closest_idx]) - target;
                    // cout << lo_diff << " " << closest_diff << endl;
                    closest_diff = (abs(lo_diff) < abs(closest_diff))?lo_diff:closest_diff;
                }
            }
        }
        return closest_diff + target;  
    }
};

int main(int argc, char const *argv[])
{   
    Solution solve;
    vector<int> input{1, 1, 1, 0};
    // print_int_vec(solve.threeSumClosest(input));
    cout << solve.threeSumClosest(input, 100) << endl;
    return 0;
}