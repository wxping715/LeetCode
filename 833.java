/*
To some string S, we will perform some replacement operations that replace groups of letters with new ones (not necessarily the same size).

Each replacement operation has 3 parameters: a starting index i, a source word x and a target word y.  The rule is that if x starts at position i in the original string S, then we will replace that occurrence of x with y.  If not, we do nothing.

For example, if we have S = "abcd" and we have some replacement operation i = 2, x = "cd", y = "ffff", then because "cd" starts at position 2 in the original string S, we will replace it with "ffff".

Using another example on S = "abcd", if we have both the replacement operation i = 0, x = "ab", y = "eee", as well as another replacement operation i = 2, x = "ec", y = "ffff", this second operation does nothing because in the original string S[2] = 'c', which doesn't match x[0] = 'e'.

All these operations occur simultaneously.  It's guaranteed that there won't be any overlap in replacement: for example, S = "abc", indexes = [0, 1], sources = ["ab","bc"] is not a valid test case.

Example 1:

Input: S = "abcd", indexes = [0,2], sources = ["a","cd"], targets = ["eee","ffff"]
Output: "eeebffff"
Explanation: "a" starts at index 0 in S, so it's replaced by "eee".
"cd" starts at index 2 in S, so it's replaced by "ffff".
Example 2:

Input: S = "abcd", indexes = [0,2], sources = ["ab","ec"], targets = ["eee","ffff"]
Output: "eeecd"
Explanation: "ab" starts at index 0 in S, so it's replaced by "eee". 
"ec" doesn't starts at index 2 in the original S, so we do nothing.
*/

class Solution {
    public String findReplaceString(String S, int[] indexes, String[] sources, String[] targets) {
        List<int[]> list = new ArrayList();
        for (int i = 0; i < indexes.length; i++)
            list.add(new int[] {i, indexes[i]});
        Collections.sort(list, (a, b) -> Integer.compare(a[1], b[1]));
        
        StringBuilder sb = new StringBuilder();
        int i = 0, j = 0;
        while (i < S.length())
        {
            if (j >= sources.length || i < list.get(j)[1]) sb.append(S.charAt(i++));
            else {
                int index = list.get(j)[0];
                boolean match = true;
                for (int k = 0; k < sources[index].length(); k++) {
                    if (i+k >= S.length() || S.charAt(i+k) != sources[index].charAt(k)) {
                        match = false;
                        break;
                    }
                }
                
                if (match) {
                    sb.append(targets[index]);
                    i += sources[index].length();
                }
                j++;
            }
        }
        return sb.toString();
    }
}
