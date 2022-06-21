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
    int next_missing_nth(vector<int>& nums, int pos){
        return nums[pos] - nums[0] - pos + 1;
    }
    int missingElement(vector<int>& nums, int k) {
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(next_missing_nth(nums, mid) <= k){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return nums[l-1] + (k - next_missing_nth(nums, l - 1) + 1);
    }
};

int main(int argc, char const *argv[])
{   
    Solution solve;
    vector<int> input{4, 7, 9, 10};
    cout << solve.missingElement(input, 3) << " 8" << endl;
    return 0;
}