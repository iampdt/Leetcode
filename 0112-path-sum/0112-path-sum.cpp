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
    bool solve(TreeNode* root, int targetSum)
    {
       if(!root) return false;
        targetSum -= root->val;
        if (!root->left && !root->right) return targetSum == 0;
        bool left_res = solve(root->left,targetSum);
        bool right_res = solve(root->right,targetSum);

        return left_res || right_res;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        return solve(root,targetSum);
    }
};