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
    
    TreeNode *otherRoot;
    
    map<TreeNode *,TreeNode *> par;
    
    queue<TreeNode *> q;
    
    vector<vector<int>> bfs(){
        vector<vector<int>> all;
        while(!q.empty()){
            int sz = q.size();
            vector<int> vec;
            while(sz--){
                TreeNode *u = q.front();
                vec.push_back(u->val);
                q.pop();
                if(par.find(u)==par.end()) continue;
                TreeNode *parent = par[u];
                if(u==parent->left){
                    parent->left = NULL;
                }else{
                   parent->right = NULL; 
                }
                if(!parent->left && !parent->right){
                    q.push(parent);
                }
            }
            all.push_back(vec);
        }
        return all;
    }
    
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        otherRoot = root;
        dfs(otherRoot);
        return bfs();
    }
    
    void dfs(TreeNode *u){
        if(!u) return;
        if(u->left){
            par[u->left] = u;
        }
        if(u->right){
            par[u->right] = u;
        }
        if(!u->left && !u->right){
            q.push(u);
        }
        dfs(u->left);
        dfs(u->right);
    }
    
};