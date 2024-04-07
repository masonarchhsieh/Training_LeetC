class LRUCache {
    int capacity_ = 0;
    struct ListNode {
        int key = -1;
        int value = -1;
        ListNode *next;
        ListNode *prev;

        ListNode(){};
        ListNode(int key, int value) : key(key), value(value) {};
    };
    unordered_map<int, ListNode*> cache;
    ListNode *head, *tail;
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
        head = new ListNode();
        tail = new ListNode();
        head->next = tail;
        head->prev = tail;
        tail->next = head;
        tail->prev = head;
        cache.clear();
    }

    void addNode(ListNode *node) {
        if (!node)
            return;
        tail->prev->next = node;
        node->prev = tail->prev;
        node->next = tail;
        tail->prev = node;
    }

    void deleteNode(ListNode *node) {
        if (!node)
            return;
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end())
            return -1;
        ListNode* t = cache[key];
        deleteNode(t);
        addNode(t);
        return cache[key]->value;
    }
    
    void put(int key, int value) {
        if (cache.find(key) == cache.end()) {
            cout << "cache miss" << endl;
            // delete the least recently used element
            if (cache.size() == capacity_) {
                ListNode* victim = head->next;
                deleteNode(victim);
                cache.erase(victim->key);
                delete victim;
            }
            ListNode* node = new ListNode(key, value);
            addNode(node);
            cache[node->key] = node;
            return;
        }
        // if the data is already in cache
        cache[key]->value = value;
        deleteNode(cache[key]);
        addNode(cache[key]);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */