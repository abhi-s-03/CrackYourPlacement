class Solution {
public:
    int c=0;
    void merge(vector<int>& nums,int l,int mid,int h){
        int i=l,j=mid+1,k=0;
        vector<int> temp(h-l+1);

        for(i;i<=mid;i++){
            while(j<=h && nums[i]>2LL*nums[j])
                j++;
            c+=j-mid-1;
        }
        i=l,j=mid+1;
        while(i<=mid && j<=h){
            if(nums[i]<nums[j]){
                temp[k++]=nums[i++];
            }
            else{
                temp[k++]=nums[j++];
            }
        }

        while(i<=mid){
            temp[k++]=nums[i++];
        }

        while(j<=h){
            temp[k++]=nums[j++];
        }

        for(int i=l;i<=h;i++){
            nums[i]=temp[i-l];
        }
    }
    void mergesort(vector<int>& nums,int l,int h){
        if(l<h){
            int mid=(l+h)/2;
            mergesort(nums,l,mid);
            mergesort(nums,mid+1,h);
            merge(nums,l,mid,h);
        }
    }
    int reversePairs(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        return c;
    }
};