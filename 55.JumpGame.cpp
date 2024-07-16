class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int goal=n-1,i=n-2;
        while(i>=0){
            if(nums[i]+i>=goal)
                goal=i;
            i--;
        }
        return goal==0;
    }
};