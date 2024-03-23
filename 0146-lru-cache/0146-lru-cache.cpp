struct Node {
    int key;
    int val;
    Node *next;
    Node *prev;
    Node(int _key, int _val) {
        key = _key;
        val = _val;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> m;
    int size = 0;
public:
    LRUCache(int capacity) {
        size = capacity;
        head->next = tail;
        tail->next = head;
    }
    
    int get(int key) {
        unordered_map<int,Node*>::iterator found = m.find(key);
        // didn't found it
        if (found == m.end()) {
            return -1;
        }

        Node *node = m[key];
        deleteNode(node);
        addNode(node);
        return node->val;
    }
    void deleteNode(Node *node) {
        unordered_map<int, Node*>::iterator found = m.find(node->key);
        if (found != m.end()) {
            m.erase(found);
        }
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void addNode(Node* node) {
        m.insert(make_pair(node->key, node));
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }
    void put(int key, int value) {
        unordered_map<int,struct Node*>::iterator found = m.find(key);
        // found it
        if (found != m.end()) {
            Node *node = m[key];
            deleteNode(node);
            addNode(node);
            node->val = value;
            return;
        }
        if (m.size() == size) {
            deleteNode(tail->prev);
        }
        addNode(new Node(key, value));
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */