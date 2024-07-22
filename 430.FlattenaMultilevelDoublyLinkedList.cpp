class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;
        
        Node* current = head;
        while (current) {
            if (current->child) {
                Node* next = current->next;
                Node* child = flatten(current->child);
                
                current->next = child;
                child->prev = current;
                current->child = nullptr;
                
                while (child->next) {
                    child = child->next;
                }
                
                child->next = next;
                if (next) next->prev = child;
            }
            current = current->next;
        }
        
        return head;
    }
};