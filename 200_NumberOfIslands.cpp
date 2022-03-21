#include <vector>
using namespace std;


/* 
Success
Runtime: 49 ms, faster than 50.90% of C++ online submissions for Number of Islands.
Memory Usage: 12.3 MB, less than 58.46% of C++ online submissions for Number of Islands.

Time Complexity: O(mn)

#DFS #Recursive 
- 與maze解法相似
- 亦可使用BFS
*/

class Solution {
public:
    int ans = 0;
    //順序: 右,下,左,上    / 1 island, 0 water, 2 traversed.
    int numIslands(vector<vector<char>>& grid) {
        for(int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ans += 1;
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<char>>&grid, const int& r, const int& c) {
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[r].size() || grid[r][c] != '1')
            return;
        //only '1' passed
        
        grid[r][c] = 2;
        dfs(grid, r, c+1);
        dfs(grid, r+1, c);
        dfs(grid, r, c-1);
        dfs(grid, r-1, c);
    }
};