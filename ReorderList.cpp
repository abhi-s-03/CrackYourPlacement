class Solution{ 
public:
    void reorderList(Node* head) {
        // Your code here
        Node*slow=head,*fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        Node* prev = nullptr;
        Node* curr = slow->next;
        while (curr) {
            Node* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        slow->next = nullptr; 
        
        Node* first = head;
        Node* second = prev;
        while (second) {
            Node* temp1 = first->next;
            Node* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};