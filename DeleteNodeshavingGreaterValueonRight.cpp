struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
class Solution
{
    public:
    int val=0;
    Node *compute(Node *head)
    {
        if(head==nullptr) return head;
        Node* temp=compute(head->next);
        if(head->data>=val){
            head->next=temp;
            val=max(val,head->data);
            return head;
        }
        return temp;
        
    }
    
};