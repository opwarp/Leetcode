// 12. Integer to Roman.cpp

class Solution {
public:
    string D2R(int d, string r1, string r5, string r10){
        string res;
        vector <string> roman(10);
        roman[0] = "";
        roman[1] = r1;
        roman[2] = r1 + r1;
        roman[3] = r1 + r1 + r1;
        roman[4] = r1 + r5;
        roman[5] = r5;
        roman[6] = r5 + r1;
        roman[7] = r5 + roman[2];
        roman[8] = r5 + roman[3];
        roman[9] = r1 + r10;
        return roman[d];
            
    }
    string intToRoman(int num) {
        string res;
        cout<<res<<endl;
        res = D2R(num%10, "I", "V", "X") + res;
        num = num / 10;
        res = D2R(num%10, "X", "L", "C") + res;
        num = num / 10;
        res = D2R(num%10, "C", "D", "M") + res;
        num = num / 10;
        res = D2R(num%10, "M", "*", "*") + res;
        return res;
    }
};

// better solution with greedy algorithm


class Solution {
public:
    string intToRoman(int num) {
        vector <pair<int, string>> v{{1000, "M"},
                                     {900,  "CM"},
                                     {500,  "D"},
                                     {400,  "CD"},
                                     {100,  "C"},
                                     {90,   "XC"},
                                     {50,   "L"},
                                     {40,   "XL"},
                                     {10,   "X"},
                                     {9,    "IX"},
                                     {5,    "V"},
                                     {4,    "IV"},
                                     {1,    "I"}};
        string str{""};
        for (auto i:v) {
            while (num >= i.first) {
                num -= i.first;
                str = str + i.second;
            }
        }
        return str;
    }
};