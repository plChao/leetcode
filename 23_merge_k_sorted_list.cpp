#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void print_list(ListNode *head){
    ListNode *cur = head;
    while(cur != nullptr){
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}
// define  priority_queue cmp function
struct cmp{
    bool operator()(const ListNode *a, const ListNode *b){
        // is b priority higher than a
        return a->val > b->val;
    }
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists){
        // init priority queue
        ListNode *res = nullptr, *cur = nullptr, *res_tail = nullptr;
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for(auto list : lists){
            if(list != nullptr){
                pq.push(list);
            }
        }
        if(pq.empty()){
            return res;
        }
        else{
            while(pq.empty() == false){
                cur = pq.top();
                pq.pop();
                if(cur->next != nullptr){
                    pq.push(cur->next);
                }
                // else{
                //     cout << "end of list" << endl;
                // }
                if(res == nullptr){
                    res = cur;
                    res_tail = cur;
                }
                else{
                    res_tail->next = cur;
                    res_tail = cur;
                    cur->next = nullptr;
                }
            }
            return res;
        }
    }
};

int main(int argc, char const *argv[])
{   
    int k = 2;
    ListNode* head = nullptr;
    // = new ListNode(8);
    vector<ListNode*> lists_input;
    for(int j=0;j<k;j++){
        for(int i=5;i>=1;i--){
            head = new ListNode(i+1, head);
        }
        lists_input.push_back(head);
        head = nullptr;
    }
    Solution s = Solution();
    for(auto ele:lists_input){
        print_list(ele);
    }
    head = s.mergeKLists(lists_input);
    cout << "out" << endl;
    print_list(head);
    return 0;
}
