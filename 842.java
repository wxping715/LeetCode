/*
842. Split Array into Fibonacci Sequence
Medium

259

88

Favorite

Share
Given a string S of digits, such as S = "123456579", we can split it into a Fibonacci-like sequence [123, 456, 579].

Formally, a Fibonacci-like sequence is a list F of non-negative integers such that:

0 <= F[i] <= 2^31 - 1, (that is, each integer fits a 32-bit signed integer type);
F.length >= 3;
and F[i] + F[i+1] = F[i+2] for all 0 <= i < F.length - 2.
Also, note that when splitting the string into pieces, each piece must not have extra leading zeroes, except if the piece is the number 0 itself.

Return any Fibonacci-like sequence split from S, or return [] if it cannot be done.

Example 1:

Input: "123456579"
Output: [123,456,579]
Example 2:

Input: "11235813"
Output: [1,1,2,3,5,8,13]
Example 3:

Input: "112358130"
Output: []
Explanation: The task is impossible.
Example 4:

Input: "0123"
Output: []
Explanation: Leading zeroes are not allowed, so "01", "2", "3" is not valid.
Example 5:

Input: "1101111"
Output: [110, 1, 111]
Explanation: The output [11, 0, 11, 11] would also be accepted.
*/

class Solution {
    public List<Integer> splitIntoFibonacci(String S) {
        long first = 0, second = 0;
        int maxLen = S.length()/2;
        for (int len1 = 1; len1 <= maxLen; len1++) {
            if (len1 > 1 && S.charAt(0) == '0') break;
            first = first * 10 + S.charAt(len1-1) - '0';
            if (first > Integer.MAX_VALUE) break;
            second = 0;
            for (int len2 = 1; len2 <= maxLen; len2++) {
                if (len2 > 1 && S.charAt(len1) == '0') break;
                second = second * 10 + S.charAt(len1 + len2 - 1) - '0';
                if (second > Integer.MAX_VALUE) break;
                
                List<Integer> ans = check(first, second, S, len1+len2);
                if (!ans.isEmpty()) return ans;
            }
        }
        return Collections.emptyList();
    }
    
    private List<Integer> check(long first, long second, String S, int thirdIndex) {
        List<Integer> list = new ArrayList<>();
        list.add((int)first); list.add((int)second);
        boolean valid = true;
        while (thirdIndex < S.length()) {
            long now = first + second;
            if (now > Integer.MAX_VALUE) {
                valid = false;
                break;
            }
            String nowString = String.valueOf(now);
            if (!S.startsWith(nowString, thirdIndex)) {
                valid = false;
                break;
            }
            list.add((int)now);
            first = second;
            second = now;
            thirdIndex += nowString.length();
        }
        
        if (!valid) return Collections.emptyList();
        else return list;
    }
}
