class Solution {
    public String shiftingLetters(String S, int[] shifts) {
        long sum = 0;
        StringBuilder sb = new StringBuilder();
        for (int i = shifts.length - 1; i >= 0; i--) {
            sum += shifts[i];
            sb.append((char)((S.charAt(i)-'a'+sum)%26 + 'a'));
        }
        sb.reverse();
        return sb.toString();
    }
}
