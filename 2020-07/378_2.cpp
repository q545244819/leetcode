class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> PQ;
        int n = matrix.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                PQ.push(matrix[i][j]);
                if (PQ.size() > k)  PQ.pop();
            }
        }

        return PQ.top();
    }
};