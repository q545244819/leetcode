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
        if (root == NULL)
            return NULL;
        queue<pair<Node*, int>> Q;
        Q.push(make_pair(root, 1));
        int prevLevel = 0;
        Node* prevNode = NULL;

        while (!Q.empty()) {
            pair<Node*, int> front = Q.front(); Q.pop();
            
            if (prevLevel == front.second)
                prevNode->next = front.first;
            prevLevel = front.second;
            prevNode = front.first;

            if (front.first->left != NULL)
                Q.push(make_pair(front.first->left, front.second + 1));
            if (front.first->right != NULL)
                Q.push(make_pair(front.first->right, front.second + 1));
        }

        return root;
    }
};