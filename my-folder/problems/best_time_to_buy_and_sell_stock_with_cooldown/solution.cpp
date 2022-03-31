class Solution {
public:
    vector<int> prices;
    const static int N = 5003;
    int meme[N][3];
    int solve(int idx, bool taken){
        if(idx>=prices.size()) return 0;
        int &ret = meme[idx][taken];
        if(~ret) return ret;
        ret = 0;
        ret = max(ret,solve(idx+1,taken));
        if(taken){
            ret = max(ret,solve(idx+2,0)+prices[idx]);
        }else{
            ret = max(ret, solve(idx+1,1)-prices[idx]);
        }
        return ret;
    }
    
    int maxProfit(vector<int>& prices) {
        memset(meme,-1,sizeof(meme));
        this->prices = prices;
        return solve(0,0);
    }
};