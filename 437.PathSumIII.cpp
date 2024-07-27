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
    void sumhelp(TreeNode* root, int target,int &ans,unordered_map<long long,int>&m,long long sum){
        if(!root) return ;
        sum+=root->val;
        if(sum==target) ans++;
        if(m.find(sum-target)!=m.end()) ans+=m[sum-target];
        m[sum]++;
        sumhelp(root->left,target,ans,m,sum);
        sumhelp(root->right,target,ans,m,sum);
        m[sum]--;
    }
    int pathSum(TreeNode* root, int target) {
        unordered_map<long long,int>m;
        int ans=0;
        sumhelp(root,target,ans,m,0);
        return ans;
    }
};