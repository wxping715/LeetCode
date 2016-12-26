class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        // cout << "inc key = " << key << endl;
        if (!counter.count(key)) counter[key] = 1;
        else counter[key]++;
        
        int cur = counter[key], pre = cur-1;
        if (!pointers.count(cur)) {
            list<unordered_set<string>>::iterator pit;
            if (cur == 1) pit = keys.begin();
            else {
                pit = pointers[pre];
                pit++;
            }
            auto it = keys.insert(pit, unordered_set<string>());
            pointers[cur] = it;
        }
        pointers[cur]->insert(key);
        if (pre != 0) {
            pointers[pre]->erase(key);
            if (pointers[pre]->empty()) {
                keys.erase(pointers[pre]);
                pointers.erase(pre);
            }
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        // cout << "dec key = " << key << endl;
        if (!counter.count(key)) return;
        
        int pre = counter[key], cur = pre-1;
        if (counter[key] == 1) counter.erase(key);
        else counter[key]--;
        
        if (cur != 0) {
            if (!pointers.count(cur)) {
                auto pit = cur == 1 ? keys.begin() : pointers[pre];
                auto it = keys.insert(pit, unordered_set<string>());
                pointers[cur] = it;
            }
            pointers[cur]->insert(key);
        }
        pointers[pre]->erase(key);
        if (pointers[pre]->empty()) {
            keys.erase(pointers[pre]);
            pointers.erase(pre);
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if (keys.empty()) return "";
        return *(keys.back().begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if (keys.empty()) return "";
        return *(keys.front().begin());
    }

private:
    unordered_map<string, int> counter;
    list<unordered_set<string>> keys;
    unordered_map<int, list<unordered_set<string>>::iterator> pointers;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */
