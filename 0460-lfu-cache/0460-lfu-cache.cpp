class LFUCache {
public:
    struct Node {
        int key, value, freq;
        Node *next, *prev;
        Node(int _key, int _val) : key(_key), value(_val), freq(1), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    int capacity;
    unordered_map<int, pair<Node*, int>> hash;

    LFUCache(int capacity) : capacity(capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (hash.find(key) == hash.end()) return -1;
        Node* cur = hash[key].first;
        cur->freq++;
        hash[key].second = cur->freq;
        deletebefore(cur);
        insertafter(cur);
        return cur->value;
    }

    void insertafter(Node *root) {
        Node* cur = head->next;
        while (cur != tail && cur->freq > root->freq) cur = cur->next;
        root->next = cur;
        cur->prev->next = root;
        root->prev = cur->prev;
        cur->prev = root;
    }

    void deletebefore(Node *root) {
        Node* f = root->prev;
        Node* b = root->next;
        f->next = b;
        b->prev = f;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (hash.find(key) != hash.end()) {
            Node *cur = hash[key].first;
            cur->value = value;
            cur->freq++;
            hash[key].second = cur->freq;
            deletebefore(cur);
            insertafter(cur);
        } else {
            if (hash.size() >= capacity) {
                Node* cur = tail->prev;
                hash.erase(cur->key);
                deletebefore(cur);
                delete cur;
                // size--;
            }
            Node *newnode = new Node(key, value);
            hash[key] = {newnode, 1};
            insertafter(newnode);
            // size++;
        }
    }
};


/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */