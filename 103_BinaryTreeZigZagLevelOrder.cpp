#include <vector>
#include <queue>
using namespace std;

/* 
Success
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
Memory Usage: 12.1 MB, less than 46.68% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.

#BinaryTree #BFS #Queue

*/


//Definition for a binary tree node.
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        q.push(root);
        while(!q.empty()) {
            int levelSize = q.size();
            vector<int> level(levelSize);
            for(int i = 0; i < levelSize; ++i) {
                auto& front = q.front();
                
                if(leftToRight) level[i] = front->val;
                else level[levelSize - 1 - i] = front->val;
                
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
                q.pop();
            }
            ans.push_back(level);
            leftToRight = !leftToRight;
        }
        return ans;
    }
private:
    queue<TreeNode*> q;
    bool leftToRight = true;
};