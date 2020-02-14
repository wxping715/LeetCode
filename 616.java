/*
Given a string s and a list of strings dict, you need to add a closed pair of bold tag <b> and </b> to wrap the substrings in s that exist in dict. If two such substrings overlap, you need to wrap them together by only one pair of closed bold tag. Also, if two substrings wrapped by bold tags are consecutive, you need to combine them.
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
*/

class Solution {
    public String addBoldTag(String s, String[] dict) {
        StringBuilder sb = new StringBuilder(); 
        int start = -1, end = -1;
        List<int[]> intervals = new ArrayList<>();
        for (int i = 0; i < s.length(); i++) {
            int lastIndex = -1;
            for (String word : dict)
                if (s.startsWith(word, i))
                    lastIndex = i + word.length() - 1;
            // interval [i, lastIndex] to merge
            if (lastIndex != -1) {
                // System.out.println(start + "," + end + "," + i + "," + lastIndex);
                if (start == -1) {
                    start = i;
                    end = lastIndex;
                } else {
                    // could merge
                    if (end >= i || end+1 == i) end = Math.max(end, lastIndex);
                    // can't merge
                    else {
                        // append 
                        intervals.add(new int[]{start, end});
                        start = i;
                        end = lastIndex;
                    }
                }
            }
        }
        if (start != -1) {
            intervals.add(new int[]{start, end});
        }
        // System.out.println("final ones");
        // for (int[] interval : intervals)
        //     System.out.println(interval[0] + "," + interval[1]);
        
        int lastEnd = -1;
        for (int[] interval : intervals) {
            sb.append(s.substring(lastEnd+1, interval[0]));
            sb.append("<b>");
            sb.append(s.substring(interval[0], interval[1]+1));
            sb.append("</b>");
            lastEnd = interval[1];
        }
        sb.append(s.substring(lastEnd+1, s.length()));
        return sb.toString();
    }
}
