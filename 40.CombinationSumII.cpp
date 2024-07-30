class Solution {
public:
    void helper(vector<int>& candidates, int target,vector<vector<int>> &ans,vector<int> &curr,int s,int index){
        if(s==target)
        {
            ans.push_back(curr);
            return;
        }
        if(s>target)
            return;
        for(int i=index+1;i<candidates.size();i++){
            if(i!= index+1 && candidates[i]==candidates[i-1])
                continue;
            curr.push_back(candidates[i]);
            helper(candidates,target,ans,curr,s+candidates[i],i);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(),candidates.end());
        for(int i=0;i<candidates.size();i++){
            if(i>0 && candidates[i]==candidates[i-1])
                continue;
            curr.push_back(candidates[i]);
            helper(candidates,target,ans,curr,candidates[i],i);
            curr.pop_back();
        }
        return ans;
    }
};