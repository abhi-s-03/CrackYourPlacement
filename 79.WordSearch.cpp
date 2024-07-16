class Solution {
public:
    bool helper(vector<vector<char>>& board, string &word,int i,int j,int k,int &n,int &m){
        if(k==word.length())
            return true;

        if(i<0 || j<0 || i==n || j==m || board[i][j]=='_' || board[i][j]!=word[k])
            return false;

        char c=board[i][j];
        board[i][j]='_';
        bool top=helper(board,word,i-1,j,k+1,n,m);
        bool right=helper(board,word,i,j+1,k+1,n,m);
        bool bottom=helper(board,word,i+1,j,k+1,n,m);
        bool left=helper(board,word,i,j-1,k+1,n,m);
        board[i][j]=c;

        return top||bottom||left||right;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0])
                    if(helper(board,word,i,j,0,n,m))
                        return true;
            }
        }
        return false;
    }
};