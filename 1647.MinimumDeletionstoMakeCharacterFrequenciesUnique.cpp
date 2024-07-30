class Solution {
public:
    int minDeletions(string s) {
        vector<int> c(26,0);
        for(auto x:s) c[x-'a']++;
        sort(c.begin(),c.end());
        int ans=0;
        for(int i=24;i>=0;i--){
            while(c[i] && c[i]>=c[i+1]){
                c[i]--;
                ans++;
            }
        }
        return ans;
    }
};