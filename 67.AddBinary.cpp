class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int i=a.length()-1,j=b.length()-1,c=0,s;
        while(i>=0 || j>=0 || c){
            s=c;
            if(i>=0) s+=a[i--]-'0';
            if(j>=0) s+=b[j--]-'0';
            ans=char(s%2+'0') + ans;
            c=s/2;
        }
        return ans;
    }
};