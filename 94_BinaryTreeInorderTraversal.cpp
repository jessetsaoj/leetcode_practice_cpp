#include <vector>
using namespace std;

/*
Success
Runtime: 8 ms, faster than 8.21% of C++ online submissions for Binary Tree Inorder Traversal.
Memory Usage: 8.3 MB, less than 76.29% of C++ online submissions for Binary Tree Inorder Traversal.

#Recursion #BinaryTree 

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
    vector<int> inorder;
    vector<int> inorderTraversal(TreeNode* root) {
        traverse(root);
        return inorder;
    }
    void traverse(TreeNode* node) {
        if(node == nullptr) return;
        traverse(node->left);
        inorder.push_back(node->val);
        traverse(node->right);
    }
};