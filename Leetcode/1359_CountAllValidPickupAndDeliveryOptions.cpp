class Solution {
private:
    int MOD = 1e9 + 7;
    long totalWays(int unpicked, int undelivered, vector<vector<int>> &dp){
        if(unpicked == 0 && undelivered == 0){
            return 1;
        }
        if(unpicked < 0 || undelivered < 0 || undelivered < unpicked){
            return 0;
        }
        if(dp[unpicked][undelivered] != 0){
            return dp[unpicked][undelivered];
        }
        
        long ans=0;
        ans += unpicked * totalWays(unpicked-1, undelivered, dp);
        ans %= MOD;
        
        ans += (undelivered - unpicked) * totalWays(unpicked, undelivered-1, dp);
        ans %= MOD;
        
        return dp[unpicked][undelivered] = ans;
    }
public:
    int countOrders(int n) {
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        return totalWays(n, n, dp);    
    }
};
