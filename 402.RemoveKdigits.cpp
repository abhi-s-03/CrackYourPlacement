class Solution {
public:
    string removeKdigits(string num, int k) {
        stack <char> st;
        string ans="";
        st.push(num[0]);
        for(int i=1;i<num.length();i++){
            while(k>0 && !st.empty() && num[i]<st.top()){
                k--;
                st.pop();
            }
            if(st.empty() && num[i]=='0')
                continue;
            st.push(num[i]);
        }
        while(k>0 && !st.empty()){
            k--;
            st.pop();
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        if(ans=="")
            return "0";
        reverse(ans.begin(),ans.end());
        return ans;
    }
};