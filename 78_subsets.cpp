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
        vector<int> tmp;
        int sets_num = 1 << nums.size();
        tmp.reserve(nums.size());
        result.reserve(sets_num);
        for(int i=0;i<sets_num;i++){
            for(int k=0;k<nums.size();k++){
                if( (i & (1 << k)) >> k == 1){
                    tmp.push_back(nums[k]);
                }
            }
            result.push_back(tmp);
            tmp.clear();
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