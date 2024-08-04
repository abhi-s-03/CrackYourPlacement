class Solution
{
    public:
    //Function to find the largest number after k swaps.
    void helper(string &str,string &ans, int k,int i){
        if(k==0 || i==str.size()){
            ans=max(str,ans);
            return;
        }
        
        for(int j=i+1;j<str.length();j++){
            if(str[i]<str[j]){
                swap(str[i],str[j]);
                helper(str,ans,k-1,i+1);
                swap(str[i],str[j]);
            }
        }
        helper(str,ans,k,i+1);
        
    }
    string findMaximumNum(string str, int k)
    {
       // code here.
       string ans=str;
       helper(str,ans,k,0);
       return ans;
    }
};