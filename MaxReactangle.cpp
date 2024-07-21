class Solution{
  public:
    int maxarea(int M[MAX],int m){
        stack<int>st;
        int ans=0,w;
        for(int i=0;i<=m;i++){
            while(!st.empty() && (i==m||M[st.top()]>=M[i])){
                int h=M[st.top()];
                st.pop();
                if(st.empty()) w=i;
                else w=i-st.top()-1;
                ans=max(ans,h*w);
            }
            st.push(i);
        }
        return ans;
    }
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int result = maxarea(M[0],m);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j]) M[i][j]+=M[i-1][j];
            }
            result=max(result,maxarea(M[i],m));
        }
        return result;
    }
};