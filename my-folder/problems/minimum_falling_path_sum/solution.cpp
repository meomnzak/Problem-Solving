class Solution {
public:
    const static int N = 104;
    int meme[N][N];
    vector<vector<int>> grid;
    int n,m;
    
    bool valid(int x, int y){
        return x>=0 && x<n && y>=0 && y<m;
    }
    
    int solve(int x, int y){
        if(!valid(x,y)) return 1e9;
        if(x==n-1) return grid[x][y];
        int &ret = meme[x][y];
        if(~ret) return ret;
        ret = min({solve(x+1,y),solve(x+1,y+1),solve(x+1,y-1)})+grid[x][y];
        return ret;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        memset(meme,-1,sizeof(meme));
        n = matrix.size();
        m = matrix[0].size();
        grid = matrix;
        int ans = 1e9;
        for(int i = 0 ; i<m  ; i++){
            ans = min(ans,solve(0,i));
        }
        return ans;
    }
};