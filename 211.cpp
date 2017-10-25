/*
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

For example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
*/

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
    TrieNode* root;
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
    TrieNode* find(string s) {
        TrieNode *p = root;
        for (char ch : s) {
            if (p == NULL) return p;
            p = p->next[ch-'a'];
        }
        return p;
    }
};

class WordDictionary {
public:

    // Adds a word into the data structure.
    void addWord(string word) {
        trie.insert(word);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return dfs_search(trie.root, word, 0);
    }

    bool dfs_search(TrieNode* p, string word, int idx) {
        char ch = word[idx];
        if (idx == word.length() && p->is_word) return true;
        for (int i = 'a'; i <= 'z'; i++) {
            if ((ch == '.' && p->next[i-'a'] != NULL) ||
                (ch != '.' && i == ch && p->next[i-'a'] != NULL)) {
                    bool res = dfs_search(p->next[i-'a'], word, idx+1);
                    if (res) return true;
                }
        }
        return false;
    }

private:
    Trie trie;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
