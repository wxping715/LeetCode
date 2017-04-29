class Solution {
public:

    /*Let's build a list of candidate answers for which the final answer must be one of those candidates. Afterwards, choosing from these candidates is straightforward.

    If the final answer has the same number of digits as the input string S, then the answer must be the middle digits + (-1, 0, or 1) flipped into a palindrome. For example, 23456 had middle part 234, and 233, 234, 235 flipped into a palindrome yields 23332, 23432, 23532. Given that we know the number of digits, the prefix 235 (for example) uniquely determines the corresponding palindrome 23532, so all palindromes with larger prefix like 23732 are strictly farther away from S than 23532 >= S.
    
    If the final answer has a different number of digits, it must be of the form 999....999 or 1000...0001, as any palindrome smaller than 99....99 or bigger than 100....001 will be farther away from S.*/
    
    string nearestPalindromic(string n) {
        int len = n.size();
        vector<long> candicates;
        
        candicates.push_back((long)pow(10, len)+1);
        candicates.push_back((long)pow(10, len-1)-1);
        
        int prefix = stol(n.substr(0, (len+1)/2));
        for (long i = -1; i <= 1; i++) {
            string cur = to_string(prefix+i);
            string ans = cur + string(cur.rbegin()+(len&1), cur.rend());
            candicates.push_back(stol(ans));
        }
        
        long min_diff = INT_MAX, palind, orig = stol(n);
        for (long v : candicates) {
            if (v == orig) continue;
            if (abs(orig-v) < min_diff) {
                palind = v;
                min_diff = abs(orig-v);
            }
        }
        return to_string(palind);
    }
};
