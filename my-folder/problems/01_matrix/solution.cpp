class Solution {
public:
    
    vector<vector<int>> mat;
    
    
    int n,m;
    
    vector<int> Xs = {1,-1,0,0};
    vector<int> Ys = {0,0,1,-1};
    
    bool valid(int x, int y){
        return x>=0&&x<n&&y>=0&&y<m;
    }
    

    vector<vector<int>> vis;
    vector<vector<int>> dis;
    
    void bfs(){
        queue<pair<int,int>> q;
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    vis[i][j] = 1;
                    dis[i][j] = 0;
                }
            }
        }
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i = 0 ; i<4 ; i++){
                int newX = Xs[i]+x;
                int newY = Ys[i]+y;
                if(!valid(newX,newY)) continue;
                if(vis[newX][newY]) continue;
                dis[newX][newY] = dis[x][y]+1;
                vis[newX][newY] = 1;
                q.push({newX,newY});
            }
        }
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        this->mat = mat;
        n = mat.size();
        m = mat[0].size();
        dis = vector<vector<int>>(n,vector<int>(m));
        vis = vector<vector<int>>(n,vector<int>(m));
        bfs();
        return dis;
    }
};