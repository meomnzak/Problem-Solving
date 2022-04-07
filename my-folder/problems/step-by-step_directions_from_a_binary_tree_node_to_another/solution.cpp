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
    
    TreeNode* lca;
    int startValue;
    int destValue;
    int cnt;
    string half;
    
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        this->startValue = startValue;
        this->destValue = destValue;
        LCA(root);
        dfs(lca,0);
        string ans(cnt,'U');
        string temp = "";
        dfs2(lca,temp);
        ans+=half;
        return ans;
    }
    
    bool LCA(TreeNode *u){
        if(!u) return false;
        int left = LCA(u->left);
        int right = LCA(u->right);
        int mid = (u->val==startValue) || (u->val==destValue);
        if(left+right+mid>=2) lca = u;
        return (mid||left||right);
    }
    
    void dfs(TreeNode *u, int c){
        if(!u) return;
        if(u->val==startValue){
            cnt = c;
            return;
        }
        dfs(u->right,c+1);
        dfs(u->left,c+1);
    }
    
    void dfs2(TreeNode *u, string &s){
        if(!u) return;
        if(u->val==destValue){
            half = s;
            return;
        }
        s+='R';
        dfs2(u->right,s);
        s.pop_back();
        s+='L';
        dfs2(u->left,s);
        s.pop_back();
    }
    
};