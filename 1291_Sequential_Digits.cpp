#include<iostream>
#include<vector>

using namespace std;
vector<int> sequential_numbers(int digitslen){
    vector<int> candidate_list;
    // if(digitslen > 9){
    //     return candidate_list;
    // }
    int candidate=0;
    int increase=0;
    for(int i=1;i<=digitslen;i++){
        candidate = candidate*10 + i;
        increase = increase*10 + 1;
    }
    while(candidate % 10 != 0){
        candidate_list.push_back(candidate);
        candidate += increase;
    }
    return candidate_list;
}
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> answer;
        int low_digit = to_string(low).size();
        // int high_digit = min(9, to_string(high).size());
        int high_digit = to_string(high).size();
        for(int i=low_digit;i<=high_digit;i++){
            vector<int> cadidate_list = sequential_numbers(i);
            if(i==low_digit || i==high_digit){
                for(int j=0;j<cadidate_list.size();j++){
                    if(cadidate_list[j]<low || cadidate_list[j]>high){
                        cadidate_list.erase(cadidate_list.begin()+j);
                        j--;
                    }
                }
            }
            answer.insert(answer.end(), cadidate_list.begin(), cadidate_list.end());
            // cadidate_list.clear();
        }
        return answer;
    }
};
int main(){
    Solution solve;
    vector<int> vec;
    vec = solve.sequentialDigits(1000, 13000);
    for(auto i: vec){
        cout << i << " ";
    }
}