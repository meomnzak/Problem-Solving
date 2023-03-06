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
    int maxHigh = 0;
    TreeNode *best;
    map<TreeNode *,TreeNode *> par;
    map<TreeNode *,int> vis;
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root->left && !root->right) return 0;
        solve(root,0);
        maxHigh = 0;
        solveAgain(best,0);
        return maxHigh;
    }
    
    void solve(TreeNode* node, int high){
        if(!node->left && !node->right) {
            if(high>maxHigh){
                best = node;
                maxHigh = high;
            }
            return;
        }   
        if(node->left){
            par[node->left] = node;
            solve(node->left,high+1);
        } 
        if(node->right) {
            par[node->right] = node;
            solve(node->right,high+1);
        }
    }
    
    void solveAgain(TreeNode* node, int high){
        maxHigh = max(maxHigh,high);
        vis[node] = 1;
        if(par.find(node)!=par.end() && vis.find(par[node])==vis.end()) solveAgain(par[node],high+1);
        if(node->left && vis.find(node->left)==vis.end()) solveAgain(node->left,high+1);
        if(node->right && vis.find(node->right)==vis.end()) solveAgain(node->right,high+1);
    }
    
    
};