class Solution {
public:
    
    const static int N = 306;
    
    int vis[N][N];
    int n,m;
    vector<int> Xs = {1,0,-1,0};
    vector<int> Ys = {0,1,0,-1};
    int valid(int x , int y){
        return x>=0&&x<n&&y>=0&&y<m;
    }
    
    void solve(vector<vector<char>>& grid,int x, int y){
        if(!valid(x,y)) return;
        if(vis[x][y]) return;
        if(grid[x][y]=='0') return;
        vis[x][y] = 1;
        for(int i = 0 ; i<4 ; i++){
            solve(grid,x+Xs[i],y+Ys[i]);
        }
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int cnt = 0;
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    solve(grid,i,j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};