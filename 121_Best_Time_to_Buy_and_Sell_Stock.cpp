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
        auto max_price_iter = max_element(prices.begin(), prices.end());
        auto min_price_iter = min_element(prices.begin(), prices.end());
        int strategy_a = *max_price_iter \
            - *min_element(prices.begin(), max_price_iter);
        int strategy_b = *max_element(min_price_iter, prices.end())\
            - *min_price_iter;
        return max(strategy_a, strategy_b);
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