class MedianFinder {
public:
    multiset<int> max_heap;
    multiset<int> min_heap;
    multiset<int>::iterator it;
    
    // Adds a number into the data structure.
    void addNum(int num) {
        it = min_heap.begin();
        int min_value = min_heap.size() > 0 ? (*it) : -0x3f3f3f3f;
        it = max_heap.begin();
        int max_value = max_heap.size() > 0 ? (*it) : 0x3f3f3f3f;
        
        if (num > min_value) min_heap.insert(num);
        else max_heap.insert(num);
        
        int v;
        if (min_heap.size() > max_heap.size() + 1) {
            v = *(min_heap.begin());
            min_heap.erase(min_heap.begin());
            max_heap.insert(v);
        } else if (max_heap.size() > min_heap.size() + 1) {
            v = *(max_heap.rbegin());
            max_heap.erase(--max_heap.end());
            min_heap.insert(v);
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (min_heap.size() == 0 && max_heap.size() == 0) return 0;
        else if (min_heap.size() < max_heap.size()) return *(max_heap.rbegin());
        else if (min_heap.size() > max_heap.size()) return *(min_heap.begin());
        else if (max_heap.size() == max_heap.size()) return (*(max_heap.rbegin()) + *(min_heap.begin()))/2.0;
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
