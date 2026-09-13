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
    struct Status
    {
        long long max = LLONG_MIN;
        long long min = LLONG_MAX;
        bool isBST = true;
    };
    Status isBST(TreeNode* root)
    {
        if(!root) return Status();
        Status s1 = isBST(root->left), s2 = isBST(root->right);
        Status result(max(s2.max,(long long)root->val),min(s1.min,(long long)root->val),s1.isBST && s2.isBST && s1.max<root->val&&s2.min>root->val);
        return result;
    }
public:
    bool isValidBST(TreeNode* root) {
        return isBST(root).isBST;
    }
};