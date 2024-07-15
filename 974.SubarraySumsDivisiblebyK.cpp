class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = 1; 
        int s = 0,r,c=0;
        for (int i = 0; i < nums.size(); i++) {
            s += nums[i];
            r=s % k;
            if(r<0)
                r+=k;
            c+=m[r];
            m[r]++;
        }
        return c;
    }
};