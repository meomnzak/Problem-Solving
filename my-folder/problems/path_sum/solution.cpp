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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        return hasPath(root,targetSum-root->val);
    }
    
     bool hasPath(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        if(root->left == NULL && root->right==NULL) return (targetSum==0);
        int lval = (root->left) ? targetSum-root->left->val : 0;
        int rval = (root->right) ? targetSum-root->right->val : 0;
        return hasPath(root->left,lval)||hasPath(root->right,rval);
    }
    
};