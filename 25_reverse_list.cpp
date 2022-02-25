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
    ListNode* reverselist(ListNode* head){
        ListNode *newhead = nullptr, *next_cur;
        ListNode *cur = head;
        while(cur != nullptr){
            next_cur = cur->next;

            cur->next = newhead;
            newhead = cur;
            
            cur = next_cur;
        }
        return newhead;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int pos = 1;
        ListNode *tar_head, *tar_tail, *next_cur; 
        ListNode *pre_head = nullptr, *pos_tail;
        ListNode *cur = head;
        while(cur != nullptr){
            next_cur = cur->next;
            if(pos == 1){
                tar_head = cur;
            }
            if(pos == k){
                tar_tail = cur;
                pos_tail = tar_tail->next;
                tar_tail->next = nullptr;
                // print_list(tar_head);
                tar_tail = tar_head;
                tar_head  = reverselist(tar_head);
                // print_list(tar_head);
                if(pre_head == nullptr){
                    head = tar_head;
                }
                else{
                    pre_head->next = tar_head;
                }
                tar_tail->next = pos_tail;
                pos = 0;
                pre_head = tar_tail;
            }
            // cout << "cur" << cur->val << endl;
            cur = next_cur;
            pos += 1;
        }
        return head;
    }
};
int main(int argc, char const *argv[])
{   
    int k = atoi(argv[1]);
    ListNode* head = nullptr;
    ListNode* cur;
    for(int i=0;i<5;i++){
        cur = new ListNode(i+1, head);
        head = cur;
    }
    Solution s = Solution();
    head = s.reverselist(head);
    print_list(head);
    head = s.reverseKGroup(head, k);
    cout << "out" << endl;
    print_list(head);
    return 0;
}
