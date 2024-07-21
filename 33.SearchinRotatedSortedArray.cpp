class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l,h,m;
        l=0;
        h=nums.size()-1;
        while(l<=h)
        {
            m=(l+h)/2;
            if (nums[m]==target)
                return m;
            else if (nums[m]>target)
            {
                if(nums[l]>nums[m]||nums[l]<=target)
                 {
                     h=m-1;
                 }
                else
                {
                    l=m+1;
                }
            }
            else
            {
                 if(nums[l]<=nums[m]|| nums[l]>target)
                {
                    l=m+1;
                }
                else
                {
                    h=m-1;
                }
            }    
                
        }
        return -1;    
        
    }
};