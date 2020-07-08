class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<double, vector<double>, less<double>> MaxHeap;
    priority_queue<double, vector<double>, greater<double>> MinHeap;
    MedianFinder() {
    }
    
    void addNum(int num) {
        int n = MaxHeap.size() + MinHeap.size();

        if ((n & 1) == 0) {
            MinHeap.push(num);
        } else {
            MaxHeap.push(num);
        }

        if (MaxHeap.size() && MinHeap.size()) {
            if (MaxHeap.top() > MinHeap.top()) {
                MinHeap.push(MaxHeap.top());
                MaxHeap.push(MinHeap.top());
                MaxHeap.pop();
                MinHeap.pop();
            }
        }
    }
    
    double findMedian() {
        if (MaxHeap.size() && MinHeap.size()) {
            int n = MaxHeap.size() + MinHeap.size();
            if ((n & 1) == 0) {
                return (MaxHeap.top() + MinHeap.top()) / 2;
            } else {
                if (MaxHeap.size() > MinHeap.size())
                    return MaxHeap.top();
                else
                    return MinHeap.top();
            }
        } else if (MaxHeap.size()) {
            return MaxHeap.top();
        } else if (MinHeap.size()) {
            return MinHeap.top();
        }
        return 0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */