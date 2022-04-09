#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<cmath>

using namespace std;

vector<vector<int>> combination(vector<int> all, vector<int> elements){
    // get all the combination of vector all elements
    vector<vector<int>> res;
    vector<vector<int>> subresult;
    if(all.size() == 1){
        res.push_back(all);
        return res;
    }
    else{
        
        for(int i=0;i<elements.size();i++){
            // pop out the elements[i] from all
            vector<int> tmp = all;
            auto ptr = lower_bound(tmp.begin(), tmp.end(), elements[i]);
            if(ptr != tmp.end()){
                tmp.erase(ptr);
                subresult = combination(tmp, elements);
            }
            for(auto ele:subresult){
                ele.push_back(elements[i]);
                res.push_back(ele);
            }
            subresult.clear();
        }
        return res;
    }

}

int main(int argc, char const *argv[])
{   
    int num_case;
    cin >> num_case;
    for(int cc=1;cc<=num_case;cc++){
        cout << "Case #" << cc << ": ";
        int Excerise, Weight;
        cin >> Excerise >> Weight;
        int Array[Excerise][Weight];
        //input array
        for(int i=0;i<Excerise;i++){
            for(int j=0;j<Weight;j++){
                cin >> Array[i][j];
            }
        }
        int step = 0;
        // sum the difference of each row
        // depth first search the 
        for(int i=0;i<Excerise;i++){
            if(i == 0 || i == Excerise - 1){
                for(int j=0;j<Weight;j++){
                    step += Array[i][j];
                }
            }
            if(i != 0){
                for(int j=0;j<Weight;j++){
                    step += abs(Array[i][j] - Array[i-1][j]);
                }
            }
        }
        cout << step << endl;
    }
    return 0;
}