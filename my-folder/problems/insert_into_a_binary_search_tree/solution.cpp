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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* cur = root;
        TreeNode* node = new TreeNode(val);
        if(root==NULL) return node;
        while(true){
            if(val < cur->val){
                if(cur->left==NULL) {
                    cur->left = node;
                    break;
                }
                cur = cur->left;
                
            }else{
                if(cur->right==NULL){
                    cur->right = node;
                     break;
                } 
                cur = cur->right;
              
            }
        }
        return root;
    }
};