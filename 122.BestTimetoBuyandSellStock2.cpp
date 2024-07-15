class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0,p;
        for(int i=1;i<prices.size();i++){
            p=prices[i]-prices[i-1];
            if(p>0){
                ans+=p;
            }
        }
        return ans;
    }
};