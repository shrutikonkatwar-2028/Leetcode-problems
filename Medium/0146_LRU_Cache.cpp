#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> mp;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        auto node = mp[key];
        int value = node->second;

        cache.erase(node);
        cache.push_front({key, value});
        mp[key] = cache.begin();

        return value;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            cache.erase(mp[key]);
        } else if (cache.size() == capacity) {
            auto last = cache.back();
            mp.erase(last.first);
            cache.pop_back();
        }

        cache.push_front({key, value});
        mp[key] = cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
