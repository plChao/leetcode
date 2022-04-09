#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<cmath>

using namespace std;

int main(int argc, char const *argv[])
{   
    int num_case;
    cin >> num_case;
    for(int cc=1;cc<=num_case;cc++){
        cout << "Case #" << cc << ": ";
        string input;
        cin >> input;
        int len = input.size();
        // if the char in the string is smaller than the next char, then repetet ouptut again
        int accumulate = 0;
        for(int i=0;i<len;i++){
            if(input[i] < input[i+1]){
                accumulate++;
                // cout << endl << "BUG " << input[i] << " " << accumulate << endl;
                cout << input[i];
                while(accumulate--){
                    cout << input[i];
                }
                accumulate = 0;
            }
            else if(input[i] == input[i+1]){
                cout << input[i];
                accumulate++;
            }
            else{
                cout << input[i];
                accumulate = 0;
            }
        }
        cout << endl;
    }
    return 0;
}