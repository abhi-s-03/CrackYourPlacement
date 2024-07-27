// User function template in C++

/*

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;


// A utility function to create a new tree node
Node* newNode( int data )
{
    Node* temp = (Node *)malloc( sizeof( Node ) );
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

*/

class Solution {
  public:
    // Function that constructs BST from its preorder traversal.
    Node * solve(int pre[], int size,int min,int max,int &i){
        if(i==size || pre[i]<min || pre[i]>max) return NULL;
        Node* root=newNode(pre[i++]);
        root->left=solve(pre,size,min,root->data,i);
        root->right=solve(pre,size,root->data,max,i);
        return root;
    }
    Node* Bst(int pre[], int size) {
        // code here
        int i=0;
        Node * root=solve(pre,size,INT_MIN,INT_MAX,i);
        return root;
    }
};