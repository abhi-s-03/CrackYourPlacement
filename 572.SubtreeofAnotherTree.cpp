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
    bool helper2(TreeNode* root,TreeNode* node){
        if(!root && !node) return true;
        if(!root && node || root && !node || root->val!=node->val) return false;
        return helper2(root->left,node->left) && helper2(root->right,node->right);

    }
    bool helper(TreeNode* root,TreeNode*subroot){
        if(!root) return false;
        if(root->val==subroot->val){
            if(helper2(root,subroot)) return true;
        }        
        bool left=helper(root->left,subroot);
        if(left) return left;
        bool right=helper(root->right,subroot);
        return right==true;
    }
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        return helper(root,subroot);
    }
};