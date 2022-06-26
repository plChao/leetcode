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
#include<cmath> 
using namespace std;

void print_int_vec(vector<int> tar){
    for(auto i: tar){
        cout << i << " ";
    }
    cout << endl;
}

class Solution {
public:
    long long modual_num = pow(10, 9) + 7;
    long long multi_a_to_b(long long a, long long b){
        long long res=1;
        for(long long i=a;i<=b;i++){
            res *= i;
            res = res % modual_num;;
        }
        return res;
    }
    long long dvide_by_group(long long num, long long group){
        // (num + group - 1)! / num ! / (group - 1) !
        if(num < 0) return 0;
        return multi_a_to_b(num + 1, num + group - 1) / multi_a_to_b(1, group - 1);
    }
    int countHousePlacements(int n) {
        long long res = 0;
        for(long long i=0;i<=(n/2+1);i++){
            // put i houses
            // space with n - i
            // group n - i - (i - 1) to (i + 1) groups
            // cout << i << " " << dvide_by_group(n-i-i+1, i+1) << endl;
            res += dvide_by_group(n-i-i+1, i+1);
            res = res % modual_num;
        }
        return int(res*res % modual_num);
    }
};

int main(int argc, char const *argv[])
{   
    Solution solve;
    // vector<int> input{1, 2, 1, 2};
    int input = 1;
    cout << solve.countHousePlacements(input) << endl;
    return 0;
}