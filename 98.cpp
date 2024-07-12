#include <climits> // For INT_MIN and INT_MAX

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
    
    bool isValidBST(TreeNode* root, long long minVal, long long maxVal) {
        if (!root) return true; // An empty tree is a valid BST
        
        // Check current node's value against the range
        if (root->val <= minVal || root->val >= maxVal) return false;
        
        // Recursively check left and right subtrees
        return isValidBST(root->left, minVal, root->val) &&
               isValidBST(root->right, root->val, maxVal);
    }
};
