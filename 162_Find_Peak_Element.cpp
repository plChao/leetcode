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
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(l != r){
            int mid = (l + r) / 2;
            // cout << l << " " << r << " " << mid << endl;
            if(nums[mid] < nums[mid + 1]){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
        return l;
    }
};

int main(int argc, char const *argv[])
{   
    Solution solve;
    vector<int> input{1, 2, 4, 3};
    cout << solve.findPeakElement(input) << endl;
    return 0;
}