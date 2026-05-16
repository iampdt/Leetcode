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
        // iterative inorder
        int cnt = 0;
        stack<TreeNode*> stk;
        TreeNode* current = root;
        vector<int> result;
        while(current || !stk.empty())
        {
            while(current)
            {
                stk.push(current);
                current = current->left;
            }
            TreeNode* topNode = stk.top();
            stk.pop();
            result.push_back(topNode->val);
            if(topNode->right) current = topNode->right;

        }
       return result[k-1];
    }
};
// Inorder is sorted