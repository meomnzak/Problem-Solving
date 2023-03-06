class Solution {
public:
    int least,most;
    map<pair<int,int>,int> mp;
    vector<int> colors;
    long long cnt = 0;
    void solve(int prev, int idx){
        if(idx==most) return;
        
        for(int i = 1 ; i<=9 ; i++){
            if(colors[i]==1) continue;
            int mini = min(i,prev);
            int maxi = max(i,prev);
            if(mp.find({mini,maxi}) != mp.end()){
                if(colors[mp[{mini,maxi}]]==0) continue;
            }
            if(idx>=(least-1))cnt++;
            colors[i] = 1;
            solve(i,idx+1);
            colors[i] = 0;
        }
        
    }
    
    int numberOfPatterns(int m, int n) {
        least = m;
        most = n;
        colors = vector<int>(10,0);
        mp[{1,3}] = 2;
        mp[{1,7}] = 4;
        mp[{1,9}] = 5;
        mp[{2,8}] = 5;
        mp[{3,7}] = 5;
        mp[{3,9}] = 6;
        mp[{4,6}] = 5;
        mp[{7,9}] = 8;
        solve(-1,0);
        return cnt;
    }
};