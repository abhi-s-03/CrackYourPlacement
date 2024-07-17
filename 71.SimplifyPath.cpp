class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string ans="";
        int n=path.size();

        for(int i=0;i<n;++i){
            while(i<n && path[i]=='/') ++i;
            
            string temp;
            while(i<n && path[i]!='/'){
                temp+=path[i];
                ++i;
            }

            if(temp==".."){
                if(!st.empty()) st.pop();
            } 
            else if(temp!="." && temp != "") st.push(temp);
        }

        while(!st.empty()){
            ans="/"+st.top()+ans;
            st.pop();
        }

        if(ans=="") return "/";
        return ans;
    }
};