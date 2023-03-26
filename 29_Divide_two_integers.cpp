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
#include<climits>
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
            int q = 0;
            while(dividend_new > (divisor_new << (q+1))){
                q++;
            }
            dividend_new -= (divisor_new << q);
            quotient += (1 << q);
        }
        cout << quotient << endl;
        quotient = quotient*div_pos*first_pos;
        if(quotient > INT_MAX){
            return INT_MAX;
        }
        else if (quotient < INT_MIN){
            return INT_MIN;
        }
        else{
            return quotient;
        }
        
    }
};

int main(int argc, char const *argv[])
{   
    Solution solve;
    int dividend = -2147483648;
    int divisor = -1;
    cout << solve.divide(dividend, divisor) << endl;
    cout << solve.divide(10, 3) << endl;
    return 0;
}