#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<cmath>

using namespace std;
void print_int_vec(vector<string> tar){
    for(auto i: tar){
        cout << i << " ";
    }
    cout << endl;
}
class Solution {
    public:
        int rolling_hash_string_to_int(string input, int setmod, int setX){
            int value = 0;
            int base = 1;
            for(int i=0;i<input.size();i++){
                value += (input[i] - 'a') * base;
                base *= setX;
                base %= setmod;
                value %= setmod;
            }
            return value;
        }
        unordered_map<int, vector<int>> all_set;
        int MODE = 1000007;
        int SETX = 26;
        int power_mode(int setx, int j, int mode){
            int base = 1;
            while(j--){
                base *= setx;
                base %= mode;
            }
            return base;
        }
        int ignore_j_postion_hash_value(string input, int original_hash, int j){
            return (MODE + int(original_hash - (input[j] - 'a') * power_mode(SETX, j, MODE) % MODE)) % MODE;
        }
        bool differByOne(vector<string>& dict) {
            if(dict.size() <= 1 || dict[0].size() == 0){
                return false;
            }
            int n = dict.size();
            int str_len = dict[0].size();
            int r_hash[n];
            for(int i=0;i<dict.size();i++){
                r_hash[i] = rolling_hash_string_to_int(dict[i], MODE, SETX);
            }
            for(int i=0;i<dict.size();i++){
                for(int j=0;j<str_len;j++){
                    int h = ignore_j_postion_hash_value(dict[i], r_hash[i], j);
                    auto it = all_set.find(h);
                    if(it != all_set.end()){
                        // return true;
                        string tmp = dict[i];
                        tmp[j] = '_';
                        for(auto ele:it->second){
                            // cout << i << " " << ele << " " << j << endl;
                            string tmp2 = dict[ele];
                            tmp2[j] = '_';
                            if( i != ele && tmp.compare(tmp2) == 0){
                                cout << i << " " << ele << " " << j << endl;
                                return true;
                            }
                        }
                    }
                    else{
                        all_set[h].push_back(i);
                    }
                }
            }
            return false;
        }
};
int main(int argc, char const *argv[])
{   
    // vector<string> input = {"abcd", "acbd", "aacd"};
    // vector<string> input = {"cecabdbae","cecaaacaf","cecaccafe","cecabcade","cecaefbbf","cecafeacd","cecafdaea","cecafebad"};
    // vector<string> input = {"cccadd","ccccdb","bbbbb","cccdcb","cccaad"};
    vector<string> input = {"cccadd","cccaad"};
    Solution s = Solution();
    auto out = s.differByOne(input);
    cout << out << endl;
    return 0;
}