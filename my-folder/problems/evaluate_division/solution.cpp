class Solution {
public:
    const static int N = 42;
    double mat[N][N];
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i = 0 ; i<N ; i++){
            for(int j = 0 ; j<N ; j++){
                mat[i][j] = (i==j) ? 1 : 1e9;
            }
        }
        map<string,int> mp;
        int id = 0;
        for(int i = 0 ; i<equations.size(); i++){
            if(mp.find(equations[i][0])==mp.end()){
                mp[equations[i][0]] = id++;
            }
            if(mp.find(equations[i][1])==mp.end()){
                mp[equations[i][1]] = id++;
            }
            mat[mp[equations[i][0]]][mp[equations[i][1]]] = values[i];
            mat[mp[equations[i][1]]][mp[equations[i][0]]] = 1/values[i];
        }
        floyd();
        vector<double> sol;
        for(int i = 0 ; i<queries.size() ; i++){
            if(mp.find(queries[i][0])==mp.end() || mp.find(queries[i][1])==mp.end()){
                sol.push_back(-1);
            }else{
                 
                double ans = mat[mp[queries[i][0]]][mp[queries[i][1]]];
                if(ans>=1e9){
                    ans = -1;
                }
                sol.push_back(ans);
            }
        }
        return sol;
    }
    
    void floyd(){
        for(int k = 0 ; k<N ; k++){
            for(int a = 0 ; a<N ; a++){
                for(int b = 0 ; b<N ; b++){
                    if(mat[a][k]>=1e9 || mat[k][b]>=1e9) continue;
                    mat[a][b] = min(mat[a][b],mat[a][k]*mat[k][b]);
                }
            }
        }
    }
    
    
    
};