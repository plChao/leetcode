#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        string l, short_str;
        if(s.size() > t.size()){
            if(s.size() - t.size() > 1){
                return false;
            }
            l = s;
            short_str = t;
        }
        else{
            if(t.size() - s.size() > 1){
                return false;
            }
            l = t;
            short_str = s;
        }
        
        if(l.size() == short_str.size()){
            if(l == short_str){
                cout << "return here" << endl;
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
        cout << l << " " << short_str << endl;
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
