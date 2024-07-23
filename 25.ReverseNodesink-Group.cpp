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
    ListNode* reverse(ListNode* head){
        if(head->next==nullptr)
            return head;
        ListNode *newhead=reverse(head->next);
        ListNode *front=head->next;
        front->next=head;
        head->next=nullptr;
        return newhead;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1 || !head)
            return head;
        int i=k-1;
        ListNode *temp=head,*temphead,*nextn,*p=head;;
        temphead=head;
        while(i>0 && temp!=nullptr){
            temp=temp->next;
            i--;
        }
        if(i==0){
            nextn=temp->next;
            temp->next=nullptr;
            temp=nextn;
            head=reverse(temphead);
            temphead->next=temp;
            p=temphead;
        }
        while(temp!=nullptr){
            temphead=temp;
            i=k-1;
            while(i>0 && temp->next!=nullptr){
                temp=temp->next;
                i--;
            }
            if(i==0){
                nextn=temp->next;
                temp->next=nullptr;
                temp=nextn;
                p->next=reverse(temphead);
                temphead->next=temp;
                p=temphead;
            }
            else{
                break;
            }
        }
        return head;
    }
};