/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        // 思路：bfs
        // 时间复杂度 O(n)，空间复杂度 O(n)
        if (root == NULL) {
            return NULL;
        }
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        Node* prev = NULL;
        int preLevel = 0;

        while (!q.empty()) {
            pair<Node*, int> front = q.front(); q.pop();
            Node* cur = front.first;
            if (prev != NULL && preLevel == front.second) {
                prev->next = cur;
            }
            if (cur->left != NULL)
                q.push({ cur->left, front.second + 1 });
            if (cur->right != NULL)
                q.push({ cur->right, front.second + 1 });

            prev = cur;
            preLevel = front.second;
        }

        return root;
    }
};