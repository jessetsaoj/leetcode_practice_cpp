#include <vector>
#include <algorithm>

/* 
Result: Success
Runtime: 8 ms, faster than 94.15% of C++ online submissions for Longest Increasing Subsequence.
Memory Usage: 10.4 MB, less than 86.35% of C++ online submissions for Longest Increasing Subsequence.

Time Complexity: O(nlogn)
Space Complexity: O(n)

#DP #BinarySearch #Greedy #PatienceSorting
*/

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        std::vector<int> dpTable;
        for (const auto& num: nums) {
            auto it = std::lower_bound(dpTable.begin(), dpTable.end(), num);
            if(it != dpTable.end())
                *it = num;
            else 
                dpTable.push_back(num);
        }
        return dpTable.size();
    }
};