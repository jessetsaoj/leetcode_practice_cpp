
/*
Success
Runtime: 20 ms, faster than 82.77% of C++ online submissions for Populating Next Right Pointers in Each Node.
Memory Usage: 16.8 MB, less than 86.08% of C++ online submissions for Populating Next Right Pointers in Each Node.

#BinaryTree #PerfectBinaryTree #Recursive #DFS
*/

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(!root || !root->left) return root;
        root->left->next = root->right;
        if(root->next)
            root->right->next = root->next->left;
        connect(root->left);
        connect(root->right);
        return root;
    }
};