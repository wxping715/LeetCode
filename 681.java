/*
Given a time represented in the format "HH:MM", form the next closest time by reusing the current digits. There is no limit on how many times a digit can be reused.

You may assume the given input string is always valid. For example, "01:34", "12:09" are all valid. "1:34", "12:9" are all invalid.

Example 1:

Input: "19:34"
Output: "19:39"
Explanation: The next closest time choosing from digits 1, 9, 3, 4, is 19:39, which occurs 5 minutes later.  It is not 19:33, because this occurs 23 hours and 59 minutes later.
Example 2:

Input: "23:59"
Output: "22:22"
Explanation: The next closest time choosing from digits 2, 3, 5, 9, is 22:22. It may be assumed that the returned time is next day's time since it is smaller than the input time numerically.
*/

class Solution {
    public String nextClosestTime(String time) {
        int[] digits = toDigits(time);
        int timeSeconds = (digits[0]*10+digits[1])*60 + (digits[2]*10+digits[3]);
        int maxSeconds = Integer.MAX_VALUE;
        int minSeconds = timeSeconds;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                for (int k = 0; k < 4; k++)
                    for (int z = 0; z < 4; z++) {
                        if (digits[i] > 2 || (digits[i] == 2 && digits[j] >= 4))
                            continue;
                        if (digits[k] >= 6) continue;
                        int seconds = (digits[i]*10+digits[j])*60 + (digits[k]*10+digits[z]);
                        // System.out.println(digits[i]+""+digits[j]+":"+digits[k]+""+digits[z]+" "+seconds);
                        if (seconds > timeSeconds)
                            maxSeconds = Math.min(seconds, maxSeconds);
                        minSeconds = Math.min(seconds, minSeconds);
                    }
        
        int seconds = maxSeconds != Integer.MAX_VALUE ? maxSeconds : minSeconds;
        
        StringBuilder sb = new StringBuilder();
        if (seconds/60 < 10)
            sb.append('0');
        sb.append(seconds/60);
        sb.append(":");
        if (seconds%60 < 10)
            sb.append('0');
        sb.append(seconds%60);
        return sb.toString();
    }
    
    private int[] toDigits(String time) {
        int[] digits = new int[4];
        int index = time.indexOf(':');
        
        if (index == 2) {
            digits[0] = time.charAt(0);
            digits[1] = time.charAt(1);
        } else digits[1] = time.charAt(0);
        
        if (time.length() - index - 1 == 2) {
            digits[2] = time.charAt(index+1);
            digits[3] = time.charAt(index+2);
        } else 
            digits[3] = time.charAt(index+1);
        
        for (int i = 0; i < 4; i++)
            digits[i] -= '0';
        return digits;
    }
}
