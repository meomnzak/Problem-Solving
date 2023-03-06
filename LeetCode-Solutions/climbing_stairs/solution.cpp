class Solution {
public:
    const static int N = 50;
    int memo[N];
    int solve(int n){
        if(n<0) return 0;
        if(n==0) return 1;
        int &ret = memo[n];
        if(~ret) return ret;
        ret = 0;
        ret = solve(n-1) + solve(n-2);
        return ret;
    }
    int climbStairs(int n) {
        memset(memo,-1,sizeof(memo));
        return solve(n);
    }
};