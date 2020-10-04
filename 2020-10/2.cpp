/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL && l2 == NULL)
            return NULL;
        else if (l1 == NULL)
            return l2;
        else if (l2 == NULL)
            return l1;
        
        ListNode* root = NULL;
        ListNode* node = NULL;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        int add = 0;

        while (p1 != NULL && p2 != NULL) {
            int val = p1->val + p2->val + add;
            ListNode* temp = new ListNode(val % 10);
            add = val >= 10 ? 1 : 0;
            
            if (root == NULL) {
                node = temp;
                root = node;
            } else {
                node->next = temp;
                node = node->next;
            }

            p1 = p1->next;
            p2 = p2->next;
        }

        while (p1 != NULL) {
            int val = p1->val + add;
            ListNode* temp = new ListNode(val % 10);
            add = val >= 10 ? 1 : 0;
            node->next = temp;
            node = node->next;
            p1 = p1->next;
        }
        while (p2 != NULL) {
            int val = p2->val + add;
            ListNode* temp = new ListNode(val % 10);
            add = val >= 10 ? 1 : 0;
            node->next = temp;
            node = node->next;
            p2 = p2->next;
        }
        if (add == 1) {
            node->next = new ListNode(1);
        }

        return root;
    }
};