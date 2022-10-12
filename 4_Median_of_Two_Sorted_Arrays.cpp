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
    pair<int, int> findithelement(vector<int>& nums1, vector<int>& nums2, int i){
        nums1.push_back(INT_MAX);
        nums2.push_back(INT_MAX);
        auto ptr1 = nums1.begin();
        auto ptr2 = nums2.begin();
        int before_ith_element = *ptr1;
        cout << "i " << i << endl;
        int cnt = 0;
        while(cnt < i){
            if(*ptr1 < *ptr2){
                cnt++;
                if(cnt == i){
                    before_ith_element = *ptr1;
                }
                ptr1++;
            }
            else{
                cnt++;
                if(cnt == i){
                    before_ith_element = *ptr2; 
                }
                ptr2++;
            }
        }
        if(*ptr1 < *ptr2){
            // nums1.pop_back();
            // nums2.pop_back();
            return make_pair(before_ith_element, *ptr1);
        }
        else{
            // nums1.pop_back();
            // nums2.pop_back();
            return make_pair(before_ith_element, *ptr2); 
        }

    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() < nums2.size()){
            return findMedianSortedArrays(nums2, nums1);
        }
        if(nums2.size() == 0){
            int length = nums1.size();
            return (nums1[int((length - 1) / 2)] + nums1[length/2]) / 2.0;
        }
        pair<int, int> middle_element;
        int sizesum = nums1.size() + nums2.size();
        if(sizesum % 2 == 0){
            middle_element = findithelement(nums1, nums2, sizesum / 2);
            // cout << "mid " << middle_element.first << " " << middle_element.second << endl;
            return (middle_element.first + middle_element.second) / 2.0;
        }
        else{
            middle_element = findithelement(nums1, nums2, (sizesum + 1) / 2);
            // cout << "mid " << middle_element.first << endl;
            return middle_element.first;
        }
    }
};
int main(int argc, char const *argv[])
{   
    Solution solve;
    vector<int> inputa{1, 3, 4, 5};
    vector<int> inputb{2};
    cout << solve.findMedianSortedArrays(inputa, inputb) << endl;
    return 0;
}