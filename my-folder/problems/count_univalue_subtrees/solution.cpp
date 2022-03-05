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
    int cnt = 0;
    int countUnivalSubtrees(TreeNode* root) {
        if(root==NULL) return 0;
        solve(root);
        return cnt;
    }
    
    int solve(TreeNode* root){
        if(root->left == NULL && root->right==NULL){
            cnt++;
            return root->val;
        } 
        
        int l = 1e6;
        int r = 1e6;
        if(root->left){
            l = solve(root->left);
        }
        if(root->right){
            r = solve(root->right);
        }
        
        if((l!=-1e6) && (r!=-1e6) && (l==1e6 || root->val==l) && (r==1e6 || root->val == r) ){
            cnt++;
            return root->val;
        }else{
            return -1e6;
        }
        
    }
};