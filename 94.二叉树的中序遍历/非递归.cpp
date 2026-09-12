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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result; 
        stack<TreeNode*> stk;
        while(root)
        {
            stk.push(root);
            root = root->left;
        }
        while(!stk.empty())
        {
            auto temp = stk.top();
            result.push_back(temp->val);
            stk.pop();
            temp=temp->right;
            while(temp)
            {
                stk.push(temp);
                temp = temp->left;
            }
        }
        return result;
    }
};