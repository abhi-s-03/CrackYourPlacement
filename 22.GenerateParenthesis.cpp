class Solution {
public:
    void helper(vector<string> &ans,string s,int n,int o,int c){
        if(o+c==2*n){
            ans.push_back(s);
            return;
        }
        if(o==c){
            helper(ans,s+"(",n,o+1,c);
        }
        else{
            if(o==n){
            helper(ans,s+")",n,o,c+1);
            }
            else{
                helper(ans,s+"(",n,o+1,c);
                helper(ans,s+")",n,o,c+1);
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(ans,"(",n,1,0);
        return ans;
    }
};