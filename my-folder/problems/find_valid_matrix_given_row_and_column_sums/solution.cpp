class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = colSum.size();
        int n = rowSum.size();
        vector<vector<int>> vec(n,vector<int>(m));
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m; j++){
                vec[i][j] = min(rowSum[i],colSum[j]);
                rowSum[i]-=vec[i][j];
                colSum[j]-=vec[i][j];
            }
        }
        return vec;
        
    }
};