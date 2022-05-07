
#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    double sumofvec(vector<int>& nums){
        double sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
        }
        return sum;
    }
    int minimumAverageDifference(vector<int>& nums) {
        double min_avg_diff = INT_MAX, tmp;
        int min_index = -1;
        double first_sum = 0;
        double second_sum = sumofvec(nums);
        for(int i=nums.size()-1;i>=0;i--){
            first_sum += nums[i];
            second_sum -= nums[i];
            int fi_avg = first_sum / (i + 1);
            int sec_avg = (second_sum == 0?0:(second_sum / (nums.size() - i - 1)));
            int ans = fi_avg - sec_avg;
            tmp = (fi_avg > sec_avg)?ans:-ans;
            if(tmp <= min_avg_diff){
                min_index = i;
                min_avg_diff = tmp;
            }
        }
        return min_index;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {2,5,3,9,5,3};
    cout << s.minimumAverageDifference(nums) << endl;
    return 0;
}