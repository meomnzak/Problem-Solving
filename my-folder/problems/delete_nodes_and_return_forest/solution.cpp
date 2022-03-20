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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_map<int,int> mp;
        for(int i = 0 ; i<to_delete.size() ; i++){
            mp[to_delete[i]] = 1;
        }
        dfs(root,mp);
        if(!mp[root->val])
            vec.push_back(root);
        
        return vec;
    }
    
    void dfs(TreeNode *cur, unordered_map<int,int> &mp){
        if(cur==NULL) return;
        if(cur->left){
            dfs(cur->left,mp);
            if(mp[cur->left->val])
                cur->left = NULL;
        }
        if(cur->right){
            dfs(cur->right,mp);
            if(mp[cur->right->val])
                cur->right = NULL;
        }
        if(mp[cur->val]){
            if(cur->left && !mp[cur->left->val])
                vec.push_back(cur->left);
            
            if(cur->right && !mp[cur->right->val])
                vec.push_back(cur->right);
            
        }
    }
    
};