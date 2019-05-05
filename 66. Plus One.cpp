// 66. Plus One.cpp

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int last = 1;
        for(int i=digits.size()-1; i>=0; i--){
            int nextDigits = (digits[i]+last) % 10;
            last = (digits[i]+last) / 10;
            digits[i] = nextDigits;
        }
        if(last>0){
           digits.insert(digits.begin(), last); 
        }
        return digits;
    }
};