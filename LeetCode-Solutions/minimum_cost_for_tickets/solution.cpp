class Solution {
public:
    const static int N = 370;
    vector<int> days;
    vector<int> costs;
    int n;
    int meme[N];
    vector<int> duration = {1,7,30};
    int solve(int idx){
        if(idx==n) return 0;
        int &ret = meme[idx];
        if(~ret) return ret;
        ret = 1e9;
        for(int i = 0 ; i<3 ; i++){
            ret = min(ret,solve(lower_bound(days.begin(),days.end(),days[idx]+duration[i])-days.begin())+costs[i]);
        }
        return ret;
    }
    
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(meme,-1,sizeof(meme));
        n = days.size();
        this->days = days;
        this->costs = costs;
        return solve(0);
    }
};