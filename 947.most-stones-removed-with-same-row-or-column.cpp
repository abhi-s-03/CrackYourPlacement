class DisjointSet{
public:
    vector<int> rank,parent;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int find(int node){
        if(node==parent[node]) return node;
        else return parent[node]=find(parent[node]);
    }

    void unionbyrank(int u,int v){
        int ulp_u=find(u);
        int ulp_v=find(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int row=0,col=0,n=stones.size();
        for(auto it:stones){
            row=max(row,it[0]);
            col=max(col,it[1]);
        }

        DisjointSet ds(row+col+1);

        for(auto it:stones){
            int nrow=it[0];
            int ncol=it[1]+row+1;
            ds.unionbyrank(nrow,ncol);
        }
        int k=0;
        for(int i=0;i<=(row+col+1);i++){
            if(ds.parent[i]==i && ds.rank[i]>=1)
                k++;
        }
        return n-k;
    }   
};