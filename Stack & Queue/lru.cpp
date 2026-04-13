#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
  public:
    list<pair<int,int>> l;
    int capacity;
    unordered_map<int, list<pair<int,int>>::iterator> mp; 
    LRUCache(int cap) {
        // code here
        capacity = cap;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;

        auto it = mp[key];
        int val = it->second;

        l.erase(it);
        l.push_front({key, val});
        mp[key] = l.begin();

        return val;
        
        // code here
    }

        
    void put(int key, int value) {
        // code here
           if (mp.find(key) != mp.end()) {
            // remove old
            l.erase(mp[key]);
        } else if (l.size() == capacity) {
            auto last = l.back();
            mp.erase(last.first);
            l.pop_back();
        }

        l.push_front({key, value});
        mp[key] = l.begin();
    }
};