#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

vector<vector<int>> combination(vector<int> all, int Weight_num)
{
    // get all the combination of vector all elements
    vector<vector<int>> res;
    vector<vector<int>> subresult;
    if (all.size() == 1)
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
            if (ptr != tmp.end())
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
void dfs_count(vector<int> weight_stack, int ** Array, int exersize_index, int current_step, int Exersizenum, int Weightnum)
{
    if (Exersizenum - 1 == exersize_index)
    {
        // sum the Array[0][:] to step
        for (int i = 0; i < Weightnum; i++)
        {
            current_step += Array[exersize_index][i];
        }
        if (current_step < Minstep)
        {
            Minstep = current_step;
        }
        return;
    }
    else if (current_step > Minstep)
    {
        // puring
        return;
    }
    else
    {
        int diff_weight[Weightnum] = {0};
        for (int i = 0; i < Weightnum; i++)
        {
            diff_weight[i] = Array[exersize_index + 1][i] - Array[exersize_index][i];
        }
        while (Exceeed(diff_weight, Weightnum))
        {
            diff_weight[weight_stack.back()] += 1;
            weight_stack.pop_back();
            current_step += 1;
        }
        vector<vector<int>> possible_combine;
        vector<int> elements_needed;
        for (int i = 0; i < Weightnum; i++)
        {
            for (int j = 0; j < diff_weight[i]; j++)
            {
                elements_needed.push_back(i+1);
            }
        }
        // diff weight
        possible_combine = combination(elements_needed, Weightnum);
        current_step += elements_needed.size();
        for(auto ele : possible_combine)
        {
            weight_stack.insert(weight_stack.end(), ele.begin(), ele.end());
            dfs_count(weight_stack, Array, exersize_index + 1, current_step, Exersizenum, Weightnum);
        }
        return;
    }
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
        for (int i = 1; i < Excerise; i++)
        {
            for (int j = 0; j < Weight; j++)
            {
                cin >> Array[i][j];
            }
        }
        // dfs
        vector<int> weight_stack;
        dfs_count(weight_stack, Array, 0, 0, Excerise, Weight);
        cout << Minstep << endl;
    }
    return 0;
}