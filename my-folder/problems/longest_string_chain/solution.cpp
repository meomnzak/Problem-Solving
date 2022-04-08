class Solution {
public:
    
    const static int N = 1004;
    vector<int> adj[N];
    int vis[N];
    
    bool check(string& s1, string& s2){
        
        int j = 0;
        for(int i = 0 ; i<s1.size();){
            if(s1[i]==s2[j]){
                i++;
            }
            j++;
            if(j-i>1) return false;
        }
        return true;
        
    }
    
    bool static mySort(string s1, string s2){
        return s1.size()<s2.size();
    }
    
    int ans = 0;
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        
        unordered_map<string,int> mp;
        int id = 0;
        for(int i = 0 ; i<n; i++){
            mp[words[i]] = id++;
        }
        
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<n ; j++){
                if(words[j].size()-words[i].size()==1){
                    if(check(words[i],words[j])){
                        adj[mp[words[i]]].push_back(mp[words[j]]);
                    }
                }   
            }
        }
        
        vector<string> others = words;
        sort(others.begin(),others.end(),mySort);
        for(int i = 0 ; i<others.size() ; i++){
            if(!vis[mp[others[i]]]){
                dfs(mp[others[i]],1);
            }
        }
        
        return ans;
        
    }
    
    void dfs(int u, int depth){
        vis[u] = 1;
        ans = max(ans,depth);
        for(auto v: adj[u]){
            if(vis[v]) continue;
            dfs(v,depth+1);
        }
    }
    
};