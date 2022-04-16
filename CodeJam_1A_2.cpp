#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;
void print_int_vec(vector<int> tar){
    for(auto i: tar){
        cout << i << " ";
    }
    cout << endl;
}
vector<vector<int>> combination(vector<int> all, int Weight_num)
{
    // get all the combination of vector all elements
    vector<vector<int>> res;
    vector<vector<int>> subresult;
    if (all.size() <= 1)
    {
        res.push_back(all);
        return res;
    }
    else
    {

        for (int i = 1; i <= Weight_num; i++)
        {
            // pop out the elements[i] from all
            vector<int> tmp = all;
            auto ptr = lower_bound(tmp.begin(), tmp.end(), i);
            if (*ptr == i)
            {
                tmp.erase(ptr);
                subresult = combination(tmp, Weight_num);
            }
            for (auto ele : subresult)
            {
                ele.push_back(i);
                res.push_back(ele);
            }
            subresult.clear();
        }
        return res;
    }
}
bool Exceeed(int *arr, int len)
{
    // check if the array contain negative number
    for (int i = 0; i < len; i++)
    {
        if (arr[i] < 0)
        {
            return true;
        }
    }
    return false;
}
// depth first search for combination change
int Minstep = INT_MAX;
int Count_possible = 0;
int step_between_stack(vector<int> a, vector<int> b){
    int same = 0;
    int min_index = min(a.size(), b.size());
    for(same = 0; same < min_index; same++){
        if(a[same] != b[same]){
            break;
        }
    }
    return a.size() + b.size() - 2*same;

}
void dfs_count(vector<int> weight_stack, int ** Array, int exersize_index, int current_step, int Exersizenum, int Weightnum)
{
    // cout << "stack of " << exersize_index << " " << current_step << endl;
    // print_int_vec(weight_stack);
    if (current_step > Minstep)
    {
        // puring
        // cout << "puring" << current_step << endl;
        Count_possible += 1;
        return;
    }
    if (Exersizenum == exersize_index)
    {
        // sum the Array[0][:] to step
        if (current_step < Minstep)
        {
            Minstep = current_step;
        }
        Count_possible += 1;
        return;
    }
    // else if(exersize_index == Exersizenum-1){
    //     int diff_weight[Weightnum+1] = {0};
    //     for (int i = 0; i < Weightnum; i++)
    //     {
    //         diff_weight[i] = Array[exersize_index + 1][i] - Array[exersize_index][i];
    //     }
    //     while (Exceeed(diff_weight, Weightnum))
    //     {
    //         // print int array diff_weight

    //         // for(int i=0;i<=Weightnum;i++){
    //         //     cout << diff_weight[i] << " ";
    //         // }
    //         // cout << endl;

    //         if(weight_stack.size() == 0){
    //             // cout << "Error: empty stack" << endl;
    //             break;
    //         }

    //         diff_weight[weight_stack.back()] += 1;
    //         weight_stack.pop_back();
    //         current_step += 1;
    //     }
    //     vector<int> elements_needed;
    //     for (int i = 0; i < Weightnum; i++)
    //     {
    //         for (int j = 0; j < diff_weight[i]; j++)
    //         {
    //             elements_needed.push_back(i+1);
    //         }
    //     }
    //     current_step += elements_needed.size();
    //     weight_stack.insert(weight_stack.end(), elements_needed.begin(), elements_needed.end());
    //     dfs_count(weight_stack, Array, exersize_index + 1, current_step, Exersizenum, Weightnum);
    //     return;
    // }
    else
    {
        vector<vector<int>> possible_combine;
        vector<int> elements_needed;
        for (int i = 0; i < Weightnum; i++)
        {
            for (int j = 0; j < Array[exersize_index+1][i]; j++)
            {
                elements_needed.push_back(i+1);
            }
        }
        // diff weight
        possible_combine = combination(elements_needed, Weightnum);
        for(auto ele : possible_combine)
        {
            // cout << "ori ";
            // print_int_vec(weight_stack);
            // cout << "tar ";
            // print_int_vec(ele);

            int steps = step_between_stack(weight_stack, ele);
            vector<int> tmp = ele;
            dfs_count(tmp, Array, exersize_index + 1, current_step + steps, Exersizenum, Weightnum);
        }
        return;
    }
}
void test(){
    vector<vector<int>> possible_combine;
    vector<int> tt{1, 1, 2, 2, 3, 3, 3};
    possible_combine = combination(tt, 3);
    for(auto ele:possible_combine){
        print_int_vec(ele);
    }
    return;
}

int main(int argc, char const *argv[])
{
    int num_case;
    cin >> num_case;
    for (int cc = 1; cc <= num_case; cc++)
    {
        cout << "Case #" << cc << ": ";
        int Excerise, Weight;
        cin >> Excerise >> Weight;
        int **Array = new int*[Excerise+1];
        for (int i = 0; i <= Excerise; i++)
        {
            Array[i] = new int[Weight];
        }
        
        for(int j = 0; j < Weight; j++)
        {
            Array[0][j] = 0;
        }
        // input array
        for (int i = 1; i <= Excerise; i++)
        {
            for (int j = 0; j < Weight; j++)
            {
                cin >> Array[i][j];
            }
        }
        int current_step = 0;
        for (int j = 0; j < Weight; j++)
        {
            int min_val = INT_MAX;
            for(int i=1; i<=Excerise; i++){
                if(Array[i][j] < min_val){
                    min_val = Array[i][j];
                }
            }
            for(int i=1; i<=Excerise; i++){
                Array[i][j] -= min_val;
            }
            current_step += 2*min_val;
        }
        // dfs
        for (int i = 0; i < Weight; i++)
        {
            current_step += Array[Excerise][i];
        }
        vector<int> weight_stack;
        dfs_count(weight_stack, Array, 0, current_step, Excerise, Weight);
        cout << Minstep << endl;
        Minstep = INT_MAX;
    }
    return 0;
}