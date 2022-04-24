#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<sstream>
#include<algorithm>
#include<assert.h>
using namespace std;

void print_int_vec(vector<int> tar){
    for(auto i: tar){
        cout << i << " ";
    }
    cout << endl;
}
class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<int> res;
        vector<vector<int>> bucket_rectangles(102);

        // bucket the rectangles
        for(auto ele: rectangles){
            bucket_rectangles[ele[1]].push_back(ele[0]);
        }
        // sort all the rectangles in each bucket
        for(int i=0;i<bucket_rectangles.size();i++){
            sort(bucket_rectangles[i].begin(), bucket_rectangles[i].end());
        }
        int ans = 0;
        for(int i=0;i<points.size();i++){
            for(int j=points[i][1];j<=100;j++){
                auto at_least = lower_bound(bucket_rectangles[j].begin(), bucket_rectangles[j].end(), points[i][0]);
                ans += (bucket_rectangles[j].end() - at_least);
            }
            res.push_back(ans);
            ans = 0;
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> rectangles = {{1,1},{2,2},{3,3}};
    vector<vector<int>> points = {{1,3},{1,1}};
    print_int_vec(s.countRectangles(rectangles, points));
    return 0;
}