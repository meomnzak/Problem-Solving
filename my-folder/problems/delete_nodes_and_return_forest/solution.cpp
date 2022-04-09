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
    vector<TreeNode *> vec;
    unordered_map<int,int> mp;
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(int i = 0 ; i<to_delete.size() ; i++){
            mp[to_delete[i]] = 1;
        }
        dfs(root);
        if(root && mp.find(root->val)==mp.end())
            vec.push_back(root);
        return vec;
    }
    void dfs(TreeNode *root){
        if(root==NULL) return;
        dfs(root->left);
        dfs(root->right);
        if(root->right && mp.find(root->right->val)!=mp.end()){
            root->right = NULL;
        }
        if(root->left && mp.find(root->left->val)!=mp.end()){
            root->left = NULL;
        }
        if(mp.find(root->val)!=mp.end()){
            if(root->left && mp.find(root->left->val)==mp.end())
                vec.push_back(root->left);
            if(root->right && mp.find(root->right->val)==mp.end())
                vec.push_back(root->right);
            root->left = NULL;
            root->right= NULL;
        }
    }
};