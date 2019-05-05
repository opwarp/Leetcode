// 279. Perfect Squares.cpp
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, 0);
        for(int i=1; i<=n; i++){
            int r=1, min = INT_MAX;
            while(r*r <= i){
                if(dp[i - r*r] < min) min = dp[i - r*r];
                r++;
            }
            dp[i] = min+1;
        }
        // for(int i=0; i<n; i++) cout<<i<<" i_dpi "<<dp[i]<<endl;
        return dp[n];
        
    }
};