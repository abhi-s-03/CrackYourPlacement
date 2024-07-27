/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* tree(vector<int>& pre,int prestart,int preend,vector<int>&post,int poststart,int postend){
        if(prestart>preend) return nullptr;
        TreeNode* root=new TreeNode(pre[prestart]);
        if(prestart == preend) return root;
        int left=pre[prestart+1];
        int i=poststart;
        while(i<=postend && post[i]!=left) i++;
        int l=i-poststart+1;

        root->left=tree(pre,prestart+1,prestart+l,post,poststart,i);
        root->right=tree(pre,prestart+l+1,preend,post,i+1,preend-1);
        return root; 
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n=preorder.size();
        return tree(preorder,0,n-1,postorder,0,n-1);
    }
};