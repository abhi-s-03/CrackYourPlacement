class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int ans=0;
    vector<int> solve(Node* root){
        if(!root) return {0,INT_MAX,INT_MIN};
        vector<int> l=solve(root->left);
        vector<int> r=solve(root->right);
        if(l[0]>=0 && r[0]>=0 && root->data > l[2] && root->data < r[1]){
            int mi = min(l[1], root->data);
            int mx = max(r[2], root->data);
            ans = max(ans, l[0] + r[0] + 1);
            return {l[0] + r[0] + 1, mi, mx};
            
        }
        return {-1,-1,-1};
        
    }
    int largestBst(Node *root)
    {
    	//Your code here
    	solve(root);
        return ans;
    	
    }
};