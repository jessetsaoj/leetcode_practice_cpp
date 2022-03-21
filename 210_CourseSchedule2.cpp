#include <vector>
using namespace std;

/* 
Success
Runtime: 19 ms, faster than 91.08% of C++ online submissions for Course Schedule II.
Memory Usage: 14.2 MB, less than 47.51% of C++ online submissions for Course Schedule II.

#DFS #Recursive #TopologicalSort
*/

class Solution {
public:
    // return [] if cyclic
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        graph = vector<vector<int>>(numCourses);
        for(const auto& pre: prerequisites)
            graph[pre[0]].push_back(pre[1]); //  * 我自認挺聰明的一步:  原本top sort結果會是反的, 還需要使用reverse(),將消耗時間. 這裡直接把directed graph的edge全部反過來, 結果就是正的了.
        visitTable = vector<int>(numCourses, 0); //0: nothing, 1: visited, 2: visiting
        
        for(int i = 0; i < numCourses; ++i) {
            if(!dfs(i)) {
                topSorting = vector<int>();
                return topSorting;
            }
        }
        return topSorting;
    }
private:
    bool dfs(int pos) { //cyclic => return false
        if(visitTable[pos] == 2) return false;
        if(visitTable[pos] == 1) return true;
        visitTable[pos] = 2;
        for(const auto& adj: graph[pos])
            if(!dfs(adj)) return false;
        visitTable[pos] = 1;
        topSorting.push_back(pos);
        return true;
    }
    vector<vector<int>> graph;
    vector<int> visitTable;
    vector<int> topSorting;
};