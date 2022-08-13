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
    double pos_pow(double x, long long int n){
        double res = 1;
        if(n == 1){
            return x;
        }
        else if(n % 2 == 0){
            res = pos_pow(x, n / 2);
            return res * res;
        }
        else{
            res = pos_pow(x, (n - 1) / 2);
            return res * res * x;
        }
    }
    double myPow(double x, int n) {
        if(x == 1){
            return 1;
        }
        if(n > 0){
            return pos_pow(x, n);
        }
        else if(n == 0){
            return 1;
        }
        else{
            // n < 0              
            return 1.0 / pos_pow(x, (long long) -1 * n);
        }
    }
};

int main(int argc, char const *argv[])
{   
    Solution solve;
    vector<int> input{1, 2, 1, 2};
    cout << solve.myPow(2, 10) << endl;
    return 0;
}