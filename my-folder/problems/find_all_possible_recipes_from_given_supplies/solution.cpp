class Solution {
public:
    const static int N = 204;
    unordered_map<string,int> mp;
    unordered_map<string,int> col;
    unordered_map<int,string> rev;
    unordered_map<string,bool> exist;
    vector<int> adj[N];
    vector<string> recipes;
    vector<vector<string>> ingredients;
    vector<string> supplies;
    int vis[N];
    vector<int> topo;
    
    
    void dfs(int u){
        vis[u] = 1;
        for(auto v: adj[u]){
            if(vis[v]) continue;
            dfs(v);
        }
        topo.push_back(u);
    }
    
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        this->recipes = recipes;
        this->ingredients = ingredients;
        this->supplies = supplies;
        int n = ingredients.size();
        int id = 0;
        for(int i = 0 ; i<n ; i++){
            if(mp.find(recipes[i])==mp.end()){
                mp[recipes[i]] = id++;
                rev[id-1] = recipes[i];
            } 
            col[recipes[i]] = i;
            for(int j = 0 ; j<ingredients[i].size() ; j++){
                if(mp.find(ingredients[i][j])==mp.end()) {
                    mp[ingredients[i][j]] = id++;
                    rev[id-1] = ingredients[i][j];
                }
                adj[mp[recipes[i]]].push_back(mp[ingredients[i][j]]);
            }
        }
        
        for(int i = 0 ; i<supplies.size() ; i++){
            exist[supplies[i]] = 1;
        }
        
        for(int i = 0 ; i<recipes.size() ; i++){
            if(!vis[mp[recipes[i]]]){
                dfs(mp[recipes[i]]);
            }
        }
        vector<string> ans;
        for(int i = 0 ; i<topo.size() ; i++){
            string s = rev[topo[i]];
            if(col.find(s)!=col.end()){
                int row = col[s];
                bool flag = true;
                for(int j = 0 ; j<ingredients[row].size() ; j++){
                    if(exist.find(ingredients[row][j])==exist.end()){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    exist[s] = 1;
                    ans.push_back(s);
                }
            }   
        }
        return ans;
    }
};