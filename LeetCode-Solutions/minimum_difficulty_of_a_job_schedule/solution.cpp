class Solution {
public:
    const static int N = 302;
    int meme[N][12];
    
    int solve(int idx, int day,vector<int> &jobDifficulty, int maxDays){
        if(day>maxDays) return 1e9;
        if(idx==jobDifficulty.size()){
            if(day==maxDays){
                return 0;
            }else{
                return 1e9;
            }
        }
        int &ret = meme[idx][day];
        if(~ret) return ret;
        ret = 1e9;
        int maxi = -1e9;
        for(int i = idx ; i<jobDifficulty.size() ; i++){
            maxi = max(maxi,jobDifficulty[i]);
            ret = min(ret,solve(i+1,day+1,jobDifficulty,maxDays)+maxi);
        }
        return ret;
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(jobDifficulty.size()<d) return -1;
        memset(meme,-1,sizeof(meme));
        return solve(0,0,jobDifficulty,d);
    }
};