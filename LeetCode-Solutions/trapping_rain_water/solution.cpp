class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> nxt(height.size(),height.size());
        vector<int> before(height.size(),height.size());
        int largest = 0;
        for(int i = 1 ; i<height.size() ; i++){
            if(height[largest]>height[i]){
                before[i] = largest; 
            }else{
                largest = i;
            }
        }
        largest = height.size()-1;
        for(int i = height.size()-2 ; i>=0 ; i--){
            if(height[largest]>height[i]){
                nxt[i] = largest; 
            }else{
                largest = i;
            }
        }
        int ans = 0;
        for(int i = 0 ; i<height.size() ; i++){ 
            int afterMe = nxt[i];
            int beforeMe = before[i];
            if(afterMe==height.size() || beforeMe==height.size()) continue;
            int high = min(height[afterMe],height[beforeMe]);
            ans+=(high-height[i]);
        }
        return ans;
    }
};