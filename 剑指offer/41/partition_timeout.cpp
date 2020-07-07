class MedianFinder {
public:
    /** initialize your data structure here. */
    vector<double> data;
    MedianFinder() {
    }
    
    void addNum(int num) {
        data.push_back(num);
    }
    
    double findMedian() {
        int n = data.size();
        double ans = 0;

        if ((n & 1) == 0) {
            int l = 0, r = n - 1, p1 = (n / 2) - 1, p2 = n / 2, index = partition(data, l, r);

            while (index != p1) {
                if (index > p1)
                    r = index - 1;
                else
                    l = index + 1;
                index = partition(data, l, r);
            }

            l = 0; r = n - 1; index = partition(data, l, r);

            while (index != p2) {
                if (index > p2)
                    r = index - 1;
                else
                    l = index + 1;
                index = partition(data, l, r);
            }
            //cout << data[p1] << " " << data[p2] << endl;
            ans = (data[p1] + data[p2]) / 2;
        } else {
            int l = 0, r = n - 1, mid = n / 2, index = partition(data, l, r);

            while (index != mid) {
                if (index > mid)
                    r = index - 1;
                else
                    l = index + 1;
                index = partition(data, l, r);
            }

            //cout << data[mid] << endl;
            ans = data[mid];
        }

        return ans;
    }

    int partition (vector<double>& data, int l, int r) {
        int index = l + (r - l) / 2;
        int small = l;

        swap(data[index], data[r]);

        for (index = l; index < r; index++)
            if (data[index] < data[r])
                swap(data[index], data[small++]);
        
        swap(data[small], data[r]);

        return small;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */