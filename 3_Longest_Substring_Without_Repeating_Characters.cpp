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
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int left = 0, right = 0;
        int appear[128];
        memset(appear, -1, 128*sizeof(int));
        while(right < s.size()){
            char cur_char = s[right];
            if(appear[cur_char] == -1){
                appear[cur_char] = right;
            }
            else{
                res = max(res, right - left);
                for(int i=left;i<appear[cur_char];i++){
                    appear[s[i]] = -1;
                }
                left = appear[cur_char] + 1;
                appear[cur_char] = right;
            }
            right += 1;
        }
        res = max(res, right - left);
        return res;
    }
};

int main(int argc, char const *argv[])
{   
    Solution solve;
    // vector<int> input{1, 2, 1, 2};
    string input;
    // input = "abcabc";
    // input = "bbbbb";
    input = " ";
    cout << solve.lengthOfLongestSubstring(input) << endl;
    return 0;
}