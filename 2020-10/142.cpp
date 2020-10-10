/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL)
            return NULL;
        if (head->next == NULL)
            return NULL;

        ListNode* p1 = head;
        ListNode* p2 = head->next ? head->next->next : head->next;

        while (p2 != NULL) {
            if (p1->next == p2) {
                ListNode* res = head;
                while (res != p2) {
                    res = res->next;
                    p2 = p2->next;
                }
                return res;
            }
            p1 = p1->next;
            p2 = p2->next ? p2->next->next : p2->next;
        }

        return NULL;
    }
};