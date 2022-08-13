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

void print_str_vec(vector<string> tar){
    for(auto i: tar){
        cout << i << "\"" << endl;
    }
}

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int cur_width = 0;
        int i = 0;
        int line_start_i = 0, line_end_i;
        vector<string> res;
        while(i != words.size()){
            // ignore the first space
            cur_width = -1;
            while( i < words.size() && cur_width + words[i].length() + 1 <= maxWidth){
                cur_width += words[i].length() + 1;
                i += 1;
            }
            line_end_i = i;
            string justify_str;
            justify_str.reserve(maxWidth);
            int left_space = maxWidth - cur_width;
            int end_space = 0;
            int avg_space = 1;
            if(i == words.size()){
                // last line
                end_space = left_space;
            } 
            else{
                int add_avg_space = 0;
                if(line_end_i - line_start_i - 1 != 0){
                    add_avg_space += left_space / (line_end_i - line_start_i - 1);
                }
                end_space = left_space - add_avg_space * (line_end_i - line_start_i - 1);
                avg_space += add_avg_space;
            }
            string gap(avg_space, ' ');
            for(int j=line_start_i;j<line_end_i - 1;j++){
                justify_str += (words[j] + gap);
                if(i != words.size() && end_space > 0){
                    justify_str += ' ';
                    end_space -= 1;
                }
            }
            justify_str += (words[line_end_i - 1]);
            if(i == words.size() || end_space > 0){
                string end_gap(end_space, ' ');
                justify_str += end_gap;
            }
            res.push_back(justify_str);
            line_start_i = line_end_i;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{   
    Solution solve;
    vector<string> input{"What","must","be","acknowledgment","shall","be"};
    print_str_vec(solve.fullJustify(input, 16));
    return 0;
}