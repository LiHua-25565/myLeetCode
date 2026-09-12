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
    bool _isSymetric(TreeNode* l, TreeNode* r)
    {
        if(!l) return !r? true : false;
        else if(!r) return false;
        if(l->val!=r->val) return false;
        return _isSymetric(l->left,r->right) && _isSymetric(l->right, r->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return _isSymetric(root->left,root->right);
    }
};