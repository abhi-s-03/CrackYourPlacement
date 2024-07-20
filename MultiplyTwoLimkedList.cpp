/* Linked list node structure
struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

/*The method multiplies
two  linked lists l1 and l2
and returns their product*/

/* Multiply contents of two linked lists */
class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        // code here
        long long mod = 1000000007;
        long long s1 =0;
        while(first != NULL){
            s1 = (s1*10)%mod+first->data;
            first = first ->next;
        }
        long long s2 = 0;
        while(second != NULL){
            s2 = (s2*10)%mod+second->data;
            second = second ->next;
        }
        return (s1*s2)%mod;
    }
};