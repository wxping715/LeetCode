/*An abbreviation of a word follows the form <first letter><number><last letter>. Below are some examples of word abbreviations:

a) it                      --> it    (no abbreviation)

     1
b) d|o|g                   --> d1g

              1    1  1
     1---5----0----5--8
c) i|nternationalizatio|n  --> i18n

              1
     1---5----0
d) l|ocalizatio|n          --> l10n
Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary. A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.

Example: 
Given dictionary = [ "deer", "door", "cake", "card" ]

isUnique("dear") -> 
false

isUnique("cart") -> 
true

isUnique("cane") -> 
false

isUnique("make") -> 
true*/

class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for (string word : dictionary) {
            string key = generate(word);
            hash[key].insert(word);
        }
    }

    bool isUnique(string word) {
        string key = generate(word);
        return hash[key].count(word) == hash[key].size();
    }

    string generate(string word) {
        string key = "";
        key.push_back(word[0]);
        key += to_string(word.length()-2);
        key.push_back(word.back());
        return key;
    }

private:
    unordered_map<string, unordered_set<string> > hash;
};
