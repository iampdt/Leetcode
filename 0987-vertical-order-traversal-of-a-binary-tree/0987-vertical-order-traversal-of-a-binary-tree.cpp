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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
       map<int, vector<pair<int, int>>> mp;
        vector<vector<int>> ans;
        queue<tuple<TreeNode*, int, int>> q;
         q.push({root,0,0});
         while(!q.empty())
         {
            auto[node,col,row] = q.front();
            q.pop();
            mp[col].push_back({row,node->val});
            if(node->left) q.push({node->left,col-1,row+1});
            if(node->right) q.push({node->right,col+1,row+1});

         }

    for(auto& [col,enteries] : mp)
    {
        vector<int> colValues;
        sort(enteries.begin(),enteries.end());
        for(auto& [row,val]:enteries)
        {
            colValues.push_back(val);
        }
        // sort(colValues.begin(),colValues.end());
        ans.push_back(colValues);
    }
    return ans;
    }
};