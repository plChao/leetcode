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
#include<unordered_map>
using namespace std;

void print_int_vec(vector<int> tar){
    for(auto i: tar){
        cout << i << " ";
    }
    cout << endl;
}
class DSU{
    // disjont set union
    private:
        vector<int> root;
        vector<int> rank;
    public:
        DSU(int set_size){
            for(int i=0;i<set_size;i++){
                root.push_back(i);
                rank.push_back(1);
            }
        }
        int find_root(int a){
            if(root[a] == a){
                return a;
            }
            else{
                return find_root(root[a]);
            }
        }
        void setUnion(int x, int y) {
            int rootX = find_root(x);
            int rootY = find_root(y);
            if (rootX != rootY) {
                if (rank[rootX] >= rank[rootY]) {
                    root[rootY] = rootX;
                    rank[rootX] += rank[rootY];
                } else {
                    root[rootX] = rootY;
                    rank[rootY] += rank[rootX];
                }
            }
        }
    
};
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        DSU set_union_record(s.size());
        for(auto pair: pairs){
            set_union_record.setUnion(pair[0], pair[1]);
        }
        unordered_map<int, vector<int>> set_record;
        for(int vertics=0;vertics<s.size();vertics++){
            int root = set_union_record.find_root(vertics);
            set_record[root].push_back(vertics);
        }
        string smalleststring(s.size(), ' ');
        for(auto pos_set : set_record){
            string tmp;
            for(int component: pos_set.second){
                tmp.push_back(s[component]);
            }
            sort(tmp.begin(), tmp.end());
            for(int i=0;i<tmp.size();i++){
                smalleststring[pos_set.second[i]] = tmp[i];
            }
        }
        return smalleststring;
    }
};

int main(int argc, char const *argv[])
{   
    Solution solve;
    string s_in = "cbad";
    vector<int> input{1, 2};
    vector<vector<int>> pair_in{input};
    cout << solve.smallestStringWithSwaps(s_in, pair_in) << endl;
    return 0;
}