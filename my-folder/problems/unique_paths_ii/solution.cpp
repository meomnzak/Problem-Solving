class Solution {
public:
    int n,m;
    
    vector<vector<int>> obstacleGrid;
    
    const static int N = 103;
    
    int meme[N][N];
    
    bool valid(int x, int y){
        return x>=0 && x<n && y>=0 && y<m;
    }
    
    int solve(int x, int y){
        if(!valid(x,y)) return 0;
        if(obstacleGrid[x][y]==1) return 0;
        if(x==n-1 && y==m-1){
            return 1;
        }
        int &ret = meme[x][y];
        if(~ret) return ret;
        ret = solve(x+1,y)+solve(x,y+1);
        return ret;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        n = obstacleGrid.size();
        m = obstacleGrid[0].size();
        this->obstacleGrid = obstacleGrid;
        memset(meme,-1,sizeof(meme));
        return solve(0,0);
    }
};