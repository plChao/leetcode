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
#include<cmath> 
using namespace std;

void print_int_vec(vector<int> tar){
    for(auto i: tar){
        cout << i << " ";
    }
    cout << endl;
}

class Solution {
public:
    long long modual_num = pow(10, 9) + 7;
    int countHousePlacements(int n) {
        long long first_space_placement = 1;
        long long first_house_placement = 1;
        long long total_placement = first_house_placement + first_space_placement;
        for(int i=2;i<=n;i++){
            first_house_placement = first_space_placement;
            // first_space_placement = first_house_placement + first_space_placement;
            first_space_placement = total_placement;
            total_placement = (first_house_placement + first_space_placement) % modual_num;
        }
        return total_placement * total_placement % modual_num;
    }
};

int main(int argc, char const *argv[])
{   
    Solution solve;
    // vector<int> input{1, 2, 1, 2};
    int input = 2;
    cout << solve.countHousePlacements(input) << endl;
    return 0;
}