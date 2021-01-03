/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
  ListNode *partition(ListNode *head, int x)
  {
    if (head == NULL)
      return head;

    ListNode *newHead1 = NULL;
    ListNode *newHead2 = NULL;
    ListNode *p1 = NULL;
    ListNode *p2 = NULL;

    ListNode *node = head;

    while (node != NULL)
    {
      if (node->val < x)
      {
        if (p1 == NULL)
        {
          newHead1 = node;
          p1 = node;
        }
        else
        {
          p1->next = node;
          p1 = p1->next;
        }
      }
      else
      {
        if (p2 == NULL)
        {
          newHead2 = node;
          p2 = node;
        }
        else
        {
          p2->next = node;
          p2 = p2->next;
        }
      }

      ListNode *next = node->next;
      node->next = NULL;
      node = next;
    }

    if (p1 != NULL)
      p1->next = newHead2;

    return newHead1 != NULL ? newHead1 : newHead2;
  }
};