class Solution {
public:
    const static int N = 204;
    int meme[N][N];
    vector<vector<int>> grid;
    int n,m;
    
    bool valid(int x, int y){
        return x>=0 && x<n && y>=0 && y<m;
    }
    
    int solve(int x, int y){
        if(!valid(x,y)) return 1e9;
        if(x==n-1 && y==m-1) return grid[x][y];
        int &ret = meme[x][y];
        if(~ret) return ret;
        ret = min(solve(x+1,y),solve(x,y+1))+grid[x][y];
        return ret;
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        memset(meme,-1,sizeof(meme));
        n = grid.size();
        m = grid[0].size();
        this->grid = grid;
        return solve(0,0);
    }
};