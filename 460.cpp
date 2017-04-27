class LFUCache {
public:
    LFUCache(int capacity) {
        size = 0;
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (!cache.count(key)) return -1;
        
        int f = cache[key].second;
        freqMap[f].erase(ptrMap[key]);
        cache[key].second ++;
        freqMap[f+1].push_back(key);
        ptrMap[key] = --freqMap[f+1].end();
        
        if (freqMap[minFreq].size() == 0)
            minFreq++;
        
        return cache[key].first;
    }
    
    void put(int key, int value) {
        if (capacity <= 0) return;
        
        int curVal = get(key);
        if (curVal != -1) {
            cache[key].first = value;
            return;
        }
        
        if (size >= capacity) {
            int dkey = freqMap[minFreq].front();
            cache.erase(dkey);
            ptrMap.erase(dkey);
            freqMap[minFreq].pop_front();
            size--;
        }
        
        cache[key] = make_pair(value, 1);
        freqMap[1].push_back(key);
        ptrMap[key] = --freqMap[1].end();
        minFreq = 1;
        size++;
    }
    
    
private:
    typedef pair<int, int> node;
    // key -> list pointer
    unordered_map<int, list<int>::iterator> ptrMap;
    // key -> val, freq
    unordered_map<int, node> cache;
    // freq -> list<key>
    unordered_map<int, list<int>> freqMap;
    
    int size;
    int capacity;
    int minFreq;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.set(key,value);
 */
