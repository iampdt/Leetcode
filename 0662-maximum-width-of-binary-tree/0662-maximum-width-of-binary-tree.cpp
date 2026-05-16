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
    int widthOfBinaryTree(TreeNode* root) {
        int max_width = 0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        while(!q.empty())
        {
            auto it = q.front();
            int sz = q.size();
            TreeNode* node = it.first;
            int leftpos = it.second;
            int rightpos = leftpos;
            for(int i=0;i<sz;i++)
            {
                auto[childnode,position] = q.front();
                q.pop();
                rightpos = position;
                int normalised = position - leftpos;
                if(childnode->left) q.push({childnode->left,1LL*2*normalised});
                if(childnode->right) q.push({childnode->right,1LL*2*normalised+1});
            }
            max_width = max(max_width,rightpos-leftpos+1);
        }
        return max_width;
    }
};