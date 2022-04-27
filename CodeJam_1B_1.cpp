#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<cmath>
#include<list>

using namespace std;
void print_int_vec(vector<int> tar){
    for(auto i: tar){
        cout << i << " ";
    }
    cout << endl;
}
int main(int argc, char const *argv[])
{   
    int num_case;
    cin >> num_case;
    for(int cc=1;cc<=num_case;cc++){
        cout << "Case #" << cc << ": ";
        int numbers;
        cin >> numbers;
        vector<int> input;
        for(int i=0;i<numbers;i++){
            int temp;
            cin >> temp;
            input.push_back(temp);
        }
        int count = 0;
        int level = 0;
        while(input.size() > 1){
            auto f_it = input.begin();
            auto b_it = input.end();
            b_it--;
            while((b_it - f_it) > 0 && *f_it == *b_it){
                f_it++;
                b_it--;
            }
            if((b_it - f_it) <= 0){
                count += input.size();
                level = input.front() + 10;
                break;
            }
            if(*f_it < *b_it){
                if(input.front() >= level){
                    count += 1;
                    level = input.front();
                }
                input.erase(input.begin());
            }
            else if(*b_it < *f_it){
                if(input.back() >= level){
                    count += 1;
                    level = input.back();
                }
                input.pop_back();
            }
            else{
                cout << "out of except" << endl;
            }
        }
        if(input.front() >= level){
            count += 1;
        }
        cout << count << endl;
    }
    return 0;
}