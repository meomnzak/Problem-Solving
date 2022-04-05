class Solution {
public:
    const static int N = 11;
    vector<vector<int>> workers;
    vector<vector<int>> bikes;
    int meme[N][1<<N];
    int n;
    int m;
    int solve(int idx, int msk){
        if(idx==n) return 0;
        int &ret = meme[idx][msk];
        if(~ret) return ret;
        ret = 1e9;
        for(int i = 0 ; i<m ; i++){
            if(((1<<i)&msk)==0){
                int dis = abs(workers[idx][0]-bikes[i][0]) + abs(workers[idx][1]-bikes[i][1]);
                ret = min(ret, solve(idx+1,(1<<i)|msk) + dis);
            }
        }
        return ret;
    }
    
    

    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        this->workers = workers;
        this->bikes = bikes;
        memset(meme,-1,sizeof(meme));
        n = workers.size();
        m = bikes.size();
        return solve(0,0);
    }
};