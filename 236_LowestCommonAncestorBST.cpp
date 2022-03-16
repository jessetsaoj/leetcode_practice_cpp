/* 
Success
Runtime: 30 ms, faster than 25.63% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
Memory Usage: 14.2 MB, less than 59.44% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.

#BinaryTree #DFS #Recursive 
#tricky
(此方法重點之一: 當某個node是目標node，另一目標node若不在他sibling為root的subtree之下，則此node就是解)
*/



// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};



class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;
        if(root == p || root == q) return root;
        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);
        
        if(left && right) return root;
        return left ? left:right;
        
    }
    
};