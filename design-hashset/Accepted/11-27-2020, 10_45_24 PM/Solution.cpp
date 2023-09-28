// https://leetcode.com/problems/design-hashset

class MyHashSet {
    vector<bool> hash_set;
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        hash_set.assign(1000000, false);
    }
    
    void add(int key) {
        hash_set[key] = true;
    }
    
    void remove(int key) {
        hash_set[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return hash_set[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */