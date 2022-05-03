#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool matching(string &s, string &p, int i, int j, int ** memo){
        // cout << i << " " << j << endl;
        if(i == s.size() && p[j] == '*'){
            // return true;
            return matching(s, p, i, j+1, memo);
        }
        if(memo[i][j] != 0){
            return memo[i][j] == -1?false:true;
        }
        if(p[j] == '*'){
            bool star_match = matching(s, p, i, j+1, memo) || matching(s, p, i+1, j, memo);
            if(star_match){
                memo[i][j] = 1;
                return true;
            }
        }
        bool first_match = (p[j] == s[i]) or (p[j] == '?');
        if(first_match && matching(s, p, i+1, j+1, memo)){
            memo[i][j] = 1;
            return true;
        }
        memo[i][j] = -1;
        return false;
    }
    bool isMatch(string s, string p) {
        int **memo = new int*[s.size()+1];
        for(int i = 0; i <= s.size(); i++) {
            memo[i] = new int[p.size()+1];
        }
        for(auto i=0;i<s.size();i++){
            memset(memo[i], 0, sizeof(int)*p.size());
            memo[i][p.size()] = -1;
        }
        memset(memo[s.size()], -1, sizeof(int)*p.size());
        memo[s.size()][p.size()] = 1;
        // for(int i=0;i<s.size();i++){
        //     for(int j=0;j<p.size();j++){
        //         cout << memo[i][j] << endl;
        //     }
        // }
        return matching(s, p, 0, 0, memo);
    }
};
int main(int argc, char const *argv[])
{   
    Solution s = Solution();
    cout << s.isMatch("baccd", "b*c") << endl;
    return 0;
}