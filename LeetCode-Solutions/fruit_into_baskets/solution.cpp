class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l = 0,r=0;
        set<int> st;
        int maxi = 1;
        vector<int> last(fruits.size());
        while(l<n){
            while(r<n && st.size()<3){
                st.insert(fruits[r]);
                last[fruits[r]] = r;
                if(st.size()<3)
                    r++;
            }
            maxi = max(maxi,r-l);
            int best = 1e9;
            int val = -1;
            for(auto elem: st){
                if(last[elem]<best){
                    best = last[elem];
                    val = elem;
                }
            }
            st.erase(val);
            l = best+1;
        }
        return maxi;
   
    }
};