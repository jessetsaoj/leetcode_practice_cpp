#include <vector>
using namespace std;

/*
Success
Runtime: 35 ms, faster than 41.42% of C++ online submissions for Course Schedule.
Memory Usage: 13.8 MB, less than 61.40% of C++ online submissions for Course Schedule.

#DFS #TopologicalSort
#需複習
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph = vector<vector<int>>(numCourses);
        for(const auto& pre: prerequisites)
            graph[pre[1]].push_back(pre[0]);
        visitTable = vector<int>(numCourses, 0); //0: nothing, 1: visited, 2: visiting
        
        for(int i = 0; i < numCourses; ++i) 
            if(!dfs(i)) return false;
        return true;
    }
private:
    bool dfs(int pos) { // false => has cycle
        if(visitTable[pos] == 1) return true;
        if(visitTable[pos] == 2) return false;
        visitTable[pos] = 2;
        for(const auto& adj: graph[pos]) {
            if(!dfs(adj)) return false;
        }
        visitTable[pos] = 1;
        return true;
    }
    vector<vector<int>> graph;
    vector<int> visitTable;
};