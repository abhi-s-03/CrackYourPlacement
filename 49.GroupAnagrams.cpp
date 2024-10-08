class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>m;
        vector<vector<string>> ans;
        string s;
        for(int i=0;i<strs.size();i++){
            s=strs[i];
            sort(s.begin(),s.end());
            m[s].push_back(strs[i]);
        }
        for(auto x:m) ans.push_back(x.second);
        return ans;
    }
};