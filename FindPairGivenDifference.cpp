class Solution {
  public:
    int findPair(int n, int x, vector<int> &a) {
        sort(a.begin(),a.end());
        int i=0,j=1;
        while(i<n && j<n){
            int d=a[j]-a[i];
            if(d==x && i!=j) return 1;
            else if(d>x) i++;
            else j++;
        }
        return -1;
    }
};