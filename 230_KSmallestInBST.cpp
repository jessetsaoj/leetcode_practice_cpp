
/*
Success
Runtime: 22 ms, faster than 66.53% of C++ online submissions for Kth Smallest Element in a BST.
Memory Usage: 24.1 MB, less than 87.80% of C++ online submissions for Kth Smallest Element in a BST.

#BinaryTree #BST #InorderTraversal #Recursion
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
    int ans = -1;
    int kthSmallest(TreeNode* root, int k) {
        int idx = 0;
        inorder(root, k, idx);
        return ans;
    }
    
    void inorder(TreeNode* node, const int& k,  int& idx) {
        if(node == nullptr) return ;
        inorder(node->left, k, idx);
        
        ++idx;
        if(idx == k) ans = node->val;
        
        inorder(node->right, k, idx);
    }
};