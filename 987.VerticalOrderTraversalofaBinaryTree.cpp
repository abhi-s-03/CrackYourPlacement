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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> n;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            root=p.first;
            int x=p.second.first,y=p.second.second;
            n[x][y].insert(root->val);
            if(root->left){
                q.push({root->left,{x-1,y+1}});
            }
            if(root->right){
                q.push({root->right,{x+1,y+1}});
            }
        }
        vector<vector<int>> ans;
        for(auto x:n){
            vector<int> l;
            for(auto y:x.second){
                l.insert(l.end(),y.second.begin(),y.second.end());
            }
            ans.push_back(l);
        }
        return ans;
    }
};