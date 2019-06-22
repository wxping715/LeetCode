/*
In a forest, each rabbit has some color. Some subset of rabbits (possibly all of them) tell you how many other rabbits have the same color as them. Those answers are placed in an array.

Return the minimum number of rabbits that could be in the forest.

Examples:
Input: answers = [1, 1, 2]
Output: 5
Explanation:
The two rabbits that answered "1" could both be the same color, say red.
The rabbit than answered "2" can't be red or the answers would be inconsistent.
Say the rabbit that answered "2" was blue.
Then there should be 2 other blue rabbits in the forest that didn't answer into the array.
The smallest possible number of rabbits in the forest is therefore 5: 3 that answered plus 2 that didn't.

Input: answers = [10, 10, 10]
Output: 11

Input: answers = []
Output: 0

*/

class Solution {
    public int numRabbits(int[] answers) {
        Map<Integer, Integer> hashmap = new HashMap<>();
        for (int ans : answers) {
            int v = hashmap.getOrDefault(ans, 0);
            hashmap.put(ans, v+1);
        }
    
        int count = 0;
        for (Map.Entry<Integer, Integer> entry : hashmap.entrySet()) {
            int k = entry.getKey(), v = entry.getValue();
            count += ((v % (k+1) == 0 ? 0 : 1) + v / (k+1)) * (k+1);
        }
        return count;
    }
}
