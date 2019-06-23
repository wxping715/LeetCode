class Solution {
    // one pass implementation
    public int numUniqueEmails(String[] emails) {
        Set<String> set = new HashSet<>();
        for (String email : emails) {
            StringBuilder sb = new StringBuilder();
            boolean plus = false;
            for (int i = 0; i < email.length(); i++) {
                char ch = email.charAt(i);
                if (ch == '.');
                else if (ch == '+') plus = true;
                else if (ch == '@') {
                    sb.append(email.substring(i));
                    break;
                }
                else if (!plus) sb.append(ch);
            }
            set.add(sb.toString());
        }
        return set.size();
    }
}
