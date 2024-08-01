class Solution {
public:
    void helper(vector<vector<int>> &ans, vector<int> &a, vector<int>& nums, int start) {
        ans.push_back(a);

        for (int i = start; i < nums.size(); i++) {
            a.push_back(nums[i]);
            helper(ans, a, nums, i + 1);
            a.pop_back(); 
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> a = {};
        helper(ans, a, nums, 0);
        return ans;
    }
};
