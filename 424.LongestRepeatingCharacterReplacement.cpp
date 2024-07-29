class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> a;
        int front = 0;
        int end = 0;
        int count = 0;
        int res = 0;
        while (end < s.length()) {
            a[s[end]]++;
            count = max(count, a[s[end]]);
            if ((end - front + 1 - count) > k) {
                a[s[front]]--;
                front++;
            }
            res = max(res, end - front + 1);
            end++;
        }
        return res;  
    }
};