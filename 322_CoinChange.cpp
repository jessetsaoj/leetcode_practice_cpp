#include <vector>
using namespace std;

/*
Success
Runtime: 214 ms, faster than 15.93% of C++ online submissions for Coin Change.
Memory Usage: 14.4 MB, less than 65.35% of C++ online submissions for Coin Change.

Time Complexity: O(Amount*C)
Space Complexity: O(Amount)

#DP 
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for(int i = 1; i <= amount; ++i) {
            for (int j = 0; j < coins.size(); ++j) {
                if(coins[j] <= i)
                    dp[i] = min(dp[i], dp[i-coins[j]]+1);
            }
        }
        return dp.back() > amount ? -1 : dp.back();
    }
};