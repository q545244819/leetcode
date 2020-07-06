class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> ans;
        if (k == 0) return ans;
        priority_queue<int> PQ;
        for (int i = 0; i < arr.size(); i++) {
            if (PQ.size() == k && PQ.top() > arr[i]) {
                PQ.pop();
                PQ.push(arr[i]);
            } else if (PQ.size() < k) {
                PQ.push(arr[i]);
            }
        }
        for (int i = 0; i < k; i++) {
            ans.push_back(PQ.top());
            PQ.pop();
        }
        return ans;
    }
};