class Solution {
public:

    unordered_map<unsigned int, bool> cached;
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= maxChoosableInteger) return true;
        
        int sum = (maxChoosableInteger+1)*maxChoosableInteger/2;
        if (desiredTotal > sum || desiredTotal < 0) return false;
        
        unsigned int visited = (1 << maxChoosableInteger) - 1;
        return canIWin(visited, desiredTotal, maxChoosableInteger);
    }
    
    bool canIWin(unsigned int visited, int d, int mint) {
        if (cached.count(visited)) return cached[visited];
        
        if ((d <= mint) && (visited >= (1 << (d-1)))) {
            cached[visited] = true;
            return true;
        }
      
        int bit = 1;
        for (int i = 1; i <= mint; i++, bit <<= 1) {
            if (!(visited&bit)) continue;
            visited ^= bit;
            if (!canIWin(visited, d-i, mint)) {
                visited |= bit;
                cached[visited] = true;
                return true;
            }
            visited |= bit;
        }
        cached[visited] = false;
        return false;
    }
};
