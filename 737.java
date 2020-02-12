/*
737. Sentence Similarity II

Given two sentences words1, words2 (each represented as an array of strings), and a list of similar word pairs pairs, determine if two sentences are similar.

For example, words1 = ["great", "acting", "skills"] and words2 = ["fine", "drama", "talent"] are similar, if the similar word pairs are pairs = [["great", "good"], ["fine", "good"], ["acting","drama"], ["skills","talent"]].

Note that the similarity relation is transitive. For example, if "great" and "good" are similar, and "fine" and "good" are similar, then "great" and "fine" are similar.

Similarity is also symmetric. For example, "great" and "fine" being similar is the same as "fine" and "great" being similar.

Also, a word is always similar with itself. For example, the sentences words1 = ["great"], words2 = ["great"], pairs = [] are similar, even though there are no specified similar word pairs.

Finally, sentences can only be similar if they have the same number of words. So a sentence like words1 = ["great"] can never be similar to words2 = ["doubleplus","good"].


*/

class Solution {
    public boolean areSentencesSimilarTwo(String[] words1, String[] words2, List<List<String>> pairs) {
        if (words1 == null || words2 == null)
            return false;
        if (words1.length != words2.length)
            return false;
        Map<String, String> parentMap = new HashMap<>();
        for (List<String> pair : pairs) {
            parentMap.putIfAbsent(pair.get(0), pair.get(0));
            parentMap.putIfAbsent(pair.get(1), pair.get(1));
            union(parentMap, pair.get(0), pair.get(1));
        }
        
        for (int i = 0; i < words1.length; i++) {
            if (!words1[i].equals(words2[i]) && !find(parentMap, words1[i]).equals(find(parentMap, words2[i])))
                return false;
        }
        return true;
    }
    
    private void union(Map<String, String> parentMap, String s1, String s2) {
        s1 = find(parentMap, s1);
        s2 = find(parentMap, s2);
        if (!s1.equals(s2)) {
            parentMap.put(s1, s2);
        }
    }
    
    private String find(Map<String, String> parentMap, String str) {
        if (!str.equals(parentMap.getOrDefault(str, str))) {
            parentMap.put(str, find(parentMap, parentMap.getOrDefault(str, str)));
        }
        return parentMap.getOrDefault(str, str);
    }
}
