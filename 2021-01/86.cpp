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
        // 思路：创建两个数组空间分别存放比 x 小的结点和比 x 大于等于的结点，最后链接起来。
        // 时间复杂度：O(n), 空间复杂度：O(n)
        if (head == NULL)
            return head;

        vector<ListNode *> a;
        vector<ListNode *> b;

        ListNode *node = head;

        while (node != NULL)
        {
            if (node->val < x)
                a.push_back(node);
            else
                b.push_back(node);

            ListNode *next = node->next;
            node->next = NULL;
            node = next;
        }

        ListNode *newHead = NULL;

        for (const auto &n : a)
        {
            if (newHead == NULL)
            {
                newHead = n;
                node = n;
            }
            else
            {
                node->next = n;
                node = node->next;
            }
        }
        for (const auto &n : b)
        {
            if (newHead == NULL)
            {
                newHead = n;
                node = n;
            }
            else
            {
                node->next = n;
                node = node->next;
            }
        }

        return newHead;
    }
};