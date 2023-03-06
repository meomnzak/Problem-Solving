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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vec;
        if(root==NULL) return vec;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            vector<int> level;
            while(sz--){
                TreeNode *u = q.front();
                q.pop();
                level.push_back(u->val);
                if(u->left){
                    q.push(u->left);
                }
                if(u->right){
                    q.push(u->right);
                }
            }
            vec.push_back(level);
        }
        return vec;
    }
};