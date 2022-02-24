#include<iostream>
#include<vector>
#include<cstring>

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
    ListNode* quicksort(ListNode *head){
        ListNode *left=nullptr, *right=nullptr;
        ListNode *cur, *next_cur;
        if(head->next == nullptr){
            return head;
        }
        cur = head->next;
        while(cur != nullptr){
            next_cur = cur->next;
            if(cur->val < head->val){
                cur->next = left;
                left = cur;
            }
            else{
                cur->next = right;
                right = cur;
            }
            cur = next_cur;
        }
        if(left == nullptr){
            right = quicksort(right);
            head->next = right;
            // print_list(head);
            return head;
        }
        else if(right == nullptr){
            left = quicksort(left);
            get_tail(left)->next = head;
            head->next = nullptr;
            // print_list(left);
            return left;
        }
        else{
            left = quicksort(left);
            right = quicksort(right);
            get_tail(left)->next = head;
            head->next = right;
            // print_list(left);
            return left;
        }
    }
    ListNode* sortList(ListNode* head) {
        if(head == nullptr){
            return head;
        }
        return quicksort(head);
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
    head = s.quicksort(head);
    cout << "out" << endl;
    print_list(head);
    return 0;
}
