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
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for(int i=0;i<prices.size();i++){
            auto befor_min = min_element(prices.begin(), prices.begin() + i);
            res = max(res, prices[i] - *befor_min);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{   
    Solution solve;
    vector<int> input{7, 2, 4, 1};
    // vector<int> input{1, 7, 2, 4};
    cout << solve.maxProfit(input) << endl;
    return 0;
}