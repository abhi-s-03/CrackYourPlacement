class Solution {
public:
    int minCost(string s, vector<int>& t) {
        int ans=0,n=s.size();
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                int sum=t[i-1];
                int maxval=t[i-1];
                while(i<n && s[i]==s[i-1]){
                    sum+=t[i];
                    maxval=max(maxval,t[i]);
                    i++;
                }
                ans+=sum-maxval;
            }
        }
        return ans;
    }
};