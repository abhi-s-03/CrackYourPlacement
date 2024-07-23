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
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
            return head;

        ListNode *slow=head,*fast=head->next;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *lhead=head,*rhead=slow->next;
        slow->next=nullptr;

        lhead=sortList(lhead);
        rhead=sortList(rhead);
        ListNode *dnode=new ListNode(-1);
        ListNode *temp=dnode;
        while(lhead!=nullptr && rhead!=nullptr){
            if(lhead->val>rhead->val){
                temp->next=rhead;
                temp=rhead;
                rhead=rhead->next;
            }
            else{
                temp->next=lhead;
                temp=lhead;
                lhead=lhead->next;
            }
        }
        if(lhead!=nullptr)
            temp->next=lhead;
        else
            temp->next=rhead;
        return dnode->next;
    }
};