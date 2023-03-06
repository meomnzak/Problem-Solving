class Solution {
public:
    const static int N = 5e4+7;
    int fee;
    vector<int> prices;
    int n;
    int meme[N][4];
    
    int solve(int idx, bool haveStock){
        if(idx==n) return 0;
        int &ret = meme[idx][haveStock];
        if(~ret) return ret;
        ret = -1e9;
        ret = max(ret,solve(idx+1,haveStock));
        if(haveStock){
            ret = max(ret,solve(idx+1,0)+prices[idx]-fee);
        }else{
            ret = max(ret,solve(idx+1,1)-prices[idx]);
        }
        return ret;
    }
    
    
    int maxProfit(vector<int>& prices, int fee) {
        n = prices.size();
        memset(meme,-1,sizeof(meme));
        this->fee = fee;
        this->prices = prices;
        return solve(0,0);
    }
};