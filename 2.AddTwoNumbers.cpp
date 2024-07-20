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
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *ta = l1, *tb = l2, *head = new ListNode(-1);
        ListNode *temp = head;
        int c = 0;
        while (ta != nullptr && tb != nullptr)
        {
            int s = ta->val + tb->val + c;
            ListNode *body = new ListNode();
            if (s >= 10)
            {
                body->val = s - 10;
                c = 1;
            }
            else
            {
                body->val = s;
                c = 0;
            }
            temp->next = body;
            temp = body;
            ta = ta->next;
            tb = tb->next;
        }
        while (ta != nullptr)
        {
            int s = ta->val + c;
            ListNode *body = new ListNode();
            if (s >= 10)
            {
                body->val = s - 10;
                c = 1;
            }
            else
            {
                body->val = s;
                c = 0;
            }
            temp->next = body;
            temp = body;
            ta = ta->next;
        }
        while (tb != nullptr)
        {
            int s = tb->val + c;
            ListNode *body = new ListNode();
            if (s >= 10)
            {
                body->val = s - 10;
                c = 1;
            }
            else
            {
                body->val = s;
                c = 0;
            }
            temp->next = body;
            temp = body;
            tb = tb->next;
        }
        if (c == 1)
        {
            ListNode *tail = new ListNode(1);
            temp->next = tail;
        }
        return head->next;
    }
};