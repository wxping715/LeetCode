/*Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

For example,
MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3*/

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        wsize = size;
        sum = 0;
    }
    
    double next(int val) {
        vals.push_back(val);
        sum += val;
        if (vals.size() > wsize)
            sum -= vals[vals.size()-wsize-1];
        int length = vals.size() > wsize ? wsize : vals.size();
        return sum*1.0/length;
    }
private:
    vector<int> vals;
    int wsize;
    int sum;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
