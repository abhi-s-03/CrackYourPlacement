class Solution {
  public:
    void helper(vector<vector<int>> &ans,vector<int>& nums,int ind){
        if(ind==nums.size()){
            ans.push_back(nums);
            return;
        }

        unordered_set<int> s;

        for(int i=ind;i<nums.size();i++){
            if(s.find(nums[i])==s.end()){
                s.insert(nums[i]);
                swap(nums[i],nums[ind]);
                helper(ans,nums,ind+1);
                swap(nums[i],nums[ind]);
            }
        }
    }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        vector<vector<int>> ans;
        helper(ans,arr,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};