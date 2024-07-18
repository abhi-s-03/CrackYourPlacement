class Solution {
public:
    string minWindow(string s, string t) {
        int l=0,r=0,c=0,n=t.size(),si=-1,ml=INT_MAX;
        vector<int> m(125,0);
        for (char i:t)
            m[i]++;
        
        while (r<s.size()){
            if(m[s[r]]>0){
                c++;
            }
            m[s[r]]--;
            while (c==n){
                if(r-l+1<ml)
                {
                    si=l;
                    ml=r-l+1;
                }
                m[s[l]]++;
                if(m[s[l]]>0){
                    c--;
                }
                l++;
            }
            r++;
        }
        if(si==-1)
            return "";
        return s.substr(si,ml);
    }
};