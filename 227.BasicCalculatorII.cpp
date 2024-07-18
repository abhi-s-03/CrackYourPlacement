class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        char sign='+';
        int curr=0,n=s.length();
        for(int i=0;i<n;i++){
            if(isdigit(s[i]))
                curr=curr*10+(s[i]-'0');
            if(!isdigit(s[i]) && s[i]!=' ' || i==n-1){
                if(sign=='+')
                    st.push(curr);
                else if(sign=='-')
                    st.push(-curr);
                else if(sign=='*'){
                    int top=st.top();
                    st.pop();
                    st.push(top*curr);
                }
                else{
                    int top=st.top();
                    st.pop();
                    st.push(top/curr);
                }
                sign=s[i];
                curr=0;
            }
        }
        int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};