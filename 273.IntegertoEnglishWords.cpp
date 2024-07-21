class Solution {
public:
    string one(int num) {
        switch(num) {
            case 1: return "One";
            case 2: return "Two";
            case 3: return "Three";
            case 4: return "Four";
            case 5: return "Five";
            case 6: return "Six";
            case 7: return "Seven";
            case 8: return "Eight";
            case 9: return "Nine";
        }
        return "";
    }

    string twoLessThan20(int num) {
        switch(num) {
            case 10: return "Ten";
            case 11: return "Eleven";
            case 12: return "Twelve";
            case 13: return "Thirteen";
            case 14: return "Fourteen";
            case 15: return "Fifteen";
            case 16: return "Sixteen";
            case 17: return "Seventeen";
            case 18: return "Eighteen";
            case 19: return "Nineteen";
        }
        return "";
    }

    string ten(int num) {
        switch(num) {
            case 2: return "Twenty";
            case 3: return "Thirty";
            case 4: return "Forty";
            case 5: return "Fifty";
            case 6: return "Sixty";
            case 7: return "Seventy";
            case 8: return "Eighty";
            case 9: return "Ninety";
        }
        return "";
    }

    string two(int num){
        if(num == 0)
            return "";
        else if(num < 10)
            return one(num);
        else if(num < 20)
            return twoLessThan20(num);
        else{
            int t = num / 10;
            int r = num - t * 10;
            if(r != 0) return ten(t) + " " + one(r);
            return ten(t);
        }
    }

    string three(int num){
        int h = num / 100;
        int rest = num - h * 100;
        string res = "";
        if(h != 0) res = one(h) + " Hundred";
        if(rest!=0){
            if(res!="") res+=" ";
            res+=two(rest);
        }
        return res;
    }

    string numberToWords(int num) {
        if(num == 0) return "Zero";

        int b = num / 1000000000;
        int m = (num - b * 1000000000) / 1000000;
        int t = (num - b * 1000000000 - m * 1000000) / 1000;
        int rest = num - b * 1000000000 - m * 1000000 - t * 1000;

        string result = "";
        if(b != 0)
            result = three(b) + " Billion";
        if(m != 0){
            if(result != "") result += " ";
            result += three(m) + " Million";
        }
        if(t != 0){
            if(result != "") result += " ";
            result += three(t) + " Thousand";
        }
        if(rest != 0){
            if(result != "") result += " ";
            result += three(rest);
        }
        return result;
    }
};
