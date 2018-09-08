class LRUCache {
private:
    unordered_map<int, list<pair<int, int>>::iterator> data;
    list<pair<int, int>> lis;
    int size = 0;
    void moveToTop(list<pair<int, int>>::iterator it) {
        lis.splice(lis.begin(), lis, it);
    }
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if (data.find(key) == data.end()) return -1;
        auto it = data.find(key);
        moveToTop(it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        if (data.find(key) != data.end()) {
            auto it = data.at(key);
            it->second = value;
            moveToTop(it);
            return;
        }
        lis.emplace_front(make_pair(key, value));
        auto it = lis.begin();
        data.insert(make_pair(key, it));
        
        if (data.size() > size) {
            auto it = lis.back();
            data.erase(it.first);
            lis.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */