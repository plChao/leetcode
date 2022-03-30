#include<iostream>
#include<vector>
#include<cstring>
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
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() == 1){
            vector<int> empty = {};
            result.push_back(empty);
            result.push_back(nums);
            return result;
        }
        int last_ele = nums.back();
        nums.pop_back();
        vector<vector<int>> sub_result = subsets(nums);
        for(auto i:sub_result){
            result.push_back(i);
            i.push_back(last_ele);
            result.push_back(i);
        }
        return result;
    }
};
int main(int argc, char const *argv[])
{   
    vector<int> input = {1, 2, -3};
    Solution s = Solution();
    auto out = s.subsets(input);
    for(auto i:out){
        print_int_vec(i);
    }
    return 0;
}