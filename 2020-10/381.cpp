class RandomizedCollection {
public:
    vector<int> data;
    unordered_map<int, set<int>> memo;
    /** Initialize your data structure here. */
    RandomizedCollection() {
        // 思路：使用数组和哈希表作为数据存储，哈希表用于存储 val 在数组中的下标。
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        // 直接插入数组后，且在对应的哈希表 key 为 val 中插入新的下标值
        data.push_back(val);
        memo[val].insert(data.size() - 1);
        
        return memo[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        // 删除的思路是，先将需要删除的数交换到数组中最后的一个数，且删除该数在哈希表中的存储的下标值。然后弹出数组的最后一个元素（该操作实际删除 val），然后更新之前属于数组最后一个元素值在哈希表中存储的下标值
        if (memo.find(val) == memo.end())
            return false;
        
        int idx = (*memo[val].begin());
        data[idx] = data.back();
        memo[val].erase(idx);
        memo[data.back()].erase(data.size() - 1);

        if (idx < data.size() - 1)
            memo[data[idx]].insert(idx);
        if (memo[val].size() == 0)
            memo.erase(val);

        data.pop_back();

        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return data[rand() % data.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */