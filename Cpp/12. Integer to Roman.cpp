class Solution {
    string intToRoman(int num, string s) {
        if (num >= 1000) {
            int n = num / 1000;
            string str = "";
            for (int i = 0; i < n; i++) str += "M";
            return intToRoman(num % 1000, s + str);
        }
        if (num >= 900) {
            s = s + "CM";
            return intToRoman(num - 900, s);
        }
        if (num >= 500) {
            s = s + "D";
            return intToRoman(num - 500, s);
        }
        if (num >= 400) {
            s = s + "CD";
            return intToRoman(num - 400, s);
        }
        if (num >= 100) {
            int n = num / 100;
            string str = "";
            for (int i = 0; i < n; i++) str += "C";
            return intToRoman(num % 100, s + str);
        }
        if (num >= 90) {
            s = s + "XC";
            return intToRoman(num - 90, s);
        }
        if (num >= 50) {
            s = s + "L";
            return intToRoman(num - 50, s);
        }
        if (num >= 40) {
            s = s + "XL";
            return intToRoman(num - 40, s);
        }
        if (num >= 10) {
            int n = num / 10;
            string str = "";
            for (int i = 0; i < n; i++) str += "X";
            return intToRoman(num % 10, s + str);
        }
        if (num >= 9) {
            s = s + "IX";
            return intToRoman(num - 9, s);
        }
        if (num >= 5) {
            s = s + "V";
            return intToRoman(num - 5, s);
        }
        if (num >= 4) {
            s = s + "IV";
            return intToRoman(num - 4, s);
        }
        if (num >= 1) {
            int n = num;
            string str = "";
            for (int i = 0; i < n; i++) str += "I";
            return s + str;
        }
        return s;
    }
public:
    string intToRoman(int num) {
        return intToRoman(num, "");
    }
};