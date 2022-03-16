
/*
Success
Runtime: 14 ms, faster than 15.61% of C++ online submissions for Symmetric Tree.
Memory Usage: 16.4 MB, less than 42.38% of C++ online submissions for Symmetric Tree.

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
    bool isSymmetric(TreeNode* root) {
        return check(root->left, root->right);
    }
    
    bool check(TreeNode* leftPart, TreeNode* rightPart) {
        if(!leftPart && !rightPart) return true;
        if(!leftPart || !rightPart) return false;
        if(leftPart->val != rightPart->val) return false;
        return check(leftPart->left, rightPart->right) && check(leftPart->right, rightPart->left);
    }
};