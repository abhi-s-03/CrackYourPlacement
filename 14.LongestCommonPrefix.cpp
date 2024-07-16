class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n1=strs.size()-1;
        sort(strs.begin(),strs.end());
        string ans="";
        int n=min(strs[0].length(),strs[n1].length());
        for(int i=0;i<n;i++){
            if(strs[0][i]==strs[n1][i])
                ans+=strs[0][i];
            else
                return ans;
        }
        return ans;
    }
};