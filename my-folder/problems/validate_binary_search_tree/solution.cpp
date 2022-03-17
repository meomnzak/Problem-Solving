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
    vector<int> vec;
    bool isValidBST(TreeNode* root) {
        solve(root);
        for(int i = 0 ; i<vec.size()-1 ; i++){
            if(vec[i]>=vec[i+1])
                return false;
        }
        return true;
    }
    
    void solve(TreeNode *u){
        if(u==NULL) return;
        solve(u->left);
        vec.push_back(u->val);
        solve(u->right);
    }
    
};