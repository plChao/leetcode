#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;
void print_int_vec(vector<int> tar){
    for(auto i: tar){
        cout << i << " ";
    }
    cout << endl;
}
class Solution {
public:
    string longestDiverseString(int a, int b, int c){
        string res;
        res.reserve(a+b+c);
        vector<int> count{a, b, c};
        char dict[3] = {'a', 'b', 'c'};
        vector<int> continue_count{0, 0, 0};
        int maxindex = max_element(count.begin(), count.end()) - count.begin();
        while(count[0]+count[1]+count[2] > 0){
            int otherone = (maxindex + 1) % 3;
            int othertwo = (maxindex + 2) % 3;
            if(continue_count[maxindex] == 2){
                if(count[otherone] == 0 && count[othertwo] == 0){
                    break;
                }
                if(count[otherone] > count[othertwo]){
                    maxindex = otherone;
                }
                else{
                    maxindex = othertwo;
                }
                otherone = (maxindex + 1) % 3;
                othertwo = (maxindex + 2) % 3;
            }

            res.push_back(dict[maxindex]);
            count[maxindex]--;
            continue_count[maxindex]++;
            continue_count[otherone] = 0;
            continue_count[othertwo] = 0;
            maxindex = max_element(count.begin(), count.end()) - count.begin();
            // print_int_vec(continue_count);   
        }
        return res;
    }
};
int main(){
    Solution solve;
    string ans;
    ans = solve.longestDiverseString(1, 1, 7);
    cout << ans << endl;
    return 0;
}