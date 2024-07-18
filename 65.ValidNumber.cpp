class Solution {
public:
    bool isNumber(string s) {
        int i = 0, n = s.length();        
        if (s[i] == '+' || s[i] == '-') i++;
        
        bool isNumeric = false;
        bool isExponent = false;
        bool isDot = false;
        bool isSign = false;
        
        while (i < n ) {
            if (isdigit(s[i])) {
                isNumeric = true;
            } else if (s[i] == '.') {
                if (isDot || isExponent) return false;
                isDot = true;
            } else if (s[i] == 'e' || s[i] == 'E') {
                if (isExponent || !isNumeric) return false;
                isExponent = true;
                isNumeric = false; 
                isSign = false;
            }
            else if(s[i]=='+'||s[i]=='-'){
                if(!isExponent|| isNumeric) return false;
                isSign=true;
                isNumeric = false; 
            }
            else{
                return false;
            }
            i++;
        }
        if (!isNumeric) return false;        
        return i == n;
    }
};
