/*
In English, we have a concept called root, which can be followed by some other words to form another longer word - let's call this word successor. For example, the root an, followed by other, which can form another word another.

Now, given a dictionary consisting of many roots and a sentence. You need to replace all the successor in the sentence with the root forming it. If a successor has many roots can form it, replace it with the root with the shortest length.

You need to output the sentence after the replacement.

Example 1:
Input: dict = ["cat", "bat", "rat"]
sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
Note:
The input will only have lower-case letters.
1 <= dict words number <= 1000
1 <= sentence words number <= 1000
1 <= root length <= 100
1 <= sentence words length <= 1000
*/

struct TrieNode {
    bool isWord;
    TrieNode* next[26];
    
    TrieNode() {
        isWord = false;
        memset(next, 0, sizeof(next));
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        root = new TrieNode();
        
        for (string s : dict)
            insert(s);
        
        string res = "", cur = "";
        for (int i = 0; i < sentence.length(); i++) {
            if (sentence[i] != ' ')
                cur.push_back(sentence[i]);
            else {
                string token = shortestPrefix(cur);
                token = token.empty() ? cur : token;
                res += " " + token;
                cur = "";
            }
            
            if (i+1 == sentence.length()) {
                string token = shortestPrefix(cur);
                token = token.empty() ? cur : token;
                res += " " + token;
            }
        }
        return res.substr(1, res.length()-1);
    }

private:
    TrieNode* root;
    
    void insert(string &s) {
        TrieNode* p = root;
        for (char ch : s) {
            if (!p->next[ch-'a']) p->next[ch-'a'] = new TrieNode();
            p = p->next[ch-'a'];
        }
        p->isWord = true;
    }
    
    string shortestPrefix(string& s) {
        TrieNode* p = root;
        int len = 0;
        for (char ch : s) {
            if (p == NULL || p->isWord) break;
            p = p->next[ch-'a'];
            len++;
        }
        return (p ? s.substr(0, len) : "");
    }
};
