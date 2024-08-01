class Solution {
    string ele="";
public:
    void helper(vector<vector<string>>&ans,vector<string> &a,int idx,string s,int n){
        if(idx==n){
            ans.push_back(a);
            return;
        }
        for(int i=idx;i<n;i++){
            int start=idx,end=i,flag=0;
            while(start<=end){
                if(s[start++]!=s[end--]){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                a.push_back(s.substr(idx,i-idx+1));
                helper(ans,a,i+1,s,n);
                a.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> a;
        int n=s.length();
        helper(ans,a,0,s,n);
        return ans;
    }
};