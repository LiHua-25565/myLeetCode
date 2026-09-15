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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        while(root)
        {
            stk.push(root);
            root = root->left;
        }
        int count = 0;
        while(!stk.empty())
        {
            TreeNode* cur = stk.top();
            stk.pop();
            if(++count == k) return cur->val;
            cur = cur->right;
            while(cur)
            {
                stk.push(cur);
                cur = cur->left;
            }
        }
        return -1;
    }
};