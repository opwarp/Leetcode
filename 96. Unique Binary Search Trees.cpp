// 96. Unique Binary Search Trees.cpp

class Solution {
public:
    int numTrees(int n) {
        vector <int> dp(n+1, 0);
        dp[0]=1;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=i; j++){
                dp[i] += ( dp[j-1] * dp[i-j] ); //left child tree num + right child tree num
                // cout<<i<<" "<<dp[i]<<endl;
            }
        }
        // for(int i=0; i<=n; i++){
        //     cout<<dp[i]<<endl;
        // }
        return dp[n];
    }
};