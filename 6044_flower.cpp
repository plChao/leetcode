#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<sstream>
#include<algorithm>
#include<queue>

using namespace std;
void print_int_vec(vector<int> tar){
    for(auto i: tar){
        cout << i << " ";
    }
    cout << endl;
}

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        vector<int> res;
        // sort flowers by start time
        sort(flowers.begin(), flowers.end());
        // loop all the flowers and generate (time, flowers_num) if flowers_num change
        priority_queue<int, vector<int>, greater<int>> pq;
        int flowers_num = 0;
        vector<vector<int>> change_of_flowers;
        change_of_flowers.push_back({0, 0});
        for(int i=0;i<flowers.size();i++){
            // cout << "flowers ";
            // print_int_vec(flowers[i]);
            while (pq.size() > 0 && pq.top() < flowers[i][0])
            {
                flowers_num -= 1;
                vector<int> tmp = {pq.top()+1, flowers_num};
                change_of_flowers.push_back(tmp);
                pq.pop();
            }
            flowers_num += 1;
            pq.push(flowers[i][1]);
            change_of_flowers.push_back({flowers[i][0], flowers_num});
        }
        while(pq.size() > 0){
            flowers_num -= 1;
            vector<int> tmp = {pq.top()+1, flowers_num};
            change_of_flowers.push_back(tmp);
            pq.pop();
        }
        // for(auto ele:change_of_flowers){
        //     cout << ele[0] << " " << ele[1] << endl;
        // }
        // cout << "end of change of flowers" << endl;
        // find the lower_bound of person time
        for(int person_time: persons){
            vector<int> tmp = {person_time, INT_MAX};
            auto it = upper_bound(change_of_flowers.begin(), change_of_flowers.end(), tmp);
            if(it != change_of_flowers.end()){
                // cout << it->at(0) << " " << it->at(1) << " it--" << endl;
                it --;
                // cout << it->at(0) << " " << it->at(1) << endl;
                res.push_back(it->at(1));
            }
            else{
                cout << 0 << endl;
                res.push_back(0);
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> flowers = {{1,6},{3,7},{9,12},{4,13}};
    vector<int> person = {2, 3, 7, 11};

    // vector<vector<int>> flowers = {{1,1},{2,2},{2,2},{2,3}};
    // vector<int> person = {1, 2, 3, 4};

    // vector<vector<int>> flowers = {{28,37},{23,33},{39,39},{49,50},{41,45},{14,47}};
    // vector<int> person = {19,44,28,41,40,12,48,17,34,30};
    print_int_vec(s.fullBloomFlowers(flowers, person));
    return 0;
}