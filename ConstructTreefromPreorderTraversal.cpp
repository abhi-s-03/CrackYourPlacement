Node* build(int &i, int n, int pre[], char preLN[]){
    if(i==n) return nullptr;
    Node* node=new Node(pre[i]);
    if(preLN[i]=='L') return node;
    i++;
    node->left=build(i,n,pre,preLN);
    i++;
    node->right=build(i,n,pre,preLN);
    return node;
}
struct Node *constructTree(int n, int pre[], char preLN[])
{
    // Code here
    int i=0;
    Node *root= build(i,n,pre,preLN);
    return root ;
}