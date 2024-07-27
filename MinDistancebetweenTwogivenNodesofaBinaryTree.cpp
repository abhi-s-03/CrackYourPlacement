class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int found=0;
    int dist(Node* root, int a, int b,int d){
        if(!root) return 0;
        int l=dist(root->left,a,b,d+1);
        int r=dist(root->right,a,b,d+1);
        if(root->data==a || root->data ==b){
            found++;
            if(l || r)
                return l+r-d;
            return d;
        }
        if(l && r) return l+r-2*d;
        return l+r;
    }
    int findDist(Node* root, int a, int b) {
        int ans=dist(root,a,b,0);
        if(found==2) return ans;
        return 0;
    }
};