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
class BSTIterator {
public:
    
    stack<TreeNode *> st;
    void goLeft(TreeNode* cur){
        while(cur!=NULL){
            st.push(cur);
            cur = cur->left;
        }
    }
    
    BSTIterator(TreeNode* root) {
        while(st.size()>0) st.pop();
        goLeft(root);
    }
    
    
    int next() {
        TreeNode* ans = st.top();
        st.pop();
        if(ans->right!=NULL){
            goLeft(ans->right);
        }
        return ans->val;
    }
    
    bool hasNext() {
        return st.size()>0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */