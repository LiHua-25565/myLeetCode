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
    void flatten(TreeNode* root) {
        if(!root) return;
        stack<TreeNode*>  rstk;
        TreeNode* cur = root;
        while(cur || !rstk.empty())
        {
            if(cur->right) rstk.push(cur->right);
            cur->right = cur->left;
            cur->left = nullptr;
            if(!cur->right && !rstk.empty())
            {
                cur->right = rstk.top();
                rstk.pop();
            }
            cur = cur->right;
        }
    }
};