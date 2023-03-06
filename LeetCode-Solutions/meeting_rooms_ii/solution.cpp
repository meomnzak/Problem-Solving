class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int N = 1e6+7;
        vector<int> D(N+1,0);
        for(int i = 0 ; i<intervals.size() ; i++){
            int l = intervals[i][0];
            int r = intervals[i][1];
            D[l]++;
            D[r]--;
        }
        vector<int> arr(N);
        int maxi = arr[0];
        arr[0] = D[0];
        for(int i = 1 ; i<N ; i++){
            arr[i] = arr[i-1]+D[i];
            maxi = max(maxi,arr[i]);
        }
        return maxi;
    }
};