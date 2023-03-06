class Solution {
public:
    const static int N = 307;
    int meme[N][N];
    bool valid(int i , int j , int n , int m){
        return i>=0 && i<n && j>=0 && j<m;
    }
    int solve(int i, int j , vector<vector<char>>& matrix){
        if(!valid(i,j,matrix.size(),matrix[0].size())) return 0;
        if(matrix[i][j]=='0') return 0;
        int &ret = meme[i][j];
        if(~ret) return ret;
        ret = min({solve(i,j-1,matrix),solve(i-1,j,matrix),solve(i-1,j-1,matrix)})+1;
        return ret;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        memset(meme,-1,sizeof(meme));
        int maxi = 0;
        for(int i = 0 ; i <matrix.size() ; i++){
            for(int j = 0 ; j<matrix[0].size() ; j++){
              //  if(matrix[i][j]==0) continue;
                maxi = max(maxi,solve(i,j,matrix));
            }
        }
        return maxi*maxi;
        
    }
};