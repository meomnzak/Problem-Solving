class Solution {
public:
    
    vector<int> Xs = {2,2,-2,-2,1,1,-1,-1};
    vector<int> Ys = {1,-1,1,-1,2,-2,2,-2};
    long double meme[27][27][103];
    
    int vis[27][27][103];
    
    int sz;
    
    bool valid(int x, int y){
        return x>=0 && x<sz && y>=0 && y<sz;
    }
    
    long double solve(int x, int y, int cnt){
        if(!valid(x,y)) return 0;
        if(cnt==0) return 1.0;
        long double &ret = meme[x][y][cnt];
        if(vis[x][y][cnt]) return ret;
        vis[x][y][cnt] = 1;
        for(int i = 0 ; i<8 ; i++){
            int newX = x+Xs[i];
            int newY = y+Ys[i];
            ret+= 1.0/8.0 * solve(newX,newY,cnt-1);
        }
        return ret;
    }
    
    double knightProbability(int n, int k, int row, int column) {
        sz = n;
        return solve(row,column,k);
    }
};