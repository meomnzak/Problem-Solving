class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        int n,m;
        n = grid.size();
        m = grid[0].size();
        int flipped[m];
        for(int j = 0 ; j<m ; j++){
            if(grid[0][j]==1){
                flipped[j] = 1;
            }else{
                flipped[j] = 0;
            }
        }
        for(int i = 1 ; i<n ; i++){
            int cntZeroes = 0;
            int cntOnes = 0;
            for(int j = 0 ; j<m ; j++){
                int cur = grid[i][j];
                if(flipped[j]==1) cur = 1-cur;
                if(cur==0){
                    cntZeroes++;
                }else{
                    cntOnes++;
                }
            }
            if( !(cntZeroes==m || cntOnes==m) ) return 0;
        }
        return 1;
    }
};