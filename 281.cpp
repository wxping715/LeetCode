/*Given two 1d vectors, implement an iterator to return their elements alternately.

For example, given two 1d vectors:

v1 = [1, 2]
v2 = [3, 4, 5, 6]
By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1, 3, 2, 4, 5, 6].

Follow up: What if you are given k 1d vectors? How well can your code be extended to such cases?

Clarification for the follow up question - Update (2015-09-18):
The "Zigzag" order is not clearly defined and is ambiguous for k > 2 cases. If "Zigzag" does not look right to you, replace "Zigzag" with "Cyclic". For example, given the following input:

[1,2,3]
[4,5,6,7]
[8,9]
It should return [1,4,8,2,5,9,3,6,7].
*/

class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        vec1 = v1;
        vec2 = v2;
        idx1 = 0;
        idx2 = 0;
        nvec = 1;
    }

    int next() {
        if (idx1 >= vec1.size()) return vec2[idx2++];
        if (idx2 >= vec2.size()) return vec1[idx1++];
        
        if (nvec == 1) {
            nvec = 2;
            return vec1[idx1++];
        } else {
            nvec = 1;
            return vec2[idx2++];
        }
    }

    bool hasNext() {
        return idx1 < vec1.size() || idx2 < vec2.size();
    }
private:
    vector<int> vec1, vec2;
    int idx1, idx2;
    int nvec = 1;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
