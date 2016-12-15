/*Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.

Please note that the string does not contain any non-printable characters.

Example:

Input: "Hello, my name is John"
Output: 5*/

class Solution {
public:
    int countSegments(string s) {
        int segment = 0, pre = -1;
        for (int i = 0; i < s.length(); i++) {
            while (i < s.length() && s[i] != ' ') i++;
            if (i-pre > 1) segment++;
            pre = i;
        }
        return segment;
    }
};
