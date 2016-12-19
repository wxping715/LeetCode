class TrieNode {
public:
    TrieNode* next[26];
    bool is_word;
    // Initialize your data structure here.
    TrieNode() {
        memset(next, 0, sizeof(next));
        is_word = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* p = root;
        for (char ch : word) {
            if (p->next[ch-'a'] == NULL)
                p->next[ch-'a'] = new TrieNode();
            p = p->next[ch-'a'];
        }
        p->is_word = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* p = find(word);
        return p != NULL && p->is_word == true;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* p = find(prefix);
        return p != NULL;
    }

private:
    TrieNode* root;
    
    TrieNode* find(string s) {
        TrieNode *p = root;
        for (char ch : s) {
            if (p == NULL) return p;
            p = p->next[ch-'a'];
        }
        return p;
    }
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
