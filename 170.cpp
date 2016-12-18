/*Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

For example,
add(1); add(3); add(5);
find(4) -> true
find(7) -> false
*/

class TwoSum {
public:

    // Add the number to an internal data structure.
	void add(int number) {
	    hash.insert(number);
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
	    typedef std::multiset<int>::iterator It;
	    for (auto it : hash) {
	        if (2*it != value && hash.find(value-it) != hash.end()) return true; 
	        else if (2*it == value && hash.count(it) > 1) return true;
	    }
	    return false;
	}
	
private:
    unordered_multiset<int> hash;
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);
