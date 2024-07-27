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
    TreeNode* m1=nullptr,*m2=nullptr,*prev=new TreeNode(INT_MIN);
    void inorder(TreeNode* root){
        if(!root) return;

        inorder(root->left);
        if(root->val<prev->val){
            if(!m1) m1=prev;
            m2=root;
        }
        prev=root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(m1->val,m2->val);
    }
};