class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0,n=nums.size();
        for(int i=0;i<(n+1)/2;i++){
            ans+=nums[n-i-1]-nums[i];
        }
        return ans;
    }
};