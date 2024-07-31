class Solution {
public:
    void helper(int n, int k,vector<vector<int>> &ans,vector<int>&temp,int index){
        if(k==0){
            ans.push_back(temp);
            return ;
        }
        for(int i=index;i<=n;i++){
            temp.push_back(i);
            helper(n,k-1,ans,temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int>temp;
        helper(n,k,ans,temp,1);
        return ans;
    }
};