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
    ListNode* reverse(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
            return head;

        ListNode *newhead=reverse(head->next);
        ListNode *f=head->next;
        f->next=head;
        head->next=nullptr;
        return newhead;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head,*fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast!=nullptr){
            slow=slow->next;
        }
        slow=reverse(slow);
        fast=head;
        while(slow!=nullptr && fast->val==slow->val)
        {
            slow=slow->next;
            fast=fast->next;
        }
        if(slow==nullptr)
            return true;
        return false;
    }
};