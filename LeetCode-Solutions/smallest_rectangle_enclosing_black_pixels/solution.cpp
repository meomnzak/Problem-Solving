class Solution {
public:
    
    vector<int> Xs = {1,-1,0,0};
    vector<int> Ys = {0,0,-1,1};
    
    
    
    vector<vector<char>> image;
    int n,m;
        
    int u = 1e9,d = -1e9,l = 1e9,r = -1e9;
    
    bool valid(int x, int y){
        return x>=0&&x<n&&y>=0&&y<m;
    }
    
    const static int N = 104;
    
    int vis[N][N];
    
    void dfs(int x, int y){
        u = min(x,u);
        d = max(x,d);
        l = min(y,l);
        r = max(y,r);
        vis[x][y] = 1;
        for(int i = 0 ; i<4 ; i++){
            int newX = Xs[i]+x;
            int newY = Ys[i]+y;
            if(!valid(newX,newY) || image[newX][newY]=='0' || vis[newX][newY]) continue;
            vis[newX][newY] = 1;
            dfs(newX,newY);
        }
    }
    
    int minArea(vector<vector<char>>& image, int x, int y) {
        this->image = image;
        n = image.size();
        m = image[0].size();
        dfs(x,y);
        return (r-l+1)*(d-u+1);
    }
};