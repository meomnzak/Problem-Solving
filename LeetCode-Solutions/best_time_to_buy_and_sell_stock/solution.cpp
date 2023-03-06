class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = prices.back();
        int best = 0;
        for(int i = prices.size()-2 ; i>=0 ; i--){
            best = max(best,maxi-prices[i]);
            maxi = max(maxi,prices[i]);
        }
        return best;
    }
};