class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int e,c=0;
        for(auto x:nums){
            if(c==0){
                e=x;
                c=1;
            }
            else if(e==x)
                c++;
            else
                c--;
        }
        return e;
    }
};