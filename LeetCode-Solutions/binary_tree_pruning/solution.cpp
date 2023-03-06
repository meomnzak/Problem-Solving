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
    
    const static int N = 204;
    
    map<TreeNode *,bool> containOne;
    
    bool dfs(TreeNode* cur){
        bool one = cur->val;
        if(cur->left){
            one = dfs(cur->left) || one || cur->left->val ;
        }
        if(cur->right){
            one = dfs(cur->right) || one || cur->right->val ;
        }
        return containOne[cur] = one;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        dfs(root);
        if(containOne[root]==0) return NULL;
        prune(root);
        return root;
    }
    
    void prune(TreeNode *cur){
        if(!cur) return;
        if(containOne[cur->left]==0){
            cur->left = NULL;
        }
        if(containOne[cur->right]==0){
            cur->right = NULL;
        }
        prune(cur->left);
        prune(cur->right);
    }
    
};