class Solution {
public:
    
    int query(vector<vector<int>> &prefixSum, int x1, int y1, int x2, int y2){
        int res = prefixSum[x2][y2];
        if(x1>0){
            res-=prefixSum[x1-1][y2];
        }
        if(y1>0){
            res-=prefixSum[x2][y1-1];
        }
        if(x1>0 && y1>0){
            res+=prefixSum[x1-1][y1-1];
        }
        return res;
    }
    
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> prefixSum(n,vector<int>(m));
        prefixSum[0][0] = mat[0][0];
        for(int i = 1 ; i<n ; i++){
            prefixSum[i][0] = mat[i][0]+prefixSum[i-1][0];
        }
        for(int j = 1 ; j<m ; j++){
            prefixSum[0][j] = mat[0][j]+prefixSum[0][j-1];
        }
        
        for(int i = 1 ; i<n ; i++){
            for(int j = 1 ; j<m ; j++){
                prefixSum[i][j] = mat[i][j]+prefixSum[i-1][j]+prefixSum[i][j-1]-prefixSum[i-1][j-1];
            }
        }
        
        vector<vector<int>> ans(n,vector<int>(m));
        
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                int x1 = max(0,i-k);
                int y1 = max(0,j-k);
                int x2 = min(n-1,i+k);
                int y2 = min(m-1,j+k);
                ans[i][j] = query(prefixSum,x1,y1,x2,y2);
            }
        }
        return ans;
    }
};