#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<sstream>

using namespace std;

class debug_Solution {
public:
    int min_solution_dp[20001] = {0};
    int min_solution_direction_dp[20001] = {0};
    string min_combine_dp[20001];
    int basic_solution(int target, int& direction, string& combine){
        if(min_solution_dp[target] != 0){
            direction = min_solution_direction_dp[target];
            combine = min_combine_dp[target];
            return min_solution_dp[target];
        }
        string instruct;
        int remain = target;
        int speed = 1;
        // if(target == 2){
        //     combine = "AARA";
        //     direction = -1;
        //     return 4;
        // }
        while(remain != 0){
            if(remain*speed < 0){
                instruct.push_back('R');
                speed *= -1;
                continue;
            }
            int acctimes = lround(log(abs(remain)+1)/log(2));
            for(int i=0;i<acctimes;i++){
                instruct.push_back('A');
            }
            // cout << "near log" << log(abs(remain)+1)/log(2) << endl;
            // cout << "go" << (pow(2, acctimes) - 1)*speed << endl; 
            int new_remain = remain - (pow(2, acctimes) - 1)*speed;
            if(remain*new_remain > 0){
                instruct.push_back('R');
                instruct.push_back('R');
                // cout << "not expected" << endl;
            }
            remain = new_remain;
            // cout << acctimes << endl;
            // cout << instruct << endl;
            // cout << remain << endl;
        }
        direction = speed;
        combine = instruct;

        // min_solution_direction_dp[target] = direction;
        // min_combine_dp[target] = combine;
        // min_solution_dp[target] = instruct.size();
        return instruct.size();
    }
    bool is2power(int number){
        int power = floor(log(number)/log(2));
        return (number == pow(2, power));
    }
    int min_solution(int target, int& direction, string& combine){
        if(min_solution_dp[target] != 0){
            direction = min_solution_direction_dp[target];
            combine = min_combine_dp[target];
            return min_solution_dp[target];
        }
        if(is2power(target+1)){
            combine.clear();
            return basic_solution(target, direction, combine);
        }
        string min_combineA;
        string min_combineB = "0";
        int min_step = basic_solution(target, direction, min_combineA);
        string tmp_A, tmp_B;
        for(int i=(target+1)/2;i<=target;i++){
            tmp_A.clear();
            tmp_B.clear();
            int dirA, dirB, stepA, stepB;
            if(i==target){
                // consider a special combination with negitave
                int upper2pow = pow(2, ceil(log(target+1)/log(2))) - 1;
//                 cout << "consider" << endl;
//                 cout << target - upper2pow << " " << upper2pow << endl;
                stepA = min_solution(upper2pow, dirA, tmp_A);
                stepB = min_solution(-(target-upper2pow), dirB, tmp_B);
                dirB *= -1;
                if(dirA == 1 && (stepA+1+stepB) < min_step){
                    min_step = stepA + 1 + stepB;
                    direction = dirB;
                    min_combineA = tmp_A;
                    min_combineA.append("+R");
                    min_combineB = tmp_B;
                }
                // else if(dirB == -1  && (stepA+2+stepB) < min_step){
                //     min_step = stepA + 2 + stepB;
                //     direction = -1 * dirB;
                //     min_combineA = tmp_A;
                //     min_combineA.append("+R");
                //     min_combineB = tmp_B;
                // }
                // don't consider step B first solution
            }
            else{
                // consider postive combination
                stepA = min_solution(i, dirA, tmp_A);
                stepB = min_solution(target-i, dirB, tmp_B);
                if((stepA + stepB + 1)>= min_step){
                    continue;
                }
                // may have smaller solution
                if(dirA == 1 && dirB == 1){
                    if(stepB + 2 + stepA >= min_step){
                        continue;
                    }
                    min_step = stepA + 2 + stepB;
                    direction = dirB;
                    min_combineA = tmp_A;
                    min_combineA.append("+RR");
                    min_combineB = tmp_B;
                }
                else if(dirA == -1 && (dirB == -1 || dirB == 1)){
                    min_step = stepA + 1 + stepB;
                    direction = dirB;
                    min_combineA = tmp_A;
                    min_combineA.append("+R");
                    min_combineB = tmp_B;
                }
                else if(dirB == -1 && dirA == 1){
                    min_step = stepA + 1 + stepB;
                    direction = dirA;
                    min_combineA = tmp_B;
                    min_combineA.append("+R");
                    min_combineB = tmp_A;
                }
                else{
                    cout << "not expect dirAB " << dirA << " " << dirB << endl;
                }
            }
        }
        if(min_combineB != "0"){
            combine.append(min_combineA);
            combine.append("+");
            combine.append(min_combineB);
        }
        else{
            combine = min_combineA;
        }
        // filled dp

        min_solution_direction_dp[target] = direction;
        min_combine_dp[target] = combine;
        min_solution_dp[target] = min_step;
        return min_step;
    }
    int racecar(int target) {
        int notused, ans, basic_ans;
        string combine;
        if(is2power(target+1)){
            ans = basic_solution(target, notused, combine);
        }
        else{
            ans = min_solution(target, notused, combine);
        }
        cout << combine << endl;
        
        return ans;
        
    }
};

