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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        bool d=true;
        if(root==nullptr) return ans;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int>l(n);
            for(int i=0;i<n;i++){
                root=q.front();
                q.pop();
                if(d)
                    l[i]=root->val;
                else
                    l[n-i-1]=root->val;
                if(root->left!=nullptr)
                    q.push(root->left);
                if(root->right!=nullptr)
                    q.push(root->right);
            }
            ans.push_back(l);
            d=!d;
        }
        return ans;
    }
};