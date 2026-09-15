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
    unordered_map<long long,int> map;
    int _pathSum(TreeNode* root, int targetSum, long long pre)
    {
        if(!root) return 0;
        pre+=(long long)root->val;
        int ans = 0;
        if(map.find(pre-targetSum)!=map.end()) ans += map[pre-targetSum];
        map[pre]++;
        ans += _pathSum(root->left, targetSum, pre) + _pathSum(root->right, targetSum, pre);
        map[pre]--;
        return ans;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        map[0] = 1;
        return _pathSum(root, targetSum, 0);
    }
};