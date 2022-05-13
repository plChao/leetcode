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
    vector<vector<int>> recur_permutation(vector<int> all, vector<int> element)
    {
        // get all the permutation of vector all elements
        vector<vector<int>> res;
        vector<vector<int>> subresult;
        if (all.size() == 1)
        {
            res.push_back(all);
            return res;
        }
        else
        {
            for (int i = 0; i <= element.size(); i++)
            {
                // pop out the elements[i] from all
                vector<int> tmp = all;
                auto ptr = lower_bound(tmp.begin(), tmp.end(), element[i]);
                if (*ptr == element[i])
                {
                    tmp.erase(ptr);
                    subresult = recur_permutation(tmp, element);
                }
                for (auto ele : subresult)
                {
                    ele.push_back(element[i]);
                    res.push_back(ele);
                }
                subresult.clear();
            }
            return res;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums){
        sort(nums.begin(), nums.end());
        vector<int> element (nums.begin(), nums.end());
        auto last = unique(element.begin(), element.end());  
        element.erase(last, element.end());
        return recur_permutation(nums, element);
    }
};

int main(int argc, char const *argv[])
{   
    Solution solve;
    vector<int> input{1, 2, 1};
    for(auto i:solve.permuteUnique(input)){
        print_int_vec(i);
    }
    return 0;
}