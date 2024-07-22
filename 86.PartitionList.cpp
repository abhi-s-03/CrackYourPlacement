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
    ListNode* partition(ListNode* head, int x) {
        if (!head) return nullptr;
        ListNode* lessDummy = new ListNode(0);
        ListNode* greaterDummy = new ListNode(0);
        ListNode* less = lessDummy;
        ListNode* greater = greaterDummy;

        ListNode* current = head;
        
        while (current) {
            if (current->val < x) {
                less->next = current;
                less = less->next;
            } else {
                greater->next = current;
                greater = greater->next;
            }
            current = current->next;
        }
        less->next = greaterDummy->next;
        greater->next = nullptr;
        return lessDummy->next;
    }
};