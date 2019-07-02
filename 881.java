class Solution {
    public int numRescueBoats(int[] people, int limit) {
        Arrays.sort(people);
        int l = 0, r = people.length - 1;
        int count = 0;
        while (l <= r) {
            // handle the same one
            if (l < r && people[l] + people[r] <= limit) l++;
            r--;
            count++;
        }
        return count;
    }
}
