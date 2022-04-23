#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<cmath>

using namespace std;

void print_int_vec(vector<int> tar){
    for(auto i: tar){
        cout << i << " ";
    }
    cout << endl;
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mymap;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int remain = target - nums[i];
            if(mymap.find(remain) != mymap.end()){
                ans.push_back(mymap[remain]);
                ans.push_back(i);
                return ans;
            }
            mymap[nums[i]] = i;
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