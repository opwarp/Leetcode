// 202. Happy Number.cpp
class Solution {
public:
    map<int, bool> recycling;
    bool isHappy(int n) {
        
        if (n == 1)
            return true;
        if(recycling.find(n) == recycling.end())
        {
            recycling[n] = true;
            // cout<<n<<endl;
           int sum = 0;
            while(n > 0){
                sum += pow(n % 10, 2);
                n = n / 10;
            }
            return isHappy(sum); 
        }
        else{
            return false;
        }
        
    }
};