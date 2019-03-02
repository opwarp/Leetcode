// 13. Roman to Integer.cpp
class Solution {
    map<char, int> value{{'0',0}, {'I', 1},{'V', 5},{'X', 10},{'L', 50},{'C', 100},{'D', 500},{'M', 1000}};

public:
    int romanToInt(string s) {
        int size = s.size();
        int sum = 0;
        int last = 0;
        for(int i=size-1; i>=0; i--){
            sum += value[s[i]] < last ?  -value[s[i]] : value[s[i]];
            last = value[s[i]];
        }
        return sum;
    }
};