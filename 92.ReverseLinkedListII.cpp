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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        stack<int>st;
        int i=0;
        ListNode* temp=head;
        while(temp!=nullptr){
            i++;
            if(i>=left && i<=right) st.push(temp->val);
            temp=temp->next;
        }
        temp=head;
        i=0;
        while(temp!=nullptr){
            i++;
            if(i>=left && i<=right){
                temp->val=st.top();
                st.pop();
            }
            temp=temp->next;
        }
        return head;
    }
};