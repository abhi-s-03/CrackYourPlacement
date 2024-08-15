class DisjointSet{
public:
    vector<int> parent,size;
    DisjointSet(int n){
        size.resize(n);
        parent.resize(n + 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int node){
        if(parent[node]==node) return node;
        return parent[node]=find(parent[node]);
    }

    void unionbysize(int u,int v){
        int ulp_u=find(u);
        int ulp_v=find(v);
        if(ulp_u == ulp_v) return ;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extra=0;
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            if(ds.find(u)==ds.find(v)) extra++;
            else ds.unionbysize(u,v);
        }

        int connected=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) connected++;
        }

        int ans=connected-1;
        if(extra>=ans) return ans;
        return -1;
    }
};