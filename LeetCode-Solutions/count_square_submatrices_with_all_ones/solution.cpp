class Solution {
public:
    

    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int dp[n][m];
        
        int cnt = 0;

        
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(matrix[i][j]==1){
                    if(i==0 || j==0){
                        cnt++;
                    }else{
                        int mini = min({matrix[i-1][j],matrix[i][j-1],matrix[i-1][j-1]});
                        matrix[i][j] = mini+matrix[i][j];
                        cnt+=matrix[i][j];
                    }           
                }
 
            }
        }
        return cnt;
    }
};