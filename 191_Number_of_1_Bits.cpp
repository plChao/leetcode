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
    int hammingWeight(uint32_t n) {
        int res = 0;
        for(int i=0;i<32;i++){
            if((n >> i) & 1 == 1){
                res += 1;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{   
    Solution solve;
    cout << solve.hammingWeight(100) << endl;
    return 0;
}