#include <vector>
#include <queue>
using namespace std;

/* 
Success
Runtime: 4 ms, 73.35%
Memory Usage: 12.4 MB, 85.34%

#BinaryTree #BFS #Queue
*/

// * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        q.push(root);
        while(!q.empty()) {
            int levelSize = q.size();
            ans.push_back({});
            for(int i = 0; i < levelSize; ++i) {
                auto front = q.front();
                ans.back().push_back(front->val);
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
                q.pop();
            }
            
        }
        return ans;
    }
private:
    queue<TreeNode*> q;   // 注意: queue的pop沒有回傳值
};