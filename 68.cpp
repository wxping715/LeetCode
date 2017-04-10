/*
每一行能place k个words, 计算k
k = 0
l = words[i+k].length k = 1

l + words[i+k]+1 <= length ok
else break




计算total spaces: maxWidth - length sum of k words
w1， w2 两种spaces
w2 = spaces/k-1 if k > 1 else 0
w1 = spaces, k = 1
     w2  spaces % k == 0
     w2+1  

n1 = 1  k = 1
     spaces - w2**(k-1)
n2 = k-1 - n1

j = 0, j <= k
j <= n1 时用w1, 否则用w2
*/


class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int i = 0, k = 0, l = 0;
        int w1, w2, n1, n2;
        while (i < words.size()) {
            l = words[i].length();
            k = 1;
            while (i+k < words.size() && l+words[i+k].length()+k <= maxWidth) {
                l += words[i+k].length();
                k++;
            }
            
            // assume has k words in this line
            if (i+k >= words.size()) {
                w1 = 1, n1 = k-1;
                w2 = 0, n2 = 0;
            } else {
                int spaces = maxWidth - l;
                w2 = k == 1 ? 0 : spaces/(k-1);
                w1 = k == 1 ? spaces : w2;
                if (k > 1 && spaces%(k-1) != 0) w1++;
                
                n1 = k == 1 ? 1 : spaces-w2*(k-1);
                n2 = k-n1;
            }
            
            // contact words
            string cur = words[i];
            for (int j = 1; j < k; j++) {
                if (j <= n1) cur += string(w1, ' ');
                else cur += string(w2, ' ');
                cur += words[i+j];
            }
            if (cur.length() < maxWidth) cur += string(maxWidth-cur.length(), ' ');
            
            res.push_back(cur);
            i += k;
        }
        
        return res;
    }
};
