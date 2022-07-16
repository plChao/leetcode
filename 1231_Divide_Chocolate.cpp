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
bool cmp_abc(int a, int b){
    return true;
}
class Solution {
public:
    bool can_get_the_chocolate(vector<int>& sweetness, int k, int tar_sweet){
        int index = 0;
        k += 1;
        while(k--){
            int sweet_sum = 0;
            while(sweet_sum < tar_sweet){
                if(index > sweetness.size()){
                    return false;
                }
                sweet_sum += sweetness[index];
                index += 1;
            }
            // cout << k << " " << sweet_sum << " " << index << endl;
        }
        return true;
    }
    int maximizeSweetness(vector<int>& sweetness, int k) {
        int min_value = sweetness[0];
        int max_value = 0;
        for(int sweet : sweetness){
            min_value = min(min_value, sweet);
            max_value += sweet;
        }
        max_value = max_value / (k+1);
        vector<int> tmp;
        int l=min_value, r=max_value, mid;
        while(l <= r){
            mid = l + (r - l) / 2;
            if(can_get_the_chocolate(sweetness, k, mid)){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return l - 1;

    }
};

int main(int argc, char const *argv[])
{   
    Solution solve;
    vector<int> input{5,6,7,8,9,1,2,3,4};
    // print_int_vec(solve.maximizeSweetness(input, 3));
    // solve.can_get_the_chocolate(input, 5, 8);
    cout << solve.maximizeSweetness(input, 8) << endl;
    return 0;
}