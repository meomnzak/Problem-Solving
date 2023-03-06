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
    const static int N = 103;
    int sz[N];
    int x;
    int l = 0,r = 0;
    int dfs(TreeNode *u){
        if(!u) return 0;
        if(u->val==x){
            if(u->left){
                l = u->left->val;
            }
            if(u->right){
                r = u->right->val;
            }
        }
        sz[u->val] = 1;
        sz[u->val]+=(dfs(u->left) + dfs(u->right));
        return sz[u->val];
    }
    
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        this->x = x;
        dfs(root);
        int rem = n - sz[x];
        if(sz[l]>sz[r]+rem+1 || sz[r]>sz[l]+rem+1  || rem>sz[l]+sz[r]+1) return true;
        return false;
    }
};