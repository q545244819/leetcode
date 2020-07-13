class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // 时间复杂度O(nums1.size() + nums2.size())
        // 空间复杂度(max(nums1.size(), nums2.size()))
        unordered_map<int, int> M;
        vector<int> ans;

        if (nums1.size() > nums2.size()) {
            for (int i = 0; i < nums2.size(); i++) M[nums2[i]]++;
            
            for (int i = 0; i < nums1.size(); i++)
                if (M[nums1[i]])
                    ans.push_back(nums1[i]), M[nums1[i]]--;
        } else {
            for (int i = 0; i < nums1.size(); i++) M[nums1[i]]++;
            for (int i = 0; i < nums2.size(); i++)
                if (M[nums2[i]])
                    ans.push_back(nums2[i]), M[nums2[i]]--;
        }

        return ans;
    }
};