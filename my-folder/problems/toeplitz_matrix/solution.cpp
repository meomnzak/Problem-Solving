class Solution {
public:
    int n,m;
    bool isValid(int x, int y){
        return x>=0 && x<n && y>=0 &&y<m;
    }
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(isValid(i-1,j-1)) continue;
                int val = matrix[i][j];
                int x = i;
                int y = j;
                while(isValid(x,y)){
                    int newVal = matrix[x][y];
                    if(newVal!=val) return false;
                    x++;
                    y++;
                }
            }
        }
        return true;
    }
};