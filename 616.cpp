/*
Given a string s and a list of strings dict, you need to add a closed pair of bold tag <b> and </b> to wrap the substrings in s
 that exist in dict. If two such substrings overlap, you need to wrap them together by only one pair of closed bold tag. Also, if 
 two substrings wrapped by bold tags are consecutive, you need to combine them.

Example 1:
Input: 
s = "abcxyz123"
dict = ["abc","123"]
Output:
"<b>abc</b>xyz<b>123</b>"
Example 2:
Input: 
s = "aaabbcc"
dict = ["aaa","aab","bc"]
Output:
"<b>aaabbc</b>c"
Note:
The given dict won't contain duplicates, and its length won't exceed 100.
All the strings in input have length in range [1, 1000].
*/

class Solution {
public:
	
	bool static compare(pair<int, int>& a, pair<int, int>& b) {
		if (a.first == b.first) return a.second < b.second;
		return a.first < b.first;
	}
	
	// merge intervals
    string addBoldTag(string s, vector<string>& dict) {
    	
    	// compute intervals
        unordered_set<string> hashset;
        for (string s : dict)
        	hashset.insert(s);
        
        vector<pair<int, int>> intervals;
        for (int i = 0; i < s.length(); i++) {
        	string t = "";
        	for (int j = 1; i+j <= s.length(); j++) {
        		t.push_back(s[i+j-1]);
        		if (hashset.count(t))
        			intervals.emplace_back(i, i+j);
        	}
        }
        
        // merge intervals
        sort(intervals.begin(), intervals.end(), compare);
        if (intervals.empty()) return s;
        vector<pair<int, int>> mintervals;
        int st = intervals[0].first, e = intervals[0].second;
        for (auto interval : intervals) {
        	if (interval.first <= e) e = max(e, interval.second);
        	else {
        		mintervals.emplace_back(st, e);
        		st = interval.first;
        		e = interval.second;
        	}
        }
        mintervals.emplace_back(st, e);
        
        // convert
        string res = "";
        int i = 0, j = 0;
        while (i < s.length()) {
        	if (j < mintervals.size() && i == mintervals[j].first) {
        		res += "<b>";
        		res += s.substr(i, mintervals[j].second-mintervals[j].first);
        		res += "</b>";
        		i = mintervals[j].second;
        		j++;
        	}
        	else res.push_back(s[i++]);
        }
        
        return res;
    }
};
