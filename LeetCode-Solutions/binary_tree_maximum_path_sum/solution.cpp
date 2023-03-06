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
    const int N = 3e4+7;

    int sol = -1e9;
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return sol;
    }
    
    int dfs(TreeNode *root){
        if(!root) return 0;
        int left = max(dfs(root->left),0);
        int right = max(dfs(root->right),0);
        sol = max(sol,root->val+left+right);
        return root->val + max(left,right);
    }
    
};