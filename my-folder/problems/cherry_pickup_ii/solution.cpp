class Solution {
public:
    
    vector<int> Ys = {0,1,-1};
    
    vector<vector<int>> grid;
    
    int n,m;
    
    bool valid(int y){
        return y>=0&&y<m;
    }
    
    const static int N = 72;
    
    int meme[N][N][N];
    
    int solve(int x, int y1, int y2){
        if(x==n) return 0;
        int &ret = meme[x][y1][y2];
        if(~ret) return ret;
        ret = -1e9;
        for(int i = 0 ; i<3 ; i++){
            for(int j = 0 ; j<3 ; j++){
                int newY1 = y1 + Ys[i];
                int newY2 = y2 + Ys[j];
                if(!valid(newY1) || !valid(newY2)) continue;
                if(y1==y2){
                    ret = max(ret,solve(x+1,newY1,newY2)+grid[x][y1]);
                }else{
                    ret = max(ret,solve(x+1,newY1,newY2)+grid[x][y1]+grid[x][y2]);
                }
            }
        }
        return ret;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        this->grid = grid;
        n = grid.size();
        m = grid[0].size();
        memset(meme,-1,sizeof(meme));
        return solve(0,0,m-1);
    }
};