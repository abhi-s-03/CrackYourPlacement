/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ta=headA,*tb=headB;
        if(ta==nullptr || tb==nullptr)
            return nullptr;
        while(ta!=nullptr && tb!=nullptr){
            ta=ta->next;
            tb=tb->next;
        }
        if(ta==nullptr)
            ta=headB;
        else
            tb=headA;
        while(ta!=nullptr && tb!=nullptr){
            ta=ta->next;
            tb=tb->next;
        }
        if(ta==nullptr)
            ta=headB;
        else
            tb=headA;
        while(ta!=nullptr){
            if(ta==tb)
                return ta;
            ta=ta->next;
            tb=tb->next;
        }
        return nullptr;
    }
};