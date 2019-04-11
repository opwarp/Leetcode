// 70. Climbing Stairs.cpp
class Solution {
public:
    
    // int climbStairs(int n) {
    //     if (n-1 == 0)
    //         return 1;
    //     else if(n-2 == 0)
    //         return 1 + climbStairs(n-1);
    //     else
    //         return climbStairs(n-1)+climbStairs(n-2);
    // }
    int climbStairs(int n) {
        int last2 = 1;
        if(n == 1)
            return last2;
        int last1 = 2;
        if(n == 2)
            return last1;
        int cur;
        for(int i=2; i<n; i++){
            cur = last2 + last1;
            last2 = last1;
            last1 = cur;
        }
        return cur;
    }
};