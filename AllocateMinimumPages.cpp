class Solution {
  public:
    // Function to find minimum number of pages.
    long long findPages(int n, int arr[], int m) {
        if(m>n) return -1;
        long long low=INT_MIN,high=0;
        for(int i=0;i<n;i++){
            if(low<arr[i]) low=arr[i];
            high+=arr[i];
        }
        long long mid;
        while(low<=high){
            mid=(low+high)/2;
            int s=1,p=0;
            for(int i=0;i<n;i++){
                if(p+arr[i]<=mid) p+=arr[i];
                else{
                    s++;
                    p=arr[i];
                }
            }
            if(s>m) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};