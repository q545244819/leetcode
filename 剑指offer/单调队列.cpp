class MonotonicQueue {
    private: deque < int > data;
    public: void push(int n) {
        while (!data.empty() && data.back() < n)
            data.pop_back();
        data.push_back(n);
    }
    int max() {
        return data.front();
    }
    void pop(int n) {
        if (!data.empty() && data.front() == n)
            data.pop_front();
    }
};
