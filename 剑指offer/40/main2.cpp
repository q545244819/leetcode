class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> ans;
        priority_queue<int> PQ;
        for (int i = 0; i < arr.size(); i++) PQ.push(-1 * arr[i]);
        for (int i = 0; i < k; i++) {
            ans.push_back(-1 * PQ.top());
            PQ.pop();
        }
        return ans;
    }
};