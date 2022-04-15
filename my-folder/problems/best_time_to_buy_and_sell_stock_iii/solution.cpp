class Solution {
public:
    vector<int> prices;
    int n;
    const static int N = 1e5+7;
    
    int meme[N][2][4];
    
    int solve(int idx, bool have, int tran){
        if(idx==n) return 0;
        int &ret = meme[idx][have][tran];
        if(~ret) return ret;
        ret = solve(idx+1,have,tran);
        if(have==0){
            ret = max(ret,solve(idx+1,1,tran)-prices[idx]);
        }else if(have==1 && tran<2){
            ret = max(ret,solve(idx+1,0,tran+1)+prices[idx]);
        }
        return ret;
    }
    
    int maxProfit(vector<int>& prices) {
        this->prices = prices;
        n = prices.size();
        memset(meme,-1,sizeof(meme));
        return solve(0,0,0);
    }
};