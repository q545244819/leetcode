class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> ans;
        if (k == 0) return ans;
        int l = 0, r = arr.size() - 1, index = partition(arr, l, r);
        
        while (index != k - 1) {
            if (index > k - 1) {
                r = index - 1;
                index = partition(arr, l, r);
            } else {
                l = index + 1;
                index = partition(arr, l, r);
            }
        }

        for (int i = 0; i < k; i++) ans.push_back(arr[i]);
        return ans;
    }

    int partition (vector<int>& data, int l, int r) {
        int index = (l + r) / 2;
        int small = l;

        swap(data[index], data[r]);

        for (index = l; index < r; index++) {
            if (data[index] < data[r])
                swap(data[index], data[small++]);
        }

        swap(data[small], data[r]);

        return small;
    }
};