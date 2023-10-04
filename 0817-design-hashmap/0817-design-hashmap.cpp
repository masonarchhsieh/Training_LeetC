class MyHashMap {
    vector<pair<int, int>> hash_map;
public:
    MyHashMap() {
        hash_map.clear();
    }
    
    void put(int key, int value) {
        for (auto &i : hash_map)
            if (i.first == key) {
                i.second = value;
                return;
            }
        hash_map.push_back({key, value});
    }
    
    int get(int key) {
        for (auto i : hash_map)
            if (i.first == key)
                return i.second;
                
        return -1;
    }
    
    void remove(int key) {
        vector<pair<int, int>>::iterator it;
        for (it = hash_map.begin(); it != hash_map.end(); it++) {
            if ((*it).first == key) {
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