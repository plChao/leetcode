# leetcode
## 148
### bug1 
    ListNode *left, *right=nullptr;
    不會對兩個變數做初始化
## 10
### tech1
    要改變 pointer 的值要用 pass by reference 的 pointer
    pointer 跟 pass by ref 的差別在於 pointer 的功能比 pass by ref 更多，pointer 可以用於指向別的 object 的功能，也涵蓋 pass by ref 的 local 修改到 global var 的功能。
    以下是 pass by ref 的 pointer 的例子
    ```
    void reverselist(ListNode*& head, ListNode*& tail){
    }
    ```
## 78 subsets
1. 跟窮舉有關的題目 (排列、組合、Power set)，有三種方法
    1. Cascading
    2. Backtracking
    3. Bitmap
2. 要拿到 int 在第 k 個 bit 是 0 或 1 的方法
    ```
    (n & (1 << k)) >> k
    ```
## 23 merge k sorted list
1. 有 priority queue 的用法，有空可以看他的第二個參數是什麼
2. 第三個參數的 cmp (a, b) 中，是問 b 的優先程度有沒有比 a 大，如果是要 max-queue，就回傳 a < b