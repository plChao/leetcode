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
        for(int i=1;i<prices.size();i++){
            int profit = prices[i] - prices[i-1];
            if(profit > 0){
                res += profit;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{   
    Solution solve;
    vector<int> input{1, 2, 1, 2};
    // print_int_vec(solve.maxProfit(input));
    cout << solve.maxProfit(input) << endl;
    return 0;
}