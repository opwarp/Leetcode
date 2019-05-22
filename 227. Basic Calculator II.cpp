// 227. Basic Calculator II.cpp
class Solution {
public:
    int calculate(string s) {
       stringstream ss("+" + s);
        int last, num, sum=0;
        char op;
        while(ss>>op>>num){
            if(op == '+' || op == '-') {
                last = op == '+'? num : -num;
                sum += last;
            }else if(op == '*') {
                sum += (num*last-last);
                last = num*last;
            }else if(op == '/') {
                sum += (last/num-last);
                last = last/num;
            }
        }
        return sum;
    }
};