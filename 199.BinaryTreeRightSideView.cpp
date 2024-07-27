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
    void right(TreeNode* root,vector<int> &ans,int l){
        if(root==nullptr) return ;
        if(l==ans.size()) ans.push_back(root->val);
        right(root->right,ans,l+1);
        right(root->left,ans,l+1);
    }
    vector<int> rightSideView(TreeNode* root) {
       vector<int> ans;
       right(root,ans,0);
       return ans;        
    }
};