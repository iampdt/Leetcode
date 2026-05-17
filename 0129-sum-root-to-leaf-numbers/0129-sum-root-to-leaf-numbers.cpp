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
    void solve(TreeNode* root,vector<int> temp,vector<vector<int>>&res)
    {
        if(!root) return;
        temp.push_back(root->val);
        if(!root->left && !root->right) 
        { 
            res.push_back(temp);
            return;
        }
        solve(root->left,temp,res);
        solve(root->right,temp,res);

    }
    int sumNumbers(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> temp;
        int sum = 0;
        solve(root,temp,res);
        for(auto it:res)
        {
            int num = 0;
            for(int i=0;i<it.size();i++)
            {
               num = num*10 + it[i];
            }
            sum+=num;
        }
        return sum;

    }
};