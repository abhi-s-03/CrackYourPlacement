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
    static int maxDepth(TreeNode* root,int &p) {
        if(root==nullptr) return 0;
        int lh=max(0,maxDepth(root->left,p));
        int rh =max(0,maxDepth(root->right,p));
        p=max(p,lh+rh+root->val);
        return root->val+max(lh,rh);
    }
    int maxPathSum(TreeNode* root) {
        int p=INT_MIN;
        maxDepth(root,p);
        return p;
    }
};