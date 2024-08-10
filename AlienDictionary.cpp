class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<vector<int>>adj(K);
        for(int i=1;i<N;i++){
            string s1=dict[i-1];
            string s2=dict[i];
            int len=min(s1.size(),s2.size());
            for(int j=0;j<len;j++){
                if(s1[j]!=s2[j]){
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }
        vector<int> indeg(K,0);
        string s="";
        queue<int>q;
        for(int i=0;i<K;i++){
            for(auto x:adj[i]){
                indeg[x]++;
            }
        }
        for(int i=0;i<K;i++){
            if(indeg[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            s+=char('a'+node);
            for(auto x:adj[node]){
                indeg[x]--;
                if(indeg[x]==0)
                    q.push(x);
            }
        }
        return s;
    }
};