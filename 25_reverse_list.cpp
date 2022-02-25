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
    void reverselist(ListNode* head, ListNode* tail, int len){
        ListNode * cur, *left_head, *left_tail, *right_head, *right_tail, *center;
        if(len == 1){
            return;
        }
        if(len % 2 == 1){
            int mid = len / 2 - 1;
            cur = head;
            for(int i=0;i<mid;i++){
                cur = cur->next;
            }
            left_tail = cur;
            center = left_tail->next;
            right_head = center->next;
            left_head = head;
            right_tail = tail;
            reverselist(left_head, left_tail, len/2);
            reverselist(right_head, right_tail, len/2);
            // reverse
            // link right->center->left
            head = right_head;
            right_tail->next = center;
            center->next = left_head;
            tail = left_tail;
            left_tail->next = nullptr;
            return;
        }
        else{
            int mid = len / 2 - 1;
            cur = head;
            for(int i=0;i<mid;i++){
                cur = cur->next;
            }
            left_head = head;
            left_tail = cur;
            right_head = left_tail->next;
            right_tail = tail;
            reverselist(left_head, left_tail, len/2);
            reverselist(right_head, right_tail, len/2);
            // link right->left
            head = right_head;
            right_tail->next = left_head;
            tail = left_tail;
            return;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int pos = 1;
        ListNode *tar_head, *tar_tail; 
        ListNode *pre_head = nullptr, *pos_tail;
        ListNode *cur = head;
        while(cur != nullptr){
            if(pos == 1){
                tar_head = cur;
            }
            if(pos == k){
                tar_tail = cur;
                pos_tail = tar_tail->next;
                tar_tail->next = nullptr;
                print_list(tar_head);
                reverselist(tar_head, tar_tail, k);
                tar_tail->next = nullptr;
                print_list(tar_head);
                if(pre_head == nullptr){
                    head = tar_head;
                }
                else{
                    pre_head->next = tar_head;
                }
                tar_tail->next = pos_tail;
                pos = 0;
                pre_head = cur;
            }
            cur = cur->next;
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
        cur = new ListNode(i, head);
        head = cur;
    }
    print_list(head);
    Solution s = Solution();
    head = s.reverseKGroup(head, k);
    cout << "out" << endl;
    print_list(head);
    return 0;
}
