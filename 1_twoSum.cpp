#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<cmath>
#include<hash_map> // need to paste to leetcode

using namespace std;
using namespace __gnu_cxx; // need to paste to leetcode

void print_int_vec(vector<int> tar){
    for(auto i: tar){
        cout << i << " ";
    }
    cout << endl;
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        hash_map<int, int> mymap;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            mymap[nums[i]] = i;
        }
        for(int i=0;i<nums.size();i++){
            int remain = target - nums[i];
            if(mymap.count(remain) && mymap[remain] != i){
                ans.push_back(i);
                ans.push_back(mymap[remain]);
                return ans;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{   
    Solution solve;
    vector<int> input{1, 2, 3, 4};
    print_int_vec(solve.twoSum(input, 5));
    return 0;
}