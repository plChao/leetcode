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
        unordered_set<int> first_seen;
        sort(nums.begin(), nums.end());
        int closest_diff = nums[0] + nums[1] + nums[2] - target;
        // cout << closest_diff << endl;
        for(int i=0;i<nums.size()-2;i++){
            if(!first_seen.insert(nums[i]).second){
                continue;
            }
            int remain = target - nums[i];
            int lo = i+1, hi = nums.size() - 1;
            while(lo < hi){
                if(abs(nums[lo] + nums[hi] - remain) < abs(closest_diff)){
                    closest_diff = nums[lo] + nums[hi] - remain;
                }
                if(nums[lo] + nums[hi] == remain){
                    return target;
                }
                else if(nums[lo] + nums[hi] < remain){
                    lo ++;
                }
                else{
                    hi --;
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