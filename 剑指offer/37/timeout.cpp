/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) return "[]";

        int limit = getDeep(root);
        queue<pair<TreeNode*, int>> Q;
        vector<int> arr;
        string ans = "";

        Q.push(make_pair(root, 1));
        
        while (!Q.empty()) {
            pair<TreeNode*, int> cur = Q.front(); Q.pop();
            TreeNode* root = cur.first;

            arr.push_back(root->val);

            if (root->left) Q.push(make_pair(root->left, cur.second + 1));
            else
                if (cur.second + 1 <= limit) Q.push(make_pair(new TreeNode(INT_MAX), cur.second + 1));

            if (root->right) Q.push(make_pair(root->right, cur.second + 1));
            else
                if (cur.second + 1 <= limit) Q.push(make_pair(new TreeNode(INT_MAX), cur.second + 1));
        }

        // 去掉末尾的 null
        while (arr[arr.size() - 1] == INT_MAX) arr.pop_back();
        
        // 拼接字符串
        int n = arr.size();
        ans += "[";
        for (int i = 0; i < n; i++) {
            ans += arr[i] == INT_MAX ? "null" : to_string(arr[i]);
            if (i < n - 1) ans += ",";
        }
        ans += "]";
        //cout << ans << endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "[]") return NULL;

        // 去掉方括号
        data = data.substr(1, data.length() - 2);
        vector<int> arr;
        // 占位
        arr.push_back(INT_MAX);
        
        // 将字符串转换成结点数组
        int s = 0, e = 0;
        
        while (e < data.length()) {
            if (data[e] == ',') {
                string val = data.substr(s, e - s);
                arr.push_back(val == "null" ? INT_MAX : stoi(val));
                s = e + 1;
            }
            e++;
        }

        if (s < e) {
            string val = data.substr(s, e - s);
            arr.push_back(val == "null" ? INT_MAX : stoi(val));
        }

        //cout << arr.size() << endl;

        return constructTee(arr, 1);
    }

    int getDeep (TreeNode* root) {
        if (root == NULL) return 0;

        return max(getDeep(root->left), getDeep(root->right)) + 1; 
    }

    TreeNode* constructTee (vector<int> data, int index) {
        TreeNode* root = new TreeNode(data[index]);

        // 设置左子结点
        if (index * 2 < data.size() && data[index * 2] != INT_MAX)
            root->left = constructTee(data, index * 2);

        // 设置右子结点
        if (index * 2 + 1 < data.size() && data[index * 2 + 1] != INT_MAX)
            root->right = constructTee(data, index * 2 + 1);

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));