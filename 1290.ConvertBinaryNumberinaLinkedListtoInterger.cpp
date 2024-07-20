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
    int getDecimalValue(ListNode* head) {
        if(head==nullptr) return 0;
        ListNode* temp=head;
        int l=0;
        while(temp!=nullptr){
            l++;
            temp=temp->next;
        }
        int ans=0;
        temp=head;
        while(temp!=nullptr){
            if(temp->val==1) ans+=1<<l-1;
            temp=temp->next;
            l--;
        }
        return ans;
    }
};