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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return 1;
        if(!root1 || !root2) return 0;
        if(root1->val != root2->val) return 0;
        queue<TreeNode *> q1;
        queue<TreeNode *> q2;
        q1.push(root1);
        q2.push(root2);
        map<int, int> par; 
        while(!q1.empty() && !q2.empty()){
            if(q1.size()!=q2.size()) return 0;
            int sz = q1.size();
            while(sz--){
                TreeNode *u1 = q1.front();
                q1.pop();
                if(u1->left){
                    q1.push(u1->left);
                    par[u1->left->val] = u1->val;
                }
                if(u1->right){
                    q1.push(u1->right);
                    par[u1->right->val] = u1->val;
                }
            }
            sz = q2.size();
            while(sz--){
                TreeNode *u2 = q2.front();
                q2.pop();
                if(u2->left){
                    q2.push(u2->left);
                    if(par.find(u2->left->val)==par.end()) return 0;
                    if(par[u2->left->val] != u2->val) return 0;
                }
                if(u2->right){
                    q2.push(u2->right);
                    if(par.find(u2->right->val)==par.end()) return 0;
                    if(par[u2->right->val] != u2->val) return 0;
                }
            }
        }
        return 1;
    }
};