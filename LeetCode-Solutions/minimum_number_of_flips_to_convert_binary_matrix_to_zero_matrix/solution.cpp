class Solution {
public:
    
    vector<vector<int>> mat;
    int n,m;
    
    bool valid(int x, int y){
        return x>=0 && x<n && y>=0 &&y<m;
    }
    
    bool right(vector<vector<int>> &matrix){
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(matrix[i][j]==1) return 0;
            }
        }
        return 1;
    }
    
    vector<int> Xs = {1,-1,0,0};
    vector<int> Ys = {0,0,-1,1};
    
    map<vector<vector<int>>,bool> vis;
    
    int bfs(){
        queue<vector<vector<int>>> q;
        q.push(mat);
        vis[mat] = 1;
        int lvl = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto u = q.front();
                if(right(u)) return lvl;
                q.pop();
                for(int i = 0 ; i<n ; i++){
                    for(int j = 0 ; j<m ; j++){
                        auto v = u;
                        v[i][j] = 1-v[i][j];
                        for(int k = 0 ; k<4 ; k++){
                            int newX = i+Xs[k];
                            int newY = j+Ys[k];
                            if(!valid(newX,newY)) continue;
                            v[newX][newY] = 1-v[newX][newY];
                        }
                        if(!vis[v]){
                            vis[v] = 1;
                            q.push(v);
                        }
                    }
                }
            }
            lvl++;
        }
        return -1;
    }
    
    int minFlips(vector<vector<int>>& mat) {
        this->mat = mat;
        n = mat.size();
        m = mat[0].size();
        return bfs();
    }
};