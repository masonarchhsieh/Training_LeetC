// https://leetcode.com/problems/design-hashmap

class MyHashMap {
    
    
public:
    vector<pair<int, int>> hash_map;

    /** Initialize your data structure here. */
    MyHashMap() {
       // hash_map = new vector<pair<int, int>>();
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        vector<pair<int, int>>::iterator it;
        for (it = hash_map.begin(); it < hash_map.end(); ++it) {
            if (it->first == key) {
                it->second = value;
                return;
            }
        }
        hash_map.push_back(make_pair(key, value));
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        vector<pair<int, int>>::iterator it;
         for (it = hash_map.begin(); it < hash_map.end(); ++it) {
            if (it->first == key) {                
                return it->second;
            }
        }

        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        vector<pair<int, int>>::iterator it;
         for (it = hash_map.begin(); it < hash_map.end(); ++it) {
            if (it->first == key) {                
                hash_map.erase(it);
                return;
            }
        }       
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */