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
    int result = INT_MIN;
    int _maxPathSum(TreeNode* root)
    {
        if(!root) return -1111;
        int l = _maxPathSum(root->left);
        int r = _maxPathSum(root->right);
        int v = root->val;
        result = max({result,l,r,l+r+v,l+v,r+v,v});
        return max({v,l+v,r+v});
    }
public:
    int maxPathSum(TreeNode* root) {
        _maxPathSum(root);
        return result;
    }
};