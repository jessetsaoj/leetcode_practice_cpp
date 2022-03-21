#include <vector>
using namespace std;

/* 
Success
Runtime: 16 ms, faster than 62.83% of C++ online submissions for Surrounded Regions.
Memory Usage: 10.1 MB, less than 40.57% of C++ online submissions for Surrounded Regions.

#DFS #Recursive
*/

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; ++i) { // left-most and right-most columns
            searchAlive(board, i, 0);
            searchAlive(board, i, n-1);
        }
        for(int j = 0; j < n; ++j) { // top and bottom rows
            searchAlive(board, 0, j);
            searchAlive(board, m-1, j);
        }
        // above code makes those alives 'A', and the captured remains 'O'
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[i].size(); ++j) {
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == 'A') board[i][j] = 'O';
            }
        }
    }
private:
    void searchAlive(vector<vector<char>>& board, const int& curR, const int& curC) { //DFS
        if(curR < 0 || curR >= board.size() || curC < 0 || curC >= board[curR].size() || board[curR][curC] != 'O')
            return;
        board[curR][curC] = 'A'; // 'A' for Alive
        //順序: 右下左上
        searchAlive(board, curR, curC+1);
        searchAlive(board, curR+1, curC);
        searchAlive(board, curR, curC-1);
        searchAlive(board, curR-1, curC);
    }
};