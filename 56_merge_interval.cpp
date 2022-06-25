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
    static bool end_cmp(vector<int> a, vector<int> b){
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int curstart = -1;
        int curend = -1;
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), end_cmp);
        for(int i=0;i<intervals.size();i++){
            vector<int> cur_inval = intervals[i];
            if(curstart == -1){
                // first start
                curstart = cur_inval[0];
                curend = cur_inval[1];
            }
            else if(curend >= cur_inval[0]){
                // merge
                curend = max(curend, cur_inval[1]);
            }
            else if(curend < cur_inval[0]){
                // next inval
                vector<int> inval{curstart, curend};
                res.push_back(inval);
                // push the pre interval to res
                // start the next merge
                curstart = cur_inval[0];
                curend = cur_inval[1];
            }
            
        }
        vector<int> inval{curstart, curend};
        res.push_back(inval);
        return res;
    }
};

int main(int argc, char const *argv[])
{   
    Solution solve;
    // vector<int> input{{1, 4}, {2, 3}};
    // auto res = solve.merge(input);

    // print_int_vec(solve.merge(input));
    return 0;
}