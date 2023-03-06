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
    vector<int> one;
    vector<int> two;
    bool isSymmetric(TreeNode* root) {
        traverseOne(root->left);
        traverseTwo(root->right);
        return one==two;
    }
    void traverseOne(TreeNode* root){
        if(root==NULL){
            one.push_back(-1000);
            return;
        }
        one.push_back(root->val);
        traverseOne(root->left);
        traverseOne(root->right);
    }
    void traverseTwo(TreeNode* root){
        if(root==NULL){
            two.push_back(-1000);
            return;
        }
        two.push_back(root->val);
        traverseTwo(root->right);
        traverseTwo(root->left);
    }
};