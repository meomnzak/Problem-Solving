class Solution {
public:
    
    string to_binary(int num){
        string s = "";
        while(num!=0){
            s+=(num%2)+'0';
            num/=2;
        }
        return s;
    }
    
    const static int N = 2e6+7;
    int nxt[N][3], nNodes=0;
    int createNode(){
        memset(nxt[nNodes],-1,sizeof(nxt[nNodes]));
        return nNodes++;
    }
    
    int root;
    void init(){
        nNodes = 0;
        root = createNode();
    }
    
    void addString(string s){
        int cur = root;
        for(int i = 0 ; i<s.size() ; i++){
            int &child = nxt[cur][s[i]-'0'];
            if(child==-1)
                child = createNode();
            cur = child;
        }
    }
    
    unsigned int find(string s){
        int cur = root;
        string sol = "";
        for(int i = 0 ; i<s.size() ; i++){
            int &child0 = nxt[cur][0];
            int &child1 = nxt[cur][1];
            if(s[i]=='1'){
                if(child0 != -1){
                    sol+='1';
                    cur = child0;
                }else{
                    sol+='0';
                    cur = child1;
                }
            }else{
                if(child1 != -1){
                    sol+='1';
                    cur = child1;
                }else{
                    sol+='0';
                    cur = child0;
                }
            }
        }
        unsigned int factor = 1;
        unsigned int tot = 0;
        for(int i = sol.size()-1 ; i>=0 ; i--){
            if(sol[i]=='1'){
                tot+=factor;
            }
            factor*=2;
        }
        return tot;
    }
    
    
    int findMaximumXOR(vector<int>& nums) {
        vector<string> vec;
        int maxi = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            string bi = to_binary(nums[i]);
            maxi = max(maxi,(int)bi.size());
            vec.push_back(bi);
        }
        init();
        for(int i = 0 ; i<vec.size() ; i++){
            while(vec[i].size()<maxi)
                vec[i].push_back('0');
            reverse(vec[i].begin(),vec[i].end());
            addString(vec[i]);
        }
        unsigned int sol = 0;
        for(int i = 0 ; i<vec.size() ; i++){
          //  cout<<vec[i]<<endl;
            sol = max(sol,find(vec[i]));
        }
        return sol;
        
        
    }
};