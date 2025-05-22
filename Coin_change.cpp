// created a 2d vector to save prev results
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1));

        for (int i = 1; i <= amount; i++) {
            dp[0][i] = INT_MAX - 10;
        }
        dp[0][0] = 0;

        for (int r = 1; r <= coins.size(); r++) {
            for (int c = 1; c <= amount; c++) {
                if (c < coins[r - 1]) {
                    dp[r][c] = dp[r - 1][c];
                } else {
                    dp[r][c] = min(dp[r - 1][c], 1 + dp[r][c - coins[r - 1]]);
                }
            }
        }
        if (dp[coins.size()][amount] == INT_MAX - 10)
            return -1;
        return dp[coins.size()][amount];
    }
};
