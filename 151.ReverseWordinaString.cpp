class Solution {
public:
    string reverseWords(string s) {
        int l=s.size()-1,r;
        string ans="";
        while(l>=0){
            while(l>=0 && s[l]==' ') l--;
            r=l;
            while(l>=0 && s[l]!=' ') l--;
            if(ans.length()!=0 && l<r)
                ans+=" ";
            if(l<r)
                ans+=s.substr(l+1,r-l);
            l--;
            r=l;
        }
        return ans;
    }
};