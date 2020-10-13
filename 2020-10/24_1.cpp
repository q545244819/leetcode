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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL)
            return NULL;

        ListNode* p1 = head;
        ListNode* p2 = head->next;

        if (p2 == NULL)
            return p1;

        ListNode* prev = NULL;
        ListNode* root = p2;

        while (p1 != NULL && p2 != NULL) {
            ListNode* temp = p2->next;
            p1->next = NULL;
            p2->next = p1;
            if (prev != NULL)
                prev->next = p2;
            prev = p1;
            p1 = temp;
            p2 = temp == NULL ? NULL : temp->next;
        }
        
        if (p1 != NULL)
            prev->next = p1;

        return root;
    }
};