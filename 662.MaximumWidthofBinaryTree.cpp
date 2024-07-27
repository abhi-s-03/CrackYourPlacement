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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        int ans=0;
        if(!root) return 0;
        q.push({root,0});
        while(!q.empty()){
            int n=q.size(),m=q.front().second,l;
            for(int i=0;i<n;i++){
                int id=q.front().second-m;
                root=q.front().first;
                q.pop();
                if(i==n-1) l=id;
                if(root->left) q.push({root->left,(long long)id*2+1});
                if(root->right) q.push({root->right,(long long)id*2+2});
            }
            ans=max(ans,l+1);
        }
        return ans;
    }
};