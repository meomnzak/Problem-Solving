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
    TreeNode* correctBinaryTree(TreeNode* root) {
        unordered_map<TreeNode *,TreeNode *> par;
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *toNode = NULL;
        while(!q.empty()){
            TreeNode *u = q.front();
            q.pop();
            if(u->left){
                if(par.find(u->left)!=par.end()){ 
                    toNode = u->left;
                    par[u->left] = u;
                    break;
                }
                par[u->left] = u;
                q.push(u->left);
            }
            if(u->right){
                if(par.find(u->right)!=par.end()){
                     toNode = u->right;
                     par[u->right] = u;
                    break;
                }
                par[u->right] = u;
                q.push(u->right);
            }
        }
        TreeNode *fromNode = par[toNode];
        TreeNode *cutter = par[fromNode];
        if(cutter->left && cutter->left==fromNode){
            cutter->left = NULL;
        }else{
            cutter->right = NULL;
        }
        return root;
    }
};