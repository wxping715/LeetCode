class LRUCache{
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) return -1;
        
        int val = it->second->second;
        ulist.splice(ulist.begin(), ulist, it->second);
        return val;
    }
    
    void set(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) {
            ulist.splice(ulist.begin(), ulist, it->second);
            it->second->second = value;
        } else {
            if (ulist.size() == capacity)
                remove();
            ulist.emplace_front(key, value);
            cache.emplace(key, ulist.begin()); 
        }
    }
    
    void remove() {
        auto node = ulist.back();
        cache.erase(node.first);
        ulist.pop_back();
    }

private:
    typedef pair<int, int> node;
    list<node> ulist;
    unordered_map<int, list<node>::iterator> cache;
    int capacity;
};
