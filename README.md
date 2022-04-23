# leetcode
## 解題過程
1. 分析
2. 對答案
3. 實作
### 1_two sum
1. 分析
    1. loop 所有的數字，loop ~~剩下~~後面的數字
        1. Time: O(n^2)
    2. loop 所有的數字，二分搜剩下的數字
        1. 因為不會排除原本的數，那怎麼確認有重複的數? (upper_bound - lower_bound) > 1
            不用排除，改成搜"後面"的數字
    3. loop 所有的數字，二分搜剩下的數字(使用 map)
        1. map<key=value, vector<int>=indexs of values>
        2. Time: O(2*nlogn)
    3. hash_map
        1. hash_map<key=value, vector<int>=indexs of values>
            2. Time: O(n)
                1. n times => O(n)
                    1. hash_map.insert O(1)
                2. n times => O(n)
                    1. hash_map.find O(1)
2. 對答案
    1. loop 所有的數字，loop ~~剩下~~後面的數字
        1. 因為跟前面數字的組合已經試過了，所以不用看前面的數字
    2. hash_map
        1. 原本 hash_map 要存多個 index 來看是不是有重複
        2. [hash_map-2]() 進化1: 因為只有一個跟兩個的差別(三個重複跟兩個重複是一樣的)，所以用後面的 index 蓋掉前面的 index，然後確認的時候只要 hash_map 裡的 index 跟自己不同，就代表有重複。
        3. [hash_map-3]() 進化2: 可以邊加邊檢查，因為目前檢查跟前面數字的組合，跟後面數字組合由後面數字檢查。因為是先找之後才把目前元素加進去，所以不用檢查 index 是否跟自己不同。
            
## 學會的技術
### 1
#### 使用 hash_map
1. 要在上面加上以下兩行
    ```0=c
    #include<hash_map>
    using namespace __gnu_cxx;
    ```
2. 其實 unordered_map 就是 hash_map
### 148
#### bug1 
    ListNode *left, *right=nullptr;
    不會對兩個變數做初始化
### 10
#### tech1
    要改變 pointer 的值要用 pass by reference 的 pointer
    pointer 跟 pass by ref 的差別在於 pointer 的功能比 pass by ref 更多，pointer 可以用於指向別的 object 的功能，也涵蓋 pass by ref 的 local 修改到 global var 的功能。
    以下是 pass by ref 的 pointer 的例子
    ```
    void reverselist(ListNode*& head, ListNode*& tail){
    }
    ```
### 78 subsets
1. 跟窮舉有關的題目 (排列、組合、Power set)，有三種方法
    1. Cascading
    2. Backtracking
    3. Bitmap
2. 要拿到 int 在第 k 個 bit 是 0 或 1 的方法
    ```
    (n & (1 << k)) >> k
    ```
### 23 merge k sorted list
1. 有 priority queue 的用法，有空可以看他的第二個參數是什麼
2. 第三個參數的 cmp (a, b) 中，是問 b 的優先程度有沒有比 a 大，如果是要 max-queue，就回傳 a < b