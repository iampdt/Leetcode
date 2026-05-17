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
    int computeSubtreeSum(TreeNode* root, unordered_map<TreeNode*, int>& subtreeSums) {
    if (!root) return 0;
    int leftSum = computeSubtreeSum(root->left, subtreeSums);
    int rightSum = computeSubtreeSum(root->right, subtreeSums);
    int totalSum = root->val + leftSum + rightSum;
    subtreeSums[root] = totalSum;
    return totalSum;
}

    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<TreeNode*, int> subtreeSums;
        int sum = computeSubtreeSum(root,subtreeSums);
        unordered_map<int,int> freq;
        int maxi = 0;
        vector<int> ans;
        for(auto it:subtreeSums) {freq[it.second]++; maxi=max(maxi,freq[it.second]);}
        for(auto it:freq) {if(it.second==maxi) ans.push_back(it.first);}

        return ans;

    }
};