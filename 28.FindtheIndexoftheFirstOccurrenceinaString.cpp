class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=needle.size(),h=haystack.size();
        if(n>h) return -1;
        for(int i=0;i<=h-n;i++){
            if(haystack.substr(i,n)==needle)
                return i;
        }
        return -1;
    }
};