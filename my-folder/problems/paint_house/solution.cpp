class Solution {
public:
    
    vector<vector<int>> costs;
    int n;
    const static int N = 104;
    int meme[N][5];
    
    int solve(int idx, int lst){
        if(idx==n) return 0;
        int &ret = meme[idx][lst];
        if(~ret) return ret;
        ret = 1e9;
        for(int i = 0 ; i<3 ; i++){
            if(i==lst) continue;
            ret = min(ret,solve(idx+1,i)+costs[idx][i]);
        }
        return ret;
    }
    
    int minCost(vector<vector<int>>& costs) {
        memset(meme,-1,sizeof(meme));
        this->costs = costs;
        n = costs.size();
        return solve(0,4);
    }
};