#include <iostream>
using namespace std;
/*
Success
Runtime: 18 ms, faster than 22.39% of C++ online submissions for Maximum Depth of Binary Tree.
Memory Usage: 18.8 MB, less than 89.57% of C++ online submissions for Maximum Depth of Binary Tree.


#DFS #BinaryTree

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
    int ans {0};
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        dfs(root, 1);
        return ans;
    }
    
    void dfs(const TreeNode* node, int depth) {
        ans = max(ans, depth);
        if(node->left != nullptr) {
            dfs(node->left, depth+1);
        }
        if(node->right != nullptr) {
            dfs(node->right, depth+1);
        }
    }
};

// a better solution 
class Solution2 {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int maxLeft = maxDepth(root->left);
        int maxRight = maxDepth(root->right);
        return max(maxLeft, maxRight)+1;
    }
};