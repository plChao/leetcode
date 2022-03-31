#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;
void print_int_vec(vector<string> tar){
    for(auto i: tar){
        cout << i << " ";
    }
    cout << endl;
}
class Solution {
public:
    bool differByOne(vector<string>& dict) {
        if(dict.size() <= 1 || dict[0].size() == 0){
            return false;
        }
        if(dict[0].size() == 1 && dict.size() > 1){
            // only one position different
            return true;
        }
        int str_len = dict[0].size();
        vector<string> table[str_len][30];
        for(int i=0;i<dict.size();i++){
            for(int j=0;j<str_len;j++){
                string tmp = string(dict[i]);
                int char_index = tmp[j] - 'a';
                tmp.erase(tmp.begin()+j);
                table[j][char_index].push_back(tmp);
            }
        }
        bool result = false;
        for(int i=0;i<str_len;i++){
            for(int j=0;j<26;j++){
                result = result || differByOne(table[i][j]);
                // if(table[i][j].size() > 0){
                //     print_int_vec(table[i][j]);
                //     cout << result << endl;
                // }
            }
        }
        return result;
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