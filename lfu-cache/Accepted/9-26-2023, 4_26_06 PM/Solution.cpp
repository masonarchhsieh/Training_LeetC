// https://leetcode.com/problems/lfu-cache

struct Node {
    int key;
    int val;
    int counter;
    Node *next;
    Node *prev;
    Node(int _key, int _val) {
        key = _key;
        val = _val;
        counter = 1;
        next = nullptr;
        prev = nullptr;
    }
};


class LFUCache {
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> m;
    int size = 0;
public:
    LFUCache(int capacity) {
        size = capacity;
        head->next = tail;
        tail->next = head;
    }
    int get(int key) {
        unordered_map<int,Node*>::iterator found = m.find(key);
        // didn't found it
        updateCounter();
        if (found == m.end()) {
            return -1;
        }

        Node *node = m[key];
        deleteNode(node);
        addNode(node);
        node->counter++;
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
    Node* nextVictim() {
        Node* t = tail->prev;
        Node* vic = t;
        while (t != head) {
            if (t->counter < vic->counter) {
                vic = t;
            }
            t = t->prev;
        }
        cout << "next vic: " << vic->key << ", "  << vic->val << ", " << vic->counter << endl;
        return vic;
    }
    void updateCounter() {
        // for (auto &i : m) {
        //     (i.second)->counter--;
        // }
    }
    void put(int key, int value) {
        unordered_map<int,struct Node*>::iterator found = m.find(key);
        // found it
        if (found != m.end()) {
            Node *node = m[key];
            deleteNode(node);
            addNode(node);
            node->val = value;
            node->counter++;
            updateCounter();
            return;
        }
        if (m.size() == size) {
            Node *vic = nextVictim();
            deleteNode(vic);
        }
        addNode(new Node(key, value));
        updateCounter();
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */