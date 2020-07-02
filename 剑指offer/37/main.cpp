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
    // 要注意一种输入
    //     1
    //      \
    //       2
    //      /
    //     3
    // 表示为[1,null,2,3] 而非[1,null,2,null,null,3]
    string serialize(TreeNode* root) {
        if (root == NULL) return "[]";

        queue<pair<TreeNode*, int>> Q;
        vector<int> arr;
        string ans = "";

        Q.push(make_pair(root, 1));

        while (!Q.empty()) {
            pair<TreeNode*, int> cur = Q.front(); Q.pop();
            TreeNode* root = cur.first;

            arr.push_back(root->val);

            if (root->val != INT_MAX) {
                if (root->left) Q.push(make_pair(root->left, cur.second + 1));
                else
                    Q.push(make_pair(new TreeNode(INT_MAX), cur.second + 1));

                if (root->right) Q.push(make_pair(root->right, cur.second + 1));
                else
                    Q.push(make_pair(new TreeNode(INT_MAX), cur.second + 1));
            }
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
        
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "[]") return NULL;

        vector<int> arr;
        
        // 将字符串转换成结点数组
        int s = 1, e = 0;
        
        while (e < data.length() -1) {
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

        queue<TreeNode*> Q;
        TreeNode* root = new TreeNode(arr[0]);

        Q.push(root);

        int i = 1, n = arr.size();
        
        while (!Q.empty()) {
            TreeNode* top = Q.front(); Q.pop();
            // left
            if (i + 1 <= n && arr[i] != INT_MAX) {
                TreeNode* node = new TreeNode(arr[i++]);
                top->left = node;
                Q.push(node);
            } else {
                i++;
            }
            // right
            if (i + 1 <= n && arr[i] != INT_MAX) {
                TreeNode* node = new TreeNode(arr[i++]);
                top->right = node;
                Q.push(node);
            } else {
                i++;
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));