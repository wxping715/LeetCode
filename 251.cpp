/*Implement an iterator to flatten a 2d vector.

For example,
Given 2d vector =

[
  [1,2],
  [3],
  [4,5,6]
]
By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,2,3,4,5,6].

Hint:

How many variables do you need to keep track?
Two variables is all you need. Try with x and y.
Beware of empty rows. It could be the first few rows.
To write correct code, think about the invariant to maintain. What is it?
The invariant is x and y must always point to a valid point in the 2d vector. Should you maintain your invariant ahead of time or right when you need it?
Not sure? Think about how you would implement hasNext(). Which is more complex?
Common logic in two different places should be refactored into a common method.
Follow up:
As an added challenge, try to code it using only iterators in C++ or iterators in Java.

Show Company Tags
Show Tags
Show Similar Problems
*/


class Vector2D {
public:
    Vector2D (vector<vector<int> >& vec2d) {
        data = vec2d;
        idxi = 0;
        idxj = 0;
    }

    int next() {
        return data[idxi][idxj++];
    }

    bool hasNext() {
        if (idxi >= data.size()) return false;
        while (idxi < data.size() && idxj >= data[idxi].size()) {
            idxj = 0;
            idxi++;
        }
        return idxi < data.size();
    }
private:
    int idxi;
    int idxj;
    vector<vector<int>> data;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
