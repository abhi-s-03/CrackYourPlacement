class Solution {
public:
    void solve(int n,int &ans,vector<int>&p,int num){
        if(num>n){
            ans++;
            return;
        }
        for(int i=1;i<=n;i++){
            if(p[i]==0 &&(i%num==0 || num%i==0)){
                p[i]=num;
                solve(n,ans,p,num+1);
                p[i]=0;
            }
        }
    }
    int countArrangement(int n) {
        vector<int>p(n+1,0);
        int ans=0;
        solve(n,ans,p,1);
        return ans;
    }
};