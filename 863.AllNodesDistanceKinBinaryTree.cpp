/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>p;
        queue<TreeNode*>q;
        TreeNode *c;
        q.push(root);
        while(!q.empty()){
            c=q.front();
            q.pop();
            if(c->left){
                p[c->left]=c;
                q.push(c->left);
            }
            if(c->right){
                p[c->right]=c;
                q.push(c->right);
            }
        }
        unordered_map<TreeNode*,bool>v;
        q.push(target);
        v[target]=true;
        int d=0;
        while(!q.empty()){
            int n=q.size();
            if(d==k) break;
            d++;
            for(int i=0;i<n;i++){
                c=q.front();
                q.pop();
                if(c->left && !v[c->left]){
                    q.push(c->left);
                    v[c->left]=true;
                }
                if(c->right && !v[c->right]){
                    q.push(c->right);
                    v[c->right]=true;
                }
                if(p[c] && !v[p[c]]){
                    q.push(p[c]);
                    v[p[c]]=true;
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};