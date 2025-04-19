#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

// LRU Cache Implementation
class LRUCache {
private:
    int capacity;
    // Doubly linked list: front = most recently used, back = least recently used
    list<int> keys;
    // Hash map to store key -> (value, iterator to the key in the list)
    unordered_map<int, pair<int, list<int>::iterator>> cache;

public:
    LRUCache(int capacity_): capacity(capacity_){
        cout<<"Cache is created with size "<<capacity<<endl;
    };

    void put(int key, int value)
    {
        // check if key already exists and only update value and put key at front
        if(cache.find(key) != cache.end())
        {
            auto itr = cache[key].second; // iterator of key in list
            keys.erase(itr); // erase key using iterator
            keys.push_front(key); // put key at front now (most recent used)

            cout<<"Value of key: "<<key<<" updated from "<<cache[key].first<<" to "<<value<<endl;
        
            cache[key].first = value; // update only the value 
        }
        else
        {
            // if Cache is full remove the least recently used 
            if(keys.size()==capacity)
            {
                int lruKey = keys.back();
                int val = cache[lruKey].first;
                keys.pop_back();
                cache.erase(lruKey);

                cout<<"Cache is full, LRU will be removed!--> key: "
                <<lruKey<<" value: "<<val<<endl;
            }
            // add new key in list and add key, <value, iterator> in map
            keys.push_front(key);
            auto val = make_pair(value, keys.begin());
            cache[key] = val;
        }
    }

    int get(int key)
    {
        if(cache.find(key) == cache.end())
        {
            return -1;
        }

        int ret = cache[key].first;
        auto itr = cache[key].second;

        keys.erase(itr);
        keys.push_front(key);

        return ret;
    }

    void printKeys()
    {
        cout<<"Cache keys order from MRU to LRU: ";
        for (const auto& k : keys)
        {
            cout<<k<<" ";
        }
        cout<<endl;
    }


public:
  
};

// Example usage
int main() {
    LRUCache cache(3); // Create an LRU Cache with capacity 3

    cache.printKeys();

    cache.put(1, 10);
    cache.put(2, 20);
    cache.put(3, 30);

    cache.printKeys();

    std::cout << "Get 1: " << cache.get(1) << std::endl; // Access key 1

    cache.printKeys();

    cache.put(4, 40); // Add key 4, evict key 2 (least recently used)

    cache.printKeys();

    std::cout << "Get 2: " << cache.get(2) << std::endl; // Key 2 should be evicted
    std::cout << "Get 3: " << cache.get(3) << std::endl; // Access key 3
    std::cout << "Get 4: " << cache.get(4) << std::endl; // Access key 4

    cache.printKeys();

    cache.put(3, 300); //expected value for key 3 to be updated

    cache.printKeys();

    std::cout << "Get 3: " << cache.get(3) << std::endl; // Access key 3
    
    cache.printKeys();

    return 0;
}