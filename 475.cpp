/*Winter is coming! Your first job during the contest is to design a standard heater with fixed warm radius to warm all the houses.

Now, you are given positions of houses and heaters on a horizontal line, find out minimum radius of heaters so that all houses could be covered by those heaters.

So, your input will be the positions of houses and heaters seperately, and your expected output will be the minimum radius standard of heaters.

Note:
Numbers of houses and heaters you are given are non-negative and will not exceed 25000.
Positions of houses and heaters you are given are non-negative and will not exceed 10^9.
As long as a house is in the heaters' warm radius range, it can be warmed.
All the heaters follow your radius standard and the warm radius will the same.
Example 1:
Input: [1,2,3],[2]
Output: 1
Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.
Example 2:
Input: [1,2,3,4],[1,4]
Output: 1
Explanation: The two heater was placed in the position 1 and 4. We need to use radius 1 standard, then all the houses can be warmed.*/

class Solution {
public:

    // two pointers
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        if (heaters.size() == 0 || houses.size() == 0) return 0;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        
        int p1 = 0, p2 = 0, res = 0;
        while (p1 < heaters.size() && heaters[p1] < houses[0]) p1++;
        p2 = p1;
        p1--;
        for (int house: houses) {
            while (p2 < heaters.size() && heaters[p2] < house) {
                p1 = p2;
                p2++;
            }
            
            int cur_res = 0;
            if (p1 < 0) cur_res = heaters[p2]-house;
            else if (p2 >= heaters.size()) cur_res = house - heaters[p1];
            else cur_res = min(heaters[p2]-house, house - heaters[p1]);
            res = max(res, cur_res);
        }
        return res;
    }
    
    // binary search
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        if (heaters.size() == 0 || houses.size() == 0) return 0;
        int res = 0;
        sort(heaters.begin(), heaters.end());
        for (int house: houses) {
            auto it = lower_bound(heaters.begin(), heaters.end(), house);
            
            int cur_res = 0;
            if (it == heaters.begin()) cur_res = *it - house;
            else {
                auto pre = prev(it);
                if (it == heaters.end()) cur_res = house - *pre;
                else cur_res = min(house - *pre, *it - house);
            }
            res = max(res, cur_res);
        }
        return res;
    }
};
