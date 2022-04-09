class Solution {
public:
    
    const static int N = 1003;
    
    vector<int> diff;
    
    void update(int st, int en, int val){
        diff[st]+=val;
        diff[en+1]-=val;
    }
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        diff = vector<int>(N,0);
        for(int i = 0 ; i<trips.size() ; i++){
            update(trips[i][1],trips[i][2]-1,trips[i][0]);
        }
        
        for(int i = 1 ; i<N ; i++){
            diff[i]+=diff[i-1];
        }
        
        int maxi = *max_element(diff.begin(),diff.end());
        if(maxi>capacity) return 0;
        return 1;
        
    }
};