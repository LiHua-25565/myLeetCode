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
    int maxlen = 0;
    int _depth(TreeNode* node)
    {
        if(!node) return 0;
        int ldepth = _depth(node->left);
        int rdepth = _depth(node->right);
        maxlen = max(maxlen,ldepth+rdepth+1);
        return max(ldepth,rdepth) +1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        _depth(root);
        return maxlen-1;
    }
};