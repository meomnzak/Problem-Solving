class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int half = n/2;
        for(int i = 0 ; i<(n+1)/2 ; i++){
            for(int j = 0 ; j<half; j++){
                pair<int,int> start = {i,j};
                int val = matrix[i][j];
                for(int k = 0 ; k<4 ; k++){
                    pair<int,int> nxt = {start.second,n-start.first-1};
                    swap(matrix[nxt.first][nxt.second],val);
                    start = nxt;
                }
                
            }
        }
        
     
        
    }
};