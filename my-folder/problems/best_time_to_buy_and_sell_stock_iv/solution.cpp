class Solution {
public:
    vector<int> prices;
    int k;
    const static int N = 1004;
    const static int K = 104;
    int meme[N][K][3];
    
    int solve(int idx, int transactions, bool haveStock){
        if(idx == prices.size()) return 0;
        if(transactions==k) return 0;
        int &ret = meme[idx][transactions][haveStock];
        if(~ret) return ret;
        ret = 0;
        ret = max(ret,solve(idx+1,transactions,haveStock));
        if(haveStock){
            ret = max(ret,solve(idx+1,transactions+1,0)+prices[idx]);
        }else{
            ret = max(ret,solve(idx+1,transactions,1)-prices[idx]);
        }
        return ret;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        memset(meme,-1,sizeof(meme));
        this->k = k;
        this->prices = prices;
        return solve(0,0,0);
    }
};