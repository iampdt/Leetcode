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
    int solve(TreeNode* root)
    {
        if(!root) return 0;
        int leftSubtreeHeight = solve(root->left);
        int rightSubtreeHeight = solve(root->right);
        if(leftSubtreeHeight == 0) return 1 + rightSubtreeHeight;
        else if(rightSubtreeHeight == 0) return 1 + leftSubtreeHeight;

        return 1 + min(leftSubtreeHeight,rightSubtreeHeight);

    }
    int minDepth(TreeNode* root) {
        return solve(root);
    }
};