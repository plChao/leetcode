#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>

using namespace std;
void print_int_vec(vector<int> tar){
    for(auto i: tar){
        cout << i << " ";
    }
    cout << endl;
}


vector<vector<int>> combination(vector<int> all, vector<int> element)
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

        for (int i = 0; i <= element.size(); i++)
        {
            // pop out the elements[i] from all
            vector<int> tmp = all;
            auto ptr = lower_bound(tmp.begin(), tmp.end(), element[i]);
            if (*ptr == element[i])
            {
                tmp.erase(ptr);
                subresult = combination(tmp, element);
            }
            for (auto ele : subresult)
            {
                ele.push_back(element[i]);
                res.push_back(ele);
            }
            subresult.clear();
        }
        return res;
    }
}

int main(int argc, char const *argv[])
{   
    vector<int> input = {1, 2, 2, 4}; 
    vector<int> elements = {1, 2, 4};
    vector<vector<int>> comb = combination(input, elements);
    cout << comb.size() << endl;
    for(auto i:comb){
        print_int_vec(i);
    }
    return 0;   
}
