class Solution {
public:
    vector<double> p;
    Solution(vector<int>& w) {
        int total = accumulate(w.begin(),w.end(),0);
        for(int i = 0 ; i<w.size() ; i++){
            p.push_back((w[i]*1.0)/total);
        }
        
        for(int i = 1 ; i<p.size() ; i++){
            p[i]+=p[i-1];
        }
        
    }
    
    int pickIndex() {
        double val = (double)rand()/RAND_MAX;
        int idx = lower_bound(p.begin(),p.end(),val)-p.begin();
        return idx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */