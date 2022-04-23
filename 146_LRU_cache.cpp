#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<cmath>
#include<queue>
#include<list>

using namespace std;

class LRUCache {
public:
    unordered_map<int, int> memory;
    unordered_map<int, list<int>::iterator> record_pos;
    list<int> LRUrecord;
    int max_size;
    LRUCache(int capacity) {
        max_size = capacity;
        memory.reserve(max_size); // need to reserve to avoid TLE
        record_pos.reserve(max_size);
    }
    int get(int key) {
        if(memory.find(key) == memory.end()){
            return -1;
        }
        else{
            // update LRU
            LRUrecord.erase(record_pos[key]);
            LRUrecord.push_front(key);
            record_pos[key] = LRUrecord.begin();
            // return value in memory
            return memory[key];
        }   
    }
    void put(int key, int value) {
        if(memory.find(key) != memory.end()){
            // already in memory
            // update LRU
            LRUrecord.erase(record_pos[key]);
            LRUrecord.push_front(key);
            record_pos[key] = LRUrecord.begin();
            // change value in memory
            memory[key] = value;
        }
        else{
            // not in memory
            if(memory.size() == max_size){
                // find victim
                int last_key = LRUrecord.back();
                LRUrecord.pop_back();
                record_pos.erase(last_key);
                memory.erase(last_key);
            }
            // update LRU
            LRUrecord.push_front(key);
            record_pos[key] = LRUrecord.begin();
            // add to memory
            memory[key] = value;
        }
    }
};

int main(int argc, char const *argv[])
{   
    LRUCache lRUCache = *(new LRUCache(2));
    lRUCache.put(1, 1); // cache is {1=1}
    lRUCache.put(2, 2); // cache is {1=1, 2=2}
    cout << lRUCache.get(1) << " ";    // return 1
    lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    cout << lRUCache.get(2) << " ";    // returns -1 (not found)
    lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    cout << lRUCache.get(1) << " ";    // return -1 (not found)
    cout << lRUCache.get(3) << " ";    // return 3
    cout << lRUCache.get(4) << " ";    // return 4
    return 0;
}