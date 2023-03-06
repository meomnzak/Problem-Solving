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
    vector<TreeNode *> vec;
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        solve(root);
        for(int i = 0 ; i<vec.size()-1 ; i++){
            if(vec[i] == p){
                return vec[i+1];
            }
        }
        return NULL;
    }
    void solve(TreeNode *root){
        if(root==NULL) return;
        solve(root->left);
        vec.push_back(root);
        solve(root->right);
    }
};