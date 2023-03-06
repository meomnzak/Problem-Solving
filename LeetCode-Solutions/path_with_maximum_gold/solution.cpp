class Solution {
public:
    
    int ans = 0;
    
    int vis[16][16];
    
    int vid;
    
    vector<int> Xs = {1,-1,0,0};
    vector<int> Ys = {0,0,1,-1};
    
    bool isValid(int x , int y, int n, int m){
        return x>=0&&x<n&&y>=0&&y<m;
    }
    
    void dfs(int x, int y, int collected,vector<vector<int>>& grid, int n, int m){
        vis[x][y] = vid;
        ans = max(ans,collected);
        for(int i = 0 ; i<4 ; i++){
            int newX = x+Xs[i];
            int newY = y+Ys[i];
            if(isValid(newX,newY,n,m)&& vis[newX][newY]!=vid && grid[newX][newY]!=0){
                dfs(newX,newY,collected+grid[newX][newY],grid,n,m);
                vis[newX][newY] = 0;
            }
        }
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(grid[i][j]==0) continue;
                vid++;
                dfs(i,j,grid[i][j],grid,n,m);
            }
        }
        return ans;
    }
};