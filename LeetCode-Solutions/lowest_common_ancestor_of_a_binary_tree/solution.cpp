/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    TreeNode *p;
    TreeNode *q;
    TreeNode *ans;
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        this->p = p;
        this->q = q;
        LCA(root);
        return ans;
    }
    
    
    bool LCA(TreeNode *u){
        if(!u) return false;
        int left = LCA(u->left);
        int right = LCA(u->right);
        int mid = (u==p) || (u==q);
        
        if(left+right+mid>=2){
            ans = u;
        }
        
        return mid||left||right;
    }
};