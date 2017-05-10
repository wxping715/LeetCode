class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> hashset;
        for (int candy : candies) {
            hashset.insert(candy);
        }
        
        if (2*hashset.size() <= candies.size()) return hashset.size();
        return candies.size()/2;
    }
};
