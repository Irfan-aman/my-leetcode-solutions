class LRUCache {
public:
    class Node {
    public:
        int key, val;
        Node* prev;
        Node* next;
        Node(int k, int v) {
            key = k;
            val = v;
            prev = next = NULL;
        }
    };
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> m;
    int limit;
    void addNode(Node* newNode) {
        Node* oldNext = head->next;
        head->next = newNode;
        oldNext->prev = newNode;
        newNode->prev = head;
        newNode->next = oldNext;
    }
    void delNode(Node* oldNode) {
        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;
        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }
    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (m.count(key) == 0)
            return -1;
        Node* ansNode = m[key];
        int ans = ansNode->val;
        delNode(ansNode);
        addNode(ansNode);
        return ans;
    }

    void put(int key, int value) {
        if (m.count(key)) {
            Node* oldNode = m[key];
            m.erase(key);
            delNode(oldNode);
            delete oldNode;
        }
        if (limit == m.size()) {
            Node* lruNode = tail->prev;
            m.erase(lruNode->key);
            delNode(lruNode);
            delete lruNode;
        }
        Node* newNode = new Node(key, value);
        m[key] = newNode;
        addNode(newNode);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */