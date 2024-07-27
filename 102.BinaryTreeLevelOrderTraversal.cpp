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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root==nullptr) return ans;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int>l;
            for(int i=0;i<n;i++){
                root=q.front();
                q.pop();
                l.push_back(root->val);
                if(root->left!=nullptr)
                    q.push(root->left);
                if(root->right!=nullptr)
                    q.push(root->right);
            }
            ans.push_back(l);
        }
        return ans;
    }
};