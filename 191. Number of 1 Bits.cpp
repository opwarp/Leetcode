// 191. Number of 1 Bits.cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int mask = 1;
        int sum=0;
        while(n!=0){
            sum+=n & mask;
            n = n>>1;
        }
        return sum;
    }
};