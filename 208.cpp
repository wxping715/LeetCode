/*
Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.
*/

struct TrieNode {
    bool isWord;
    TrieNode* next[26];
    
    TrieNode() {
        memset(next, 0, sizeof(next));
        isWord = false;
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* p = root;
        for (char ch : word) {
            if (p->next[ch-'a'] == NULL)
                p->next[ch-'a'] = new TrieNode();
            p = p->next[ch-'a'];
        }
        p->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* p = find(word);
        return p != NULL && p->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* p = find(prefix);
        return p != NULL;
    }

private:
    TrieNode* root;
    
    TrieNode* find(string s) {
        TrieNode* p = root;
        for (char ch : s) {
            if (p == NULL) return p;
            p = p->next[ch-'a'];
        }
        return p;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
