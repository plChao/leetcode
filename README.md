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
            因為 sort 之後要看原本的 index 是什麼，所以難以實做。
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
### 191_Number_of_1_Bits
1. 分析
    1. 最差做 32 次就是 O(1)
    2. 看一個數字 num 的第 n 位是不是 1
        1. ( num >> n ) && 1
2. 對答案
    1. 取 num 最低位的 1
        1. ( num & num - 1 ) 去除最低位的 1
        2. num - ( num & num - 1 ) 或 num & -num 得到最低位的 1
        3. $log_2( 最低位的 1 值 ) 來拿到位置$  
### 147_LRU_cache
1. 分析
    1. 要求
        1. 如果沒放滿，把 key map 到 memory index，然後放進 memory index 裡
        2. 如果滿了，找 LRU 的 key 的 index，把它換成新的 
    1. 用 unordered_map <key=key, value=memory_index> 來記錄 key 存在哪個地址，或是可以直接存 value?
    2. 用一個 queue 來記錄 LRU(least recently used) 的 block 是誰
        1. 但是如果有用到已經在 queue 紀錄裡的 block 要把它刪掉
    3. Time
        1. init
        2. put
            1. find victim: O(1)
            2. deal victim
                1. queue ~~front~~ end is the LRU victim，因為 insert front 時記錄 address 比較簡單
                2. unordered_map<key-value> erase: O(1)
                3. unordered_map<key-queue_addr> erase: O(1)
            3. store new page: 
                1. unordered_map<key-value> insert(): O(1)
                2. queue (link list) insert: O(1)
                3. unordered_map<key-queue_addr> insert(): O(1)
        3. get
            1. 如果沒有找到: return NULL
                1. ps. 正常 OS 會在這裡從 HD 拿 value 做 put(key, value)
            2. 如果有找到
                1. 更新 LRU queue
                    1. **find the queue position: unordered_map.find(): O(1)**
                    2. **delete record from queue (link list): O(1)**
                2. return  unordered_map[key]
2. 對答案
    1. 用一個 queue 來記錄 LRU(least recently used) 的 block 是誰
        1. 但是如果有用到已經在 queue 紀錄裡的 block 要把它刪掉 => 為了有效率的刪除，queue 本身會用 link list 來做
        2. 為了有效率的搜尋上一次紀錄在 queue 的哪裡，會使用 unorder_map<key=key, value=* queue_block> 來在 O(1) 的複雜度來找到位置
### 56_merge_interval
1. tag: greedy, activity-selection problem, advance from basic
2. 分析
    1. 原本想說是 greedy 找 max independent interval。
        1. 原問題 activity-selection problem，找最多個不重疊的 intervals (greedy 解 O(nlogn + n))
        2. 可以用這個精神
2. 對答案
    1. 按起始順序排，如果可以 merge 就 merge
    2. 不行 merge 就記錄下一個 interval
    3. sort O(n log n)，解題 O(n)，共 O(n log n)
3. 實做
    1. \[tech\] 在 class 內部的 costum_cmp (要給 sort) 的，要加 static 以去除原本預設的第一個 this 參數。詳情見[這篇](https://blog.csdn.net/u010982765/article/details/79021426) 
### 679
1. 分析
    1. 用一個 array 來記錄每種組合可以組出的數量 Ex. A[3] = A[0011] 代表使用後兩張牌可以組出的值
    2. 每次切一個切法，然後把兩邊的可能性做組合
        1. 四張牌: 1/3, 2/2
        2. 三張牌: 1/2
2. 對答案
    1. 因為這題是找"能不能"，所以用 DFS 尋找會比較快，一找到就可以結束程式
    2. 組合任兩張牌成新的值，把新的值當作新的排往下遞迴組合
### 161
1. 分析
    1. 原本想得太複雜
    2. 要考慮所有 case
        1. 長度一樣
        2. 長度差一
            1. 把長的 pop 掉不一樣的
            2. :star: 長的最後一個位置容易漏掉
        3. 長度差一以上
            1. false
2. 對答案
3. 實作
    1. 可以用以下好看方法判斷誰長誰短
        ```c++=0
            bool isOneEditDistance(string l, string short_str) {
                if(short_str.size() > l.size()){
                    return isOneEditDistance(short_str, l);
                }
                // we can promise l.size() > short_str.size() here
                // some code ...
            }
        ```
### 44
1. 分析
    1. 如果 pattern[0] == * => (看 text 跟 pattern[1:] 有沒有 match) 或 (text[1:] 跟 pattern 有沒有 match)
    2. first_match = pattern[0] in {text[0], '?'} => 看 text[1:] 跟 pattern[1:] 有沒有 match
    3. 時間複雜度 T(t, p) = T(t, p-1) + T(t-1, p) + T(t-1, p-1) + O(1)
        1. 沒有 DP: T(t, p) = O(2^(T+P))
        2. DP: T(t, p) = O(tp)
2. 對答案
3. 實作
    1. 要考慮好 recursive 的邊緣 case
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
## leet_code_crack_algro
### binary search
#### 1060_Missing_Element_in_Sorted_Array
1. 分析
    1. binary search: O(log n)
2. 實作
    1. 用 `num[pos] - num[0]` 看原本有幾個數字在前面，再減掉 pos (有出現的數字個數) 代表目前有幾個數字消失。
    2. 所以下一個數字 (num[pos]) 是第 `num[pos] - num[0] - pos + 1` 個數字
    3. 如果用 2. 代替 num 中的數值的話，我們要找 k 在 num 中的 upper_bound - 1
        1. 如果有多個連續都是 k 的話 (下一個數字是 k th missing)，要找最後一個。
3. TODO
    1. 了解 excercise_binary_search 的寫法，以及 edge case 會是如何?
#### 1901_Find_Peak_Element_II
1. TAG: binary search, peak search, special though
1. 分析
    1. 找 1D 的 peak 是 162 的題目，可以用 binary search 實現
    2. 而把所有 row 的 max element 找出來形成 arrary，此 array 中的 peak，就會是 2D 的其中一個 peak
    3. 如此 M*N 的 matrix 需要 log N 次的 M 來找到 peak，即 O(M log N)
2. 實作
    如上

    