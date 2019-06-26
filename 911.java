/*
In an election, the i-th vote was cast for persons[i] at time times[i].

Now, we would like to implement the following query function: TopVotedCandidate.q(int t) will return the number of the person that was leading the election at time t.  

Votes cast at time t will count towards our query.  In the case of a tie, the most recent vote (among tied candidates) wins.

 

Example 1:

Input: ["TopVotedCandidate","q","q","q","q","q","q"], [[[0,1,1,0,0,1,0],[0,5,10,15,20,25,30]],[3],[12],[25],[15],[24],[8]]
Output: [null,0,1,1,0,0,1]
Explanation: 
At time 3, the votes are [0], and 0 is leading.
At time 12, the votes are [0,1,1], and 1 is leading.
At time 25, the votes are [0,1,1,0,0,1], and 1 is leading (as ties go to the most recent vote.)
This continues for 3 more queries at time 15, 24, and 8.
*/

class TopVotedCandidate {
    private int[] leading;
    private int[] times;
    
    public TopVotedCandidate(int[] persons, int[] times) {
        this.times = times;
        leading = new int[persons.length];
        Map<Integer, Integer> map = new HashMap<>();
        map.put(-1, 0);
        int leadingPerson = -1;
        for (int i = 0; i < persons.length; i++) {
            int v = map.getOrDefault(persons[i], 0);
            map.put(persons[i], v+1);
            if (v+1 >= map.get(leadingPerson))
                leadingPerson = persons[i];
            leading[i] = leadingPerson;
        }
    }
    
    public int q(int t) {
        // find upper bound - 1
        int l = 0, r = times.length - 1;
        while (l < r) {
            int m = (l + r)/2;
            if (times[m] <= t) l = m+1;
            else r = m;
        }
        if (l == 0) return 0;
        return times[l] > t ? leading[l-1] : leading[l];
    }
}

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */
