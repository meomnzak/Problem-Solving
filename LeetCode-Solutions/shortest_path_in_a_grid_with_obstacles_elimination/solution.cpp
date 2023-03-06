class Solution {
public:
    vector<vector<int>> grid;
    int k;
    const static int N = 43;
    const static int K = 1604;
    int dis[N][N][K];
    int vis[N][N][K];
    int n,m;
    
    vector<int> Xs = {1,-1,0,0};
    vector<int> Ys = {0,0,1,-1};
    
    bool valid(int x, int y){
        return x>=0&&x<n&&y>=0&&y<m;
    }
    
    struct cell{
        int x,y,o;
        cell(int x, int y, int o){
            this->x = x;
            this->y = y;
            this->o = o;
        }
    };
    
    void bfs(int srcX, int srcY){
        memset(dis,'?',sizeof(dis));
        queue<cell> q;
        q.push(cell(srcX,srcY,0));
        dis[srcX][srcY][0] = 0;
        while(!q.empty()){
            cell u = q.front();
            q.pop();
            for(int i = 0 ; i<4 ; i++){
                int newX = u.x + Xs[i];
                int newY = u.y + Ys[i];
                if(!valid(newX,newY)) continue;
                cell v = cell(newX,newY,u.o+(grid[newX][newY]==1));
                if(vis[v.x][v.y][v.o]) continue;
                if(v.o>k) continue;
                vis[v.x][v.y][v.o] = 1;
                dis[v.x][v.y][v.o] = min(dis[v.x][v.y][v.o],dis[u.x][u.y][u.o]+1);
                q.push(v);
            }
        }
    }
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        this->grid = grid;
        this->k = k;
        n = grid.size();
        m = grid[0].size();
        bfs(0,0);
        int ans = 1e9;
        for(int i = 0 ; i<=k ; i++){
            ans = min(ans,dis[n-1][m-1][i]);
        }
        if(ans==1e9) return -1;
        return ans;
    }
};