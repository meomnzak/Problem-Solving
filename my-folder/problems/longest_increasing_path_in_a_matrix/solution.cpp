class Solution {
public:
    int n,m;
    const static int N = 204;
    int meme[N][N];
    bool valid(int x, int y){
        return x>=0&&x<n&&y>=0&&y<m;
    }
    vector<int> Xs = {1,0,-1,0};
    vector<int> Ys = {0,1,0,-1};
    int solve(vector<vector<int>>& matrix, int x, int y){
        int &ret = meme[x][y];
        if(~ret) return ret;
        ret = 0;
        for(int i = 0 ; i<4 ; i++){
            int newX = x+Xs[i];
            int newY = y+Ys[i];
            if(valid(newX,newY) && matrix[x][y]<matrix[newX][newY]){
                ret = max(ret,1+solve(matrix,newX,newY));
            }
        }
        return ret;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(meme,-1,sizeof(meme));
        n = matrix.size();
        m = matrix[0].size();
        int maxi = 0;
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                maxi = max(maxi,solve(matrix,i,j));
            }
        }
        return maxi+1;
    }
};