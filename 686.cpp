/*
Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring of it. If no such solution, return -1.

For example, with A = "abcd" and B = "cdabcdab".

Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring of it; and B is not a substring of A repeated two times ("abcdabcd").

Note:
The length of A and B will be between 1 and 10000.
*/

class Solution {
public:
    
    // O(M*N)
    int repeatedStringMatch(string A, string B) {
        for (int i = 0; i < A.length(); i++) {
            int k = i, j = 0, t = 1;
            for (j = 0; j < B.length(); j++) {
                if (k == 0) t++;
                
                if (A[k++] != B[j]) break;
                if (k == A.length()) k = 0;
            }
            
            if (j >= B.length()) return (i == 0 ? t-1 : t);
        }
        return -1;
    }
    
    //O(M+N)
    // KMP
};
