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
    TreeNode* array_to_BST(vector<int>& nums, int l, int r)
    {
        if(r==l) return nullptr;
        if(r-l==1) return new TreeNode(nums[l]);
        int mid = (r+l)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = array_to_BST(nums,l,mid);
        root->right = array_to_BST(nums,mid+1,r);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return array_to_BST(nums,0,nums.size());
    }
};