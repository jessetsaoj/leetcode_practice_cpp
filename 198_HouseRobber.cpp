#include <vector>
using namespace std;


/* 
Result: Success
Runtime: 3 ms, faster than 53.02% of C++ online submissions for House Robber.
Memory Usage: 7.9 MB, less than 25.07% of C++ online submissions for House Robber.

Time Complexity: O(n)
Space Complexity: O(n)

#DP 

> dp table can be replaced by window sliding method to reach smaller space complexity
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);   // dp[i]: nums[0]...nums[i]中可獲得的max value
        for(int i = 0; i < nums.size(); ++i) {
            dp[i] = max( (i>1 ? dp[i-2] : 0) + nums[i], (i>0 ? dp[i-1] : 0));
        }
        return dp.back();
    }
};