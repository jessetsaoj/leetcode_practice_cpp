#include <vector>
#include <cmath>
using namespace std;

/*
Success
Runtime: 377 ms, faster than 24.24% of C++ online submissions for Perfect Squares.
Memory Usage: 9.2 MB, less than 37.48% of C++ online submissions for Perfect Squares.

#DP 
*/
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1);
        for(int i = 0; i < dp.size(); ++i) {
            dp[0] = 0; dp[i] = i;
            for(int j = 1; j <= floor(sqrt(n)); ++j) {
                int square = j*j;
                if(square <= i)
                    dp[i] = min(dp[i], dp[i-square]+1);
            }   
        }
        return dp.back();
    }
};