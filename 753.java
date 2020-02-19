/*
There is a box protected by a password. The password is a sequence of n digits where each digit can be one of the first k digits 0, 1, ..., k-1.

While entering a password, the last n digits entered will automatically be matched against the correct password.

For example, assuming the correct password is "345", if you type "012345", the box will open because the correct password matches the suffix of the entered password.

Return any password of minimum length that is guaranteed to open the box at some point of entering it.

 

Example 1:

Input: n = 1, k = 2
Output: "01"
Note: "10" will be accepted too.
Example 2:

Input: n = 2, k = 2
Output: "00110"
Note: "01100", "10011", "11001" will be accepted too.
*/

class Solution {
    public String crackSafe(int n, int k) {
        int totalSize = (int) Math.pow(k,n);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++)
            sb.append('0');
        Set<String> visited = new HashSet<>();
        visited.add(sb.toString());
        if (generate(sb, totalSize, n, k, visited))
            return sb.toString();
        return "";
    }
    
    private boolean generate(StringBuilder pwd, int size, int n, int k, Set<String> visited) {
        if (visited.size() == size)
            return true;
        String prefix = pwd.substring(pwd.length()-n+1, pwd.length());
        
        for (char c = '0'; c < '0' + k; c++) {
            String newPwd = prefix + c;
            if (!visited.contains(newPwd)) {
                pwd.append(c);
                visited.add(newPwd);
                if (generate(pwd, size, n, k, visited))
                    return true;
                visited.remove(newPwd);
                pwd.deleteCharAt(pwd.length()-1);
            }
        }
        return false;
    }
}
