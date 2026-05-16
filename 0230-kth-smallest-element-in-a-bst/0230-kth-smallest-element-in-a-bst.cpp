/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* curr = root;
        int result = -1; // To store the k-th smallest value
        
        while (curr != nullptr) {
            if (curr->left == nullptr) {
                // VISIT NODE
                k--;
                if (k == 0) result = curr->val;
                
                // Move to the right
                curr = curr->right;
            } else {
                // Find the inorder predecessor of current
                TreeNode* pre = curr->left;
                while (pre->right != nullptr && pre->right != curr) {
                    pre = pre->right;
                }
                
                if (pre->right == nullptr) {
                    // Create the thread and go left
                    pre->right = curr;
                    curr = curr->left;
                } else {
                    // The thread already exists, so we are done with the left subtree
                    // Restore the tree structure
                    pre->right = nullptr;
                    
                    // VISIT NODE
                    k--;
                    if (k == 0) result = curr->val;
                    
                    // Move to the right
                    curr = curr->right;
                }
            }
        }
        
        return result;
    }
};
// Inorder is sorted