class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0){
            return 0;
        }

        int n = coins.size();
        vector<int>dp(amount+1,10001);
        dp[0] = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = coins[i] ; j <= amount ; j++){
                dp[j] = min(dp[j],dp[j - coins[i]] + 1);
            }
        }

        return (dp[amount] == 10001 ? -1 : dp[amount]);
    }
};
