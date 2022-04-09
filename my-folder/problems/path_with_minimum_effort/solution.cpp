class Solution {
public:
    
    vector<vector<int>> heights;
    int n,m;
    
    vector<int> Xs = {1,-1,0,0};
    vector<int> Ys = {0,0,1,-1};
    
    bool valid(int x, int y){
        return x>=0&&x<n&&y>=0&&y<m;
    }
    
    const static int N = 105;
    
    int dis[N][N];
    
    void dijkstra(){
        memset(dis,'?',sizeof(dis));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        q.push({0,{0,0}});
        dis[0][0] = 0;
        while(!q.empty()){
            int x = q.top().second.first;
            int y = q.top().second.second;
            int diff = q.top().first;
            q.pop();
            if(diff != dis[x][y]) continue;
            for(int i = 0 ; i<4 ; i++){
                int newX = x+Xs[i];
                int newY = y+Ys[i];
                if(!valid(newX,newY)) continue;
                int newDiff = abs(heights[x][y]-heights[newX][newY]);
                newDiff = max(newDiff,diff);
                if(newDiff<dis[newX][newY]){
                    dis[newX][newY] = newDiff;
                    q.push({newDiff,{newX,newY}});
                }
            }
        }
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        this->heights = heights;
        n = heights.size();
        m = heights[0].size();
        dijkstra();
        return dis[n-1][m-1];
    }
};