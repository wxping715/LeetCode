/*
Implement a MapSum class with insert, and sum methods.

For the method insert, you'll be given a pair of (string, integer). The string represents the key and the integer represents the value. If the key already existed, then the original key-value pair will be overridden to the new one.

For the method sum, you'll be given a string representing the prefix, and you need to return the sum of all the pairs' value whose key starts with the prefix.

Example 1:
Input: insert("apple", 3), Output: Null
Input: sum("ap"), Output: 3
Input: insert("app", 2), Output: Null
Input: sum("ap"), Output: 5
*/

struct TrieNode {
    int value;
    TrieNode* next[26];
    
    TrieNode() {
        value = 0;
        memset(next, 0, sizeof(next));
    }
};

class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        TrieNode* p = root;
        for (char ch : key) {
            if (!p->next[ch-'a']) 
                p->next[ch-'a'] = new TrieNode();
            p = p->next[ch-'a'];
        }
        p->value = val;
    }
    
    int sum(string prefix) {
        TrieNode* p = root;
        for (char ch : prefix) {
            if (!p) return 0;
            p = p->next[ch-'a'];
        }
        return dfs(p);
    }
    
    int dfs(TrieNode* p) {
        if (!p) return 0;
        int sum = p->value;
        for (int i = 0; i < 26; i++) {
            sum += dfs(p->next[i]);
        }
        return sum;
    }
    
private:
    TrieNode* root;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
