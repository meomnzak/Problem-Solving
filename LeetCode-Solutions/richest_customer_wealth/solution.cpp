class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxi = 0;
        for(int i = 0 ; i<accounts.size() ; i++){
            int summ = 0;
            for(int j = 0 ; j<accounts[i].size() ; j++){
                summ+=accounts[i][j];
            }
            maxi = max(maxi,summ);
        }
        return maxi;
    }
};