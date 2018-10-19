#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
    list<pair<int, int>> storage;
    unordered_map<int, list<pair<int, int>>::iterator> mapping; 
    int capacity;
                    
    LRUCache(int capacity) : capacity(capacity) {}
            
    int get(int key) {
        if (mapping.find(key) == mapping.end())
            return -1;
        int val = mapping[key]->second;
        storage.erase(mapping[key]);
        storage.push_back({key, val});
        mapping[key] = --storage.end();   
        return val;
    }
        
    void put(int key, int value) {
        if (get(key) == -1) {
            if (int(storage.size()) == capacity) {
                 mapping.erase(storage.begin()->first);
                 storage.erase(storage.begin());
            }
            storage.push_back({key, value});
            mapping[key] = --storage.end();
                                            
        } else {
            list<pair<int, int>>::iterator node = storage.end();
            node--;
            node->second = value;
        }           
    }
};

int main()
{
    return 0;
}

