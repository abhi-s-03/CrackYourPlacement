/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr)
            return head;
        unordered_map<Node*,Node*>m;
        Node* t1,*t2,*p,*nhead;
        t1=head;
        Node *node=new Node(t1->val);
        nhead=node;
        m[t1]=node;
        p=node;
        t1=t1->next;
        while(t1!=nullptr){
            Node *node=new Node(t1->val);
            m[t1]=node;
            p->next=node;
            p=node;
            t1=t1->next;
        }
        t1=head;
        t2=nhead;
        while(t1!=nullptr){
            if(t1->random!=nullptr)
                t2->random=m[t1->random] ;
            else
                t2->random=nullptr;
            t1=t1->next;
            t2=t2->next;          
        }
        return nhead;
    }
};