class Solution {
public:
    void moveZeroes(vector<int>& a) {
        int i,j=-1,n=a.size();
        for(i=0;i<n;i++){
            if(a[i]==0){
                j=i;
                break;
            }
        }

        if(j==-1) return ;

        for(i=j+1;i<n;i++)
        {
            if(a[i]!=0){
                swap(a[i],a[j]);
                j++;
            }
        }
    }
};