#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<unordered_map>

using namespace std;
void print_int_vec(vector<string> tar){
    for(auto i: tar){
        cout << i << " ";
    }
    cout << endl;
}
class Solution {
    public:
        unordered_map<string, bool> all_set;
        bool differByOne(vector<string>& dict) {
            if(dict.size() <= 1 || dict[0].size() == 0){
                return false;
            }
            int str_len = dict[0].size();
            for(int i=0;i<dict.size();i++){
                for(int j=0;j<str_len;j++){
                    string tmp = string(dict[i]);
                    tmp[j] = '_';
                    if(all_set.find(tmp) != all_set.end()){
                        return true;
                    }
                    else{
                        all_set[tmp] = true;
                    }
                }
            }
            return false;
        }
};
int main(int argc, char const *argv[])
{   
    // vector<string> input = {"abcd", "acbd", "aacd"};
    vector<string> input = {"cecabdbae","cecaaacaf","cecaccafe","cecabcade","cecaefbbf","cecafeacd","cecafdaea","cecafebad"};
    Solution s = Solution();
    auto out = s.differByOne(input);
    cout << out << endl;
    return 0;
}