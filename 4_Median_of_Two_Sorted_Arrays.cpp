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
    // cutsize: (n1 + n2) // 2 = 5
    // nums1 : 1, 2, 3 || 4, 5 ,6
    //                    ^ cutfor1 (3)
    // nums1 : 1, 2 || 3, 4, 5
    //                 ^ cutfor2 (2)

    bool cutright(vector<int>& nums1, vector<int>& nums2, int cutfor1, int cutsize){
        int cutfor2 = cutsize - cutfor1;
        int n1 = nums1.size(), n2 = nums2.size();
        int l1, l2, r1, r2;
        l1 = (cutfor1 == 0? INT_MIN: nums1[cutfor1-1]);
        l2 = (cutfor2 == 0? INT_MIN: nums2[cutfor2-1]);
        r1 = (cutfor1 >= n1? INT_MAX: nums1[cutfor1]);
        r2 = (cutfor2 >= n2? INT_MAX: nums2[cutfor2]); 
        if(l2 < r1){
            return true;
        }
        else{
            return false;
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int cutsize = (n1 + n2) / 2;

        if(n1 > n2){
            return findMedianSortedArrays(nums2, nums1);
        }
        // n1 < n2
        if(n1 == 0){
            return (nums2[int((n2 - 1) / 2)] + nums2[n2 / 2]) / 2.0;
        }

        for(int i=0;i<n1;i++){
            cout << cutright(nums1, nums2, i, cutsize) << " ";
        }
        cout << endl;
        
        int l = 0, r = n2 - 1;
        while (l <= r)
        {
            int mid = (l+r) / 2;
            if(cutright(nums1, nums2, mid, cutsize)){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        int cutfor1 = l;
        int cutfor2 = cutsize - cutfor1;
        int l1, l2, r1, r2;
        
        l1 = (cutfor1 == 0? INT_MIN: nums1[cutfor1-1]);
        l2 = (cutfor2 == 0? INT_MIN: nums2[cutfor2-1]);
        r1 = (cutfor1 >= n1? INT_MAX: nums1[cutfor1]);
        r2 = (cutfor2 >= n2? INT_MAX: nums2[cutfor2]); 

        // if(l1 < r2 && l2 < r1){
        //     cout << "pass" << endl;
        // }
        // else{
        //     cout << l << endl;
        // }
        if((n1+n2) % 2 == 0){
            return (max(l1, l2) + min(r1, r2)) / 2.0;
        }
        else{
            return min(r1, r2);
        }
    }
};
int main(int argc, char const *argv[])
{   
    Solution solve;
    vector<int> inputa{1, 3, 4, 5};
    vector<int> inputb{2, 4};
    cout << solve.findMedianSortedArrays(inputa, inputb) << endl;
    return 0;
}