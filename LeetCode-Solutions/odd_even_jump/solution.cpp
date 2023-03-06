class Solution {
public:
    
    static const int N = 2e4+7;
    
    int memo[N][3];
    int n;
    int solve(int idx, int jump, vector<int> &nxtSmaller,vector<int> &nxtBigger){
        if(idx==n-1) return 1;
        if(idx==n) return 0;
        int &ret = memo[idx][jump];
        if(~ret) return ret;
        ret = 0;
        if(jump==0){
            ret|=solve(nxtBigger[idx],1,nxtSmaller,nxtBigger);
        }else{
            ret|=solve(nxtSmaller[idx],0,nxtSmaller,nxtBigger);
        }
        return ret;
    }

    int oddEvenJumps(vector<int>& arr) {
        n = arr.size(); 
        memset(memo,-1,sizeof(memo));
        vector<int> nxtBigger(n,n);
        vector<int> nxtSmaller(n,n);
        
        map<int,int> mp;
        mp[arr[n-1]] = n-1;
        for(int i = n-2 ; i>=0 ; i--){
            auto one = mp.lower_bound(arr[i]);
            auto two = mp.upper_bound(arr[i]);
            if(one!=mp.end()) nxtBigger[i] = one->second;
            if(two!=mp.begin()) nxtSmaller[i] = (--two)->second;
            mp[arr[i]] = i;
        }
        

        int cnt = 0;
        for(int i = 0 ; i<arr.size() ; i++){
            cnt+=solve(i,0,nxtSmaller,nxtBigger);
        }
        return cnt;
    }
};