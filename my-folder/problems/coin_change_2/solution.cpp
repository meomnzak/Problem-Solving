class Solution {
public:
    const static int N = 303;
    const static int K = 5003;
    int meme[N][K];
    vector<int> coins;
    int amount;
    int n;
    
    int solve(int idx, int have){
        if(have>amount) return 0;
        if(have==amount) return 1;
        if(idx==n) return 0;
        int &ret = meme[idx][have];
        if(~ret) return ret;
        ret = 0;
        ret = solve(idx+1,have)+solve(idx,have+coins[idx]);
        return ret;
    }
    
    int change(int amount, vector<int>& coins) {
        memset(meme,-1,sizeof(meme));
        n = coins.size();
        this->coins = coins;
        this->amount = amount;
        return solve(0,0);
    }
};