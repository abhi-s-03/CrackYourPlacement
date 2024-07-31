class Solution {
public:
    void helper( vector<vector<int>> &ans,vector<int> &nums, vector<int> &a,int index,int n){
		ans.push_back(a);
        for(int i=index;i<n;i++){
            if(i>index && nums[i]==nums[i-1])
                continue;
            a.push_back(nums[i]);
            helper(ans,nums,a,i+1,n);
            a.pop_back();
        }    
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> a;
	    int n=nums.size();
	    ans.push_back({});
        sort(nums.begin(),nums.end());
	    for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1])
                continue;
            a.push_back(nums[i]);
		    helper(ans,nums,a,i+1,n);
            a.pop_back();
        }
	    return ans;	
    }
};