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


class Solution {
public:
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
    vector<set<float>> possible_value;
    // vecotr<float> four_cards_array;
    vector<int> four_cards_array;
    void init_vector(){
        int times = (1 << 5);
        set<float> empty_set;
        possible_value.reserve(1 << 5);
        while(times--){
            possible_value.push_back(empty_set);
        }
        return;
    }
    void free_vector(){
        for(auto i:possible_value){
            i.clear();
        }
        possible_value.clear();
        four_cards_array.clear();
    }
    int index_of_combination(vector<int> & indexs){
        int res = 0;
        for(int i:indexs){
            res += (1 << i);
        }
        return res;
    }
    set<float> * get_possible_value_of_cards(vector<int> card_index){
        if(possible_value[index_of_combination(card_index)].size() != 0){
            // cout << "dp" << endl;
            return &(possible_value[index_of_combination(card_index)]);
        }
        else if(card_index.size() == 1){
            possible_value[index_of_combination(card_index)].insert(four_cards_array[card_index[0]]);
            return &(possible_value[index_of_combination(card_index)]);
        }
        else{
            set<float> *res = &(possible_value[index_of_combination(card_index)]);
            set<float> *tmp_set;
            for(int i=0;i< card_index.size();i++){
                float card_value = four_cards_array[card_index[i]];
                vector<int> tmp = card_index;
                tmp.erase(tmp.begin()+i);
                tmp_set = get_possible_value_of_cards(tmp);
                if(tmp_set->size() == 0){
                    cout << "Error: empty" << endl;
                    print_int_vec(tmp);
                }
                for (auto &s : *tmp_set){
                    res->insert(card_value * s);
                    res->insert(card_value + s);

                    res->insert(card_value - s);
                    res->insert(s - card_value);
                    res->insert(card_value / s);
                    res->insert(s / card_value);
                }
            }
            if(card_index.size() == 4){
                if(res->find(24) != res->end()){
                    return res;
                }
                vector<int> input = {1, 1, 2, 2};
                vector<int> elements = {1, 2};
                int comb[6][4] = {{2, 2, 1, 1}, {2, 1, 2, 1}, {1, 2, 2, 1}, {2, 1, 1, 2}, {1, 2, 1, 2}, {1, 1, 2, 2}};
                vector<int> tmp1;
                vector<int> tmp2;
                set<float> *pos_tmp1, *pos_tmp2;
                for(auto cc:comb){
                    for(int i=0;i<4;i++){
                        if(cc[i] == 1){
                            tmp1.push_back(card_index[i]);
                        }
                        else{
                            tmp2.push_back(card_index[i]);
                        }
                    }
                    pos_tmp1 = get_possible_value_of_cards(tmp1);
                    pos_tmp2 = get_possible_value_of_cards(tmp2);
                    for(auto &first:*pos_tmp1){
                        for(auto &second:*pos_tmp2){
                            res->insert(first * second);
                            res->insert(first + second);

                            res->insert(first - second);
                            res->insert(second - first);
                            res->insert(first / second);
                            res->insert(second / first);
                        }
                    }

                    tmp1.clear();
                    tmp2.clear();
                }
            }
            return res;
        }
    }
    bool judgePoint24(vector<int>& cards){
        init_vector();
        vector<int> index; 
        for(int i=0;i<cards.size();i++){
            four_cards_array.push_back(cards[i]);
            index.push_back(i);
        }
        set<float> *res = get_possible_value_of_cards(index);
        bool ans = res->find(24) != res->end();
        // free_vector();
        return ans;
    }
};
void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;
    
    for (i = size-1; i >= 0; i--) {
        for (j = 7; j >= 0; j--) {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}
int main(int argc, char const *argv[])
{   
    Solution solve;
    // vector<int> input = {1, 1, 2, 2};
    // vector<int> elements = {1, 2};
    // vector<vector<int>> comb = solve.combination(input, elements);
    // cout << comb.size() << endl;
    // for(auto i:comb){
    //     print_int_vec(i);
    // }
    // return 0;
    
    vector<int> vec{3, 3, 8, 8};
    cout << solve.judgePoint24(vec) << endl;
    // int idx = 0;
    // for(auto i : solve.possible_value){
    //     printBits(1, &idx);
    //     if(i.size() == 0)
    //         cout << "empty" <<endl;
    //     for (auto &s : i){
    //         cout << s << " ";   
    //     }
    //     cout << endl;
    //     idx ++;
    // }
    return 0;
}