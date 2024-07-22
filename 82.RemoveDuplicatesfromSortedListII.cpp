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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy=new ListNode(0,head);
        ListNode* prev=dummy,*temp,*nextnode;
        while(head){
            nextnode=head->next;
            while(nextnode && head->val==nextnode->val){
                temp=nextnode->next;
                delete nextnode;
                nextnode=temp;
            }
            if(head->next==nextnode) prev=head;
            else{
                prev->next=nextnode;
                delete head;
            }
            head=nextnode;
        }
        return dummy->next;
    }
};