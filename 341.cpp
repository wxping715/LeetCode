/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
// class NestedIterator {
// public:
    
//     NestedIterator(vector<NestedInteger> &nestedList) {
//         numbers = decode(nestedList);
//         idx = 0;
//     }
    
//     // dfs version
//     vector<int> decode(vector<NestedInteger> &nestedList) {
//         vector<int> res;
//         for (auto nint : nestedList) {
//             if (nint.isInteger()) res.push_back(nint.getInteger());
//             else {
//                 vector<int> t = decode(nint.getList());
//                 res.insert(res.end(), t.begin(), t.end());
//             }
//         }
//         return res;
//     }
    
//     int next() {
//         return numbers[idx++];
//     }

//     bool hasNext() {
//         return idx < numbers.size();
//     }
    
// private:
//     vector<int> numbers;
//     int idx;
    
// };

class NestedIterator {
public:
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (auto rit = nestedList.rbegin(); rit != nestedList.rend(); rit++) 
            s.push(*rit);
    }
    
    int next() {
        NestedInteger nint = s.top();
        s.pop();
        return nint.getInteger();
    }

    bool hasNext() {
        while (!s.empty()) {
            NestedInteger nint = s.top();
            
            if (nint.isInteger()) return true;
            vector<NestedInteger> nList = nint.getList();
            s.pop();
            for (auto rit = nList.rbegin(); rit != nList.rend(); rit++)
                s.push(*rit);
        }
        return false;
    }
    
private:
    stack<NestedInteger> s;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
