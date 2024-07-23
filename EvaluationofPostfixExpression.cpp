class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string s)
    {
       stack<int>st;
       for(int i=0;i<s.length();i++){
            if(isdigit(s[i]))
                st.push(s[i]-'0');
            else{
                int op2=st.top();
                st.pop();
                int op1=st.top();
                st.pop();
                if(s[i]=='+') st.push(op1+op2);
                else if(s[i]=='-') st.push(op1-op2);
                else if(s[i]=='*') st.push(op1*op2);
                else st.push(op1/op2);
            }
       }
       return st.top();
    }
};