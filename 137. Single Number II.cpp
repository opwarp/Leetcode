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

// There are so many brilliant solutions for this problem used "| & ^ ~", and I have learned a lot from these solutions. Here is a general solution for who not familiar with "| & ^ ~".

// Q: Most elements appeared k times, except one. Find this "one".

   int singleNumber(vector<int>& s) 
    {
        vector<int> t(32);////Made a array contain 32 elements.
        int sz = s.size();
        int i, j, n;
        for (i = 0; i < sz; ++i)
        {
            n = s[i];
            for (j = 31; j >= 0; --j)
            {
                t[j] += n & 1;//Find the last digit.
                n >>= 1;
                if (!n)
                    break;
            }
        }
    int res = 0;
    for (j = 31; j >= 0; --j)
    {
        n = t[j] % 3;//"3" represents k times. 
        if (n)
            res += 1 << (31 - j);
    }
    return res;
}