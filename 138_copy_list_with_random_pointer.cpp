#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<map>

using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

void print_list(Node *head){
    Node *cur = head;
    while(cur != nullptr){
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}
map <Node*, Node*> copyed_Node;

Node* copy_Node(Node * ptr){
    if(ptr == nullptr){
        return nullptr;
    }
    auto iter = copyed_Node.find(ptr);
    if(iter != copyed_Node.end()){
        return iter->second;
    }
    Node *newNode = new Node(ptr->val);
    copyed_Node[ptr] = newNode;
    newNode->next = copy_Node(ptr->next);
    newNode->random = copy_Node(ptr->random);
    return newNode;
}

class Solution {
public:
    Node* copyRandomList(Node* head) {
        return copy_Node(head);
    }
};

int main(int argc, char const *argv[])
{   
    int num = atoi(argv[1]);
    Node* head = nullptr;
    Node* cur;
    for(int i=0;i<num;i++){
        cur = new Node(rand() % 100);
        cur->next = head;
        head = cur;
    }
    print_list(head);
    Solution s = Solution();
    head = s.copyRandomList(head);
    cout << "out" << endl;
    print_list(head);
    return 0;
}