class Solution {
public:
    
    vector<vector<int>> grid;
    
    
    const static int N = 52;
    int vis[N][N];
    
    vector<int> Xs = {1,-1,0,0};
    vector<int> Ys = {0,0,1,-1};
    
    int n,m;
    
    bool valid(int x, int y){
        return x>=0&&x<n&&y>=0&&y<m;
    }
    
    bool bfs(int maxVal){
        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0] = 1;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            if(x==n-1 && y==m-1) return 1;
            q.pop();
            for(int i = 0 ; i<4 ; i++){
                int newX = x+Xs[i];
                int newY = y+Ys[i];
                if(!valid(newX,newY)) continue;
                if(vis[newX][newY]==1) continue;
                vis[newX][newY] = 1;
                if(grid[newX][newY]>maxVal) continue;
                q.push({newX,newY});
            }
        }
        return 0;
    }
    
    
    
    
    int binarySearch(){
        int res = -1;
        int low = grid[0][0];
        int high = 2500;
        while(low<=high){
            int mid = low + (high-low)/2;
            memset(vis,0,sizeof(vis));
            if(bfs(mid)){
                res = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return res;
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        this->grid = grid;
        n = grid.size();
        m = grid[0].size();
        return binarySearch();
    }
};