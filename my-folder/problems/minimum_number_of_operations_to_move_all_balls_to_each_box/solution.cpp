class Solution {
public:
    
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        int dpLeft[n];
        dpLeft[0] = 0;
        int total = boxes[0]-'0';
        for(int i = 1 ; i<n ; i++){
            dpLeft[i] = dpLeft[i-1]+total;
            if(boxes[i]=='1')
                total++;
        }
        int dpRight[n];
        total = boxes[n-1]-'0';
        dpRight[n-1] = 0;
        for(int i = n-2 ; i>=0 ; i--){
            dpRight[i] = dpRight[i+1]+total;
            if(boxes[i]=='1')
                total++;
        }
        vector<int> ans;
        for(int i = 0 ; i<n ; i++){
            ans.push_back(dpLeft[i]+dpRight[i]);
        }
        return ans;
    }
};