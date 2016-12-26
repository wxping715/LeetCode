class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        nums.push_back(val);
        hash[val].insert(nums.size()-1);
        
        cout << nums.size() << endl;
        return hash[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (hash.count(val) == 0 || hash[val].empty()) return false;
        int ridx = *(hash[val].begin()), last = nums.back();
        
        if (val == last) {
            hash[last].erase(nums.size()-1);
            nums.pop_back();
        } else {
            hash[last].insert(ridx);
            hash[last].erase(nums.size()-1);
            hash[val].erase(ridx);
            nums[ridx] = last;
            nums.pop_back();
        }
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand()%nums.size()];
    }
private:
    unordered_map<int, unordered_set<int>> hash;
    vector<int> nums;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
