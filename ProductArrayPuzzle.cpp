class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
        long long int p=1;
        int c=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                c++;
            }
            else
                p*=nums[i];
        }
        vector<long long int> ans(n,0);
        if(c>1){
            return ans;
        }
        else if(c==1){
            for(int i=0;i<n;i++){
                if(nums[i]==0){
                    ans[i]=p;
                    break;
                } 
            
            }
        }
        else{
            for(int i=0;i<n;i++){
                ans[i]=p/nums[i];
            }
        }
        
        return ans;
    }
};
