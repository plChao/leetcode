#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// void Insert(ListNode *previous, ListNode* insert){
//     insert->next = previous->next;
//     previous->next = insert;
// }
// ListNode* unInsert(ListNode* previous){
//     ListNode* tar = previous->next;
//     previous->next = tar->next;
//     return tar;
// }
void print_list(ListNode *head){
    ListNode *cur = head;
    while(cur != nullptr){
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}
class Solution {
public:
    ListNode* get_tail(ListNode *head){
        ListNode *cur;
        cur = head;
        while(cur->next != nullptr){
            cur = cur->next;
        }
        return cur;
    }
    ListNode* sortList(ListNode* head) {
        if(head == nullptr){
            return head;
        }
        vector<int> copy;
        copy.reserve(50000);
        ListNode *cur;
        cur = head;
        while(cur != nullptr){
            copy.push_back(cur->val);
            cur = cur->next;
        }
        sort(copy.begin(), copy.end());
        cur = head;
        for(auto i:copy){
            cur->val = i;
            cur = cur->next;
        }
        return head;
    }
};
int main(int argc, char const *argv[])
{   
    int num = atoi(argv[1]);
    ListNode* head = nullptr;
    ListNode* cur;
    for(int i=0;i<num;i++){
        cur = new ListNode(rand() % 100, head);
        head = cur;
    }
    print_list(head);
    Solution s = Solution();
    head = s.sortList(head);
    cout << "out" << endl;
    print_list(head);
    return 0;
}
