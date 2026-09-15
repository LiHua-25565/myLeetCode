/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* ans = nullptr;
    bool preorder(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(!root) return false;
        bool is_l = preorder(root->left, p, q), is_r = preorder(root->right, p , q);
        bool is_c = (root==p||root==q);
        if(is_l&&is_r) ans = root;
        else if((is_l||is_r)&&is_c)  ans = root;
        return is_c || is_l || is_r;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        preorder(root,p,q);
        return ans;
    }
};