class Solution {
public:
    
    vector<vector<int>> costs;
    int n,m;
    const static int N = 104;
    const static int K = 23;
    int meme[N][K];
    
    int solve(int idx, int lst){
        if(idx==n) return 0;
        int &ret = meme[idx][lst];
        if(~ret) return ret;
        ret = 1e9;
        for(int i = 0 ; i<m ; i++){
            if(i==lst) continue;
            ret = min(ret,solve(idx+1,i)+costs[idx][i]);
        }
        return ret;
    }
    
    
    int minCostII(vector<vector<int>>& costs) {
        memset(meme,-1,sizeof(meme));
        this->costs = costs;
        n = costs.size();
        m = costs[0].size();
        return solve(0,m+1);
    }
};