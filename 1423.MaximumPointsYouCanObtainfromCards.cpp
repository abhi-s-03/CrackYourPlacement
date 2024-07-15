class Solution {
public:
    int maxScore(vector<int>& cards, int k) {
        int s=0,i,ans,j=cards.size()-1;
        for(i=0;i<k;i++)
            s+=cards[i];       
        i--;
        ans=s;
        while(i>=0){
            s+=cards[j]-cards[i];
            ans=max(ans,s);
            j--;
            i--;
        }
        return ans;
    }
};