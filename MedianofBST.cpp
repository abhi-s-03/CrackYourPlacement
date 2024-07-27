/*
Structure of the binary Search Tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// your task is to complete the Function
// Function should return median of the BST
void inorder(Node* root, vector<int>& v) {
    if (root == NULL) {
        return;
    }
    
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

float findMedian(Node* root) {
    vector<int> v;
    inorder(root, v);
    
    int n = v.size();
    
    if (n % 2 == 1) 
        return v[n/2];
    else 
        return (v[n/2-1] + v[n/2]) / 2.0;
}