class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int p,ans=0,b=prices[0];
        for(int i=1;i<prices.size();i++){
            p=prices[i]-b;
            if(p>ans){
                ans=p;
            }
            else if(p<0){
                b=prices[i];
            }
        }
        return ans;
    }
};