class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto x: flights){
            adj[x[0]].push_back({x[1],x[2]});
        }
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        vector<int>dis(n,1e9);
        dis[src]=0;

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stop=it.first;
            int node=it.second.first;
            int price=it.second.second;

            if(stop>k) continue;
            for(auto it:adj[node]){
                int adjnode=it.first;
                int nodep=it.second;
                if(price+nodep <dis[adjnode] && stop<=k){
                    dis[adjnode]=price+nodep;
                    q.push({stop+1,{adjnode,dis[adjnode]}});
                }
            }
        }


        if(dis[dst]==1e9) return -1;
        return dis[dst];
    }
};