class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            if(i!=0 && nums[i]==nums[i-1]) continue;
            for(int l=i+1;l<n;l++){
                if(l!=i+1 && nums[l]==nums[l-1]) continue;
                int j=l+1;
                int k=n-1;
                while(j<k){
                    long long s = nums[i];
                    s += nums[j];
                    s += nums[k];
                    s += nums[l];
                    if(s==target){
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        j++;
                        k--;
                        while(j<k && nums[j]==nums[j-1])j++;
                        while(j<k && nums[k]==nums[k+1])k--;
                    }
                    else if(s>target)
                        k--;
                    else
                        j++;
                }
            }
        }
        return ans;
    }
};