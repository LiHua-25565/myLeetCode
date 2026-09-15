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
    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int root_index, int l, int r)
    {
        if(l>=r) return nullptr;
        TreeNode* root = new TreeNode(preorder[root_index]);
        int mid = 0;
        for(int i = l; i < r; ++i)
        {
            if(root->val == inorder[i])
            {
                mid=i;
                break;
            }
        }
        root->left = _buildTree(preorder,inorder,root_index+1,l,mid);
        root->right = _buildTree(preorder,inorder,root_index+mid-l+1,mid+1,r);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0) return nullptr;
        return _buildTree(preorder,inorder,0,0,inorder.size());
    }
};