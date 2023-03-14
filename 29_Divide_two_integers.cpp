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
    int divide(int dividend, int divisor) {
        int first_pos = (dividend < 0)? -1: 1;
        int div_pos = (divisor < 0)? -1: 1;
        long quotient = 0;
        long dividend_new = dividend;
        long divisor_new = divisor;
        dividend_new = abs(dividend_new);
        divisor_new = abs(divisor_new);
        cout << dividend_new << " " << divisor_new << endl;
        while(dividend_new >= divisor_new){
            dividend_new -= divisor_new;
            quotient += 1;
        }
        return quotient*div_pos*first_pos;
    }
};

int main(int argc, char const *argv[])
{   
    Solution solve;
    int dividend = -2147483648;
    int divisor = -1;
    cout << solve.divide(dividend, divisor) << endl;
    return 0;
}