class Solution {
public:
    int min_solution_dp[20001] = {0};
    int min_solution_direction_dp[20001] = {0};
    int basic_solution(int target, int& direction){
        if(min_solution_dp[target] != 0){
            direction = min_solution_direction_dp[target];
            return min_solution_dp[target];
        }
        int instruct_len = 0;
        int remain = target;
        int speed = 1;
        // if(target == 2){
        //     combine = "AARA";
        //     direction = -1;
        //     return 4;
        // }
        while(remain != 0){
            if(remain*speed < 0){
                instruct_len += 1;
                speed *= -1;
                continue;
            }
            int acctimes = lround(log2(abs(remain)+1));
            instruct_len += acctimes;
            // cout << "near log" << log(abs(remain)+1)/log(2) << endl;
            // cout << "go" << (pow(2, acctimes) - 1)*speed << endl; 
            int new_remain = remain - (pow(2, acctimes) - 1)*speed;
            if(remain*new_remain > 0){
                instruct_len += 2;
            }
            remain = new_remain;
            // cout << acctimes << endl;
            // cout << remain << endl;
        }
        direction = speed;
        return instruct_len;
    }
    bool is2power(int x){
        return (x & (x - 1)) == 0;
    }
    int min_solution(int target, int& direction){
        if(min_solution_dp[target] != 0){
            direction = min_solution_direction_dp[target];
            return min_solution_dp[target];
        }
        if(is2power(target+1)){
            return basic_solution(target, direction);
        }
        int min_step = basic_solution(target, direction);
        for(int i=(target+1)/2;i<=target;i++){
            int dirA, dirB, stepA, stepB;
            if(i==target){
                // consider a special combination with negitave
                int upper2pow = pow(2, ceil(log2(target+1))) - 1;
                // cout << "consider" << endl;
                // cout << target - upper2pow << " " << upper2pow << endl;
                stepA = min_solution(upper2pow, dirA);
                stepB = min_solution(-(target-upper2pow), dirB);
                dirB *= -1;
                if(dirA == 1 && (stepA+1+stepB) < min_step){
                    min_step = stepA + 1 + stepB;
                    direction = dirB;
                }
                // don't consider step B first solution
            }
            else{
                // consider postive combination
                stepA = min_solution(i, dirA);
                stepB = min_solution(target-i, dirB);
                if((stepA + stepB + 1)>= min_step){
                    continue;
                }
                // may have smaller solution
                if(dirA == 1 && dirB == 1){
                    if(stepB + 2 + stepA >= min_step){
                        continue;
                    }
                    min_step = stepA + 2 + stepB;
                    direction = dirB;
                }
                else if(dirA == -1 && (dirB == -1 || dirB == 1)){
                    min_step = stepA + 1 + stepB;
                    direction = dirB;
                }
                else if(dirB == -1 && dirA == 1){
                    min_step = stepA + 1 + stepB;
                    direction = dirA;
                }
                else{
                    cout << "not expect dirAB " << dirA << " " << dirB << endl;
                }
            }
        }
        // filled dp

        min_solution_direction_dp[target] = direction;
        min_solution_dp[target] = min_step;
        return min_step;
    }
    int racecar(int target) {
        int notused, ans;
        if(is2power(target+1)){
            ans = basic_solution(target, notused);
        }
        else{
            ans = min_solution(target, notused);
        }
        
        return ans;
        
    }
};

int main(int argc, char const *argv[])
{
    debug_Solution s;
    Solution sp;
    if(argc >= 2){
        int target = stoi(argv[1]);
        if(target == -1){
            cout << "check two version " << endl;
            for(int i=1;i<20;i++){
                if(s.racecar(i) == sp.racecar(i)){
                    cout << "same" << i << endl;
                }
                else{
                    cout << "wrong" << i << endl;
                    break;
                }
            }
        }
        // int tmp;
        // string tmpp;
        // int kk = s.basic_solution(5, tmp, tmpp);
        // cout << kk << endl;
        // cout << tmpp << endl;
        int ans = s.racecar(target);
        int count = 0;
        int pos = 0;
//         for(auto i:s.min_solution_dp){
//             cout << pos++ << " " << i << endl;
//             if(i==0){
//                 count += 1;
//             }
//             else{
//                 count = 0;
//             }
//             if(count > 3){
//                 break;
//             }
//         }
        cout << "ans " << ans << endl;
    }
    else{
        int target = 5;
        cout << "check" << target << endl;
        // int tmp;
        // string tmpp;
        // int kk = s.basic_solution(5, tmp, tmpp);
        // cout << kk << endl;
        // cout << tmpp << endl;
        int ans = s.racecar(target);
        cout << "ans " << ans << endl;
    }
    return 0;
}