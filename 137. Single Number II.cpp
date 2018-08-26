// 137. Single Number II.cpp

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int bit1 = 0;
        int bit2 = 0;
        for(int i=0; i<n; i++){
            
            bit1 = (bit1 ^ nums[i]) & (~bit2);
            bit2 = (bit2 ^ nums[i]) & (~bit1);
            
        }
        return bit1;
    }
};