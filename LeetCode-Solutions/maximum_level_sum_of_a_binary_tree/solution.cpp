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
    
    int bfs(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        int lvl = 1;
        long long best = -1e18;
        int ans = -1;
        while(!q.empty()){
            int sz = q.size();
            long long sum = 0;
            while(sz--){
                TreeNode* u = q.front();
                sum+=u->val;
                q.pop();
                if(u->left) q.push(u->left);
                if(u->right) q.push(u->right);
            }
            if(sum>best){
                best = sum;
                ans = lvl;
            }
            lvl++;
        }
        return ans;
    }
    
    int maxLevelSum(TreeNode* root) {
       return bfs(root);
    }
};