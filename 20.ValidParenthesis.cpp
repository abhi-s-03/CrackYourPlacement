class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char x:s){
            if(x=='(' || x=='{' || x=='[')
                st.push(x);
            else{
                if(st.empty())
                    return false;
                char t=st.top();
                if(x==')' && t=='(' ||  x=='}' && t=='{' || x==']' && t=='[')
                    st.pop();
                else
                    return false;
            }
        }
        return st.empty();
    }
};