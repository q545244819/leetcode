/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        // 第一种方法的优化，使用 hashtable
        Node* root = NULL;
        Node* point = NULL;
        Node* temp = head;
        map<Node*, Node*> M;

        while (temp != NULL)  {
            Node* p = new Node(temp->val);

            if (root == NULL) {
                point = p;
                root = point;
            } else {
                point->next = p;
                point = point->next;
            }
            
            M[temp] = point;
            temp = temp->next;
        }

        temp = head;

        while (temp != NULL) {
            if (temp->random != NULL)
                M[temp]->random = M[temp->random];

            temp = temp->next;
        }

        return root;
    }
};