/*
A string S represents a list of words.

Each letter in the word has 1 or more options.  If there is one option, the letter is represented as is.  If there is more than one option, then curly braces delimit the options.  For example, "{a,b,c}" represents options ["a", "b", "c"].

For example, "{a,b,c}d{e,f}" represents the list ["ade", "adf", "bde", "bdf", "cde", "cdf"].

Return all words that can be formed in this manner, in lexicographical order.

 

Example 1:

Input: "{a,b}c{d,e}f"
Output: ["acdf","acef","bcdf","bcef"]
Example 2:

Input: "abcd"
Output: ["abcd"]
 
*/

class Solution {
    public String[] expand(String S) {
        List<List<Character>> letters = new ArrayList<>();
        
        TreeSet<Character> currentLetter = new TreeSet<>();
        boolean hasOption = false;
        for (int i = 0; i < S.length(); i++) {
            char ch = S.charAt(i);
            if (ch == '{' || ch == '}') {
                hasOption = ch == '{';
                if (!currentLetter.isEmpty()) {
                    letters.add(new ArrayList<>(currentLetter));
                    currentLetter.clear();
                }
            } else if (ch != ',') {
                currentLetter.add(ch);
                if (!hasOption) {
                    letters.add(new ArrayList<>(currentLetter));
                    currentLetter.clear();
                }
            }
        }
        
        List<String> strs = new ArrayList<>();
        generate(letters, new StringBuilder(), 0, strs);
        return strs.toArray(new String[0]);
    }
    
    void generate(List<List<Character>> letters, StringBuilder sb, int letterIndex, List<String> strs) {
        if (letterIndex >= letters.size()) {
            strs.add(sb.toString());
            return;
        }
        
        for (char ch : letters.get(letterIndex)) {
            sb.append(ch);
            generate(letters, sb, letterIndex+1, strs);
            sb.deleteCharAt(sb.length()-1);
        }
    }
}
