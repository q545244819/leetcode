class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> memo;
        
        for (const int& i : nums) {
            if (memo.find(i) != memo.end())
                return true;
            memo.insert(i);
        }

        return false;
    }
};