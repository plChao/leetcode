#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;
class Solution {
public:
    bool isOneEditDistance(string l, string short_str) {
        if(short_str.size() > l.size()){
            return isOneEditDistance(short_str, l);
        }
        if(l.size() - short_str.size() > 1){
            return false;
        }
        
        if(l.size() == short_str.size()){
            if(l == short_str){
                return false;
            }
            for(int i=0;i<l.size();i++){
                if(l[i] != short_str[i]){
                    l.erase(l.begin() + i);
                    short_str.erase(short_str.begin() + i);
                    break;
                }
            }
        }
        else{
            for(int i=0;i<l.size();i++){
                if(i == l.size()-1){
                    l.erase(l.begin() + i);
                }
                else if(l[i] != short_str[i]){
                    l.erase(l.begin() + i);
                    break;
                }
            }   
        }
        // cout << l << " " << short_str << endl;
        if(l == short_str){
            return true;
        }
        else{
            return false;
        }
        
    }
};
int main(int argc, char const *argv[])
{   
    Solution sol;
    bool ans = sol.isOneEditDistance("ab", "acb");
    cout << ans << endl;
    return 0;
}
