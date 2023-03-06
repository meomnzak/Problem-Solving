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
    int maxi = 0;
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int l = leftest(root,0,0);
        l = 0;
        int r = rightest(root);
      //  cout<<r<<endl;
        int cnt = (1<<maxi)-1;
        return cnt+(r-l+1);
    }
    
    int leftest(TreeNode *root, int index, int high){
        maxi = max(maxi,high);
        if(!root->left && !root->right) return index;
        return leftest(root->left, 2*index+1,high+1);
    }
    
    
    bool can(TreeNode *root, int idx){
        int low = 0, high = (1<<maxi)-1;
        for(int i = 0 ; i<maxi ; i++){
            int mid = (low+high)/2;
            if(idx<=mid){
                root = root->left;
                high = mid-1;
            }else{
                root = root->right;
                low = mid+1;
            }
        }
        return(root!=NULL);
    }
    
    int rightest(TreeNode *root){
        int low = 0,high = (1<<maxi)-1;
        int res = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(can(root,mid)){
                low = mid+1;
                res = mid;
            }else{
                high = mid-1;
            }
        }
        return res;
    }
    
};