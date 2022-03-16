class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int sorted[n];
        iota(sorted,sorted+n,0);
        sort(sorted,sorted+n,[&](int a, int b){
            return ratings[a]<ratings[b];
        });
        int summ = 0;
        vector<int> num(n,0);
        for(int i = 0 ; i<n ; i++){
            int val = 1;
            int idx = sorted[i];
            int cur = ratings[sorted[i]];
            if(idx>0 && (cur > ratings[idx-1] && val <= num[idx-1])){
                val = num[idx-1]+1;
            }
            if(idx<n-1 && (cur > ratings[idx+1] && val <= num[idx+1])){
                val = num[idx+1]+1;
            }
            num[idx] = val;
            summ+=val;
        }
        
        return summ;
    }
};