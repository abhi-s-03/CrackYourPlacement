class Solution
{
    public:
    string smallestWindow (string s, string p)
    {
        vector<int> hash(26,0);
        for(auto x:p)
            hash[x-'a']++;
        int ind=-1,l=0,r=0,c=0,len=INT_MAX,n=p.size();
        while(r<s.size()){
            if(hash[s[r]-'a']>0) c++;
            hash[s[r]-'a']--;
            while(c==n){
                if(r-l+1<len){
                    len=r-l+1;
                    ind=l;
                }
                hash[s[l]-'a']++;
                if(hash[s[l]-'a']>0) c--;
                l++;
            }
            r++;
        }
        if(ind==-1) return "-1";
        return s.substr(ind,len);
    }
};