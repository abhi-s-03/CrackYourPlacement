class Solution {
public:
	bool isPossible(int n,int P, vector<pair<int, int> >& pre) {
	    vector<vector<int>>adj(n);
        for(auto p : pre){
            adj[p.first].push_back(p.second);
        }

        vector<int>indeg(n,0);
        for(int i=0;i<n;i++){
            for(auto x:adj[i]){
                indeg[x]++;
            }
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0)
                q.push(i);
        }

        vector<int>topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto x:adj[node]){
                indeg[x]--;
                if(indeg[x]==0)
                q.push(x);
            }
        }

        return topo.size()==n;
	}
};