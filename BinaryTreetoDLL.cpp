class Solution
{
    public: 
    Node*dll(vector<int> ans,int n){
        if(n==0) return nullptr;
        Node* head=new Node(ans[0]);
        Node* temp=head;
        for(int i=1;i<n;i++){
            Node* node=new Node(ans[i]);
            temp->right=node;
            node->left=temp;
            temp=temp->right;
        }
        return head;
    }
    
    void inorder(Node *root,vector<int>& ans){
        if (!root) return;
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
    }
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        // your code here
        vector<int> ans;
        inorder(root, ans);
        Node *head=dll(ans,ans.size());
        return head;
    }
};