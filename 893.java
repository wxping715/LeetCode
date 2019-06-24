/*
You are given an array A of strings.

Two strings S and T are special-equivalent if after any number of moves, S == T.

A move consists of choosing two indices i and j with i % 2 == j % 2, and swapping S[i] with S[j].

Now, a group of special-equivalent strings from A is a non-empty subset S of A such that any string not in S is not special-equivalent with any string in S.

Return the number of groups of special-equivalent strings from A.


*/

class Solution {
    public int numSpecialEquivGroups(String[] A) {
        Set<String> set = new HashSet<>();
        for (String a : A) {
            char[] odd = new char[a.length()/2];
            char[] even = new char[a.length() - a.length()/2];
            for (int i = 0; i < a.length(); i++) {
                if (i % 2 == 1) odd[i/2] = a.charAt(i);
                else even[i/2] = a.charAt(i);
            }
            Arrays.sort(odd);
            Arrays.sort(even);
            set.add(new String(odd) + new String(even));
        }
        return set.size();
    }
}
