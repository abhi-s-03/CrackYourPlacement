class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int a=INT_MIN,b=INT_MIN,c=INT_MIN,d=INT_MAX,e=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>a){
                c=b;
                b=a;
                a=nums[i];
            } 
            else if(nums[i]>b){
                c=b;
                b=nums[i];
            } 
            else if(nums[i]>c) c=nums[i];

            if(d>nums[i]){
                e=d;
                d=nums[i];
            }
            else if(e>nums[i])
                e=nums[i];
        }
        return max(a*b*c,d*e*a);
    }
};