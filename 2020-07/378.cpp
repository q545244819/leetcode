class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // 使用最小堆，时间复杂度 O(n^2)
        priority_queue<int> PQ;
        int n = matrix.size(), x = 0, y = 0;
        vector<vector<int>> book(n, vector<int>(n, 0));

        if (n == 0) return 0;
        if (k > n * n) return 0;
        
        while (x < n && y < n) {
            if (matrix[x][n - 1] < matrix[n - 1][y]) {
                for (int i = y; i < n; i++) {
                    if (!book[x][i]) {
                        book[x][i] = 1;
                        PQ.push(-1 * matrix[x][i]);
                    }
                }
                x += 1;
            } else {
                for (int i = x; i < n; i++) {
                    if (!book[i][y]) {
                        book[i][y] = 1;
                        PQ.push(-1 * matrix[i][y]);
                    }
                }
                y += 1;
            }
        }

        while (k > 1) {
            PQ.pop();
            k--;
        }
        
        return -1 * PQ.top();
    }
};