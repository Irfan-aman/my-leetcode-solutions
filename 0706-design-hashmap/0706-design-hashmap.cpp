class MyHashMap {
public:
    int size = 10000;
    vector<list<pair<int, int>>> bucket;
    MyHashMap() { bucket.resize(size); }

    void put(int key, int value) {
        int bucketNo = key % size; // hash function= key%size
        auto& chain = bucket[bucketNo];
        for (auto& it : chain) {
            if (it.first == key) {
                it.second = value;
                return;
            }
        }
        chain.emplace_back(key, value);
    }

    int get(int key) {
        int bucketNo = key % size;
        auto& chain = bucket[bucketNo];
        for (auto& it : chain) {
            if (it.first == key) {
                return it.second;
            }
        }
        return -1;
    }

    void remove(int key) {
        int bucketNo = key % size;
        auto& chain = bucket[bucketNo];
        for (auto it = chain.begin(); it != chain.end(); it++) {
            if ((it->first) == key) {
                chain.erase(it);
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