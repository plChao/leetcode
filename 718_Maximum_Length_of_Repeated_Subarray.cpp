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
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int dp[nums1.size()][nums2.size()];
        // int** dp = new int*[nums1.size()];
        // for(int i = 0; i < nums1.size(); ++i)
        //     dp[i] = new int[nums2.size()];
        int res = 0;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i] == nums2[0]){
                dp[i][0] = 1;
                res = 1;
            }
            else{
                dp[i][0] = 0;
            }
        }
        for(int j=0;j<nums1.size();j++){
            if(nums2[j] == nums1[0]){
                dp[0][j] = 1;
                res = 1;
            }
            else{
                dp[0][j] = 0;
            }
        }
        for(int i=1;i<nums1.size();i++){
            for(int j=1;j<nums2.size();j++){
                // cout << i << " " << j << endl;
                if(nums1[i] == nums2[j]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                    res = max(res, dp[i][j]);
                }
                else{
                    // cout << i << " " << j << endl;
                    dp[i][j] = 0;
                }
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{   
    Solution solve;
    vector<int> input1{1,2,3,2,1};
    vector<int> input2{3,2,1,4};
    // print_int_vec(solve.findLength(input1, input2));
    cout << solve.findLength(input1, input2) << endl;
    return 0;
}