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
    vector<TreeNode *> ans;
    unordered_map<string,int> mp;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return ans;
    }
    string dfs(TreeNode *u){
        if(!u) return "#";
        string s = dfs(u->left)+ ","+ dfs(u->right)+ ","+ to_string(u->val);
        mp[s]++;
        if(mp[s]==2) ans.push_back(u);
        return s;
    }
};