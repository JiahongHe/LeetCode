class Solution {
    const vector<string> below20 =  {"Zero", "One", "Two", "Three", "Four","Five","Six","Seven","Eight","Nine","Ten", "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    const vector<string> below100 = {"Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string intToStr(int num) {
        if (num >= 1000000000) {
            int n = num / 1000000000;
            return  intToStr(n) + " Billion" + intToStr(num % 1000000000);
        }
        if (num >= 1000000) {
            int n = num / 1000000;
            string str = intToStr(n);
            return str + " Million" + intToStr(num % 1000000);
        }
        if (num >= 1000) {
            int n = num / 1000;
            string str = intToStr(n);
            return str + " Thousand" + intToStr(num % 1000);
        }
        if (num >= 100) {
            int n = num / 100;
            return " " + below20[n] + " Hundred" + intToStr(num % 100);
        }
        if (num >= 10) {
            int n = num / 10;
            if (n == 1) return " " + below20[num];
            return " " + below100[n] + intToStr(num % 10);
        }
        if (num >= 1) {
            return " " + below20[num];
        }
        return "";
    }
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string result = intToStr(num).substr(1);
        //cout << result;
        return result;
    }
};