class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        deque<int> de;
        for(int i = 0 ; i<nums.size() ; i++){
            de.push_back(nums[i]);
        }
        sort(de.begin(),de.end());
        nums.clear();
        while(de.size()>0){
            nums.push_back(de.front());
            de.pop_front();
            if(de.size()>0){
                nums.push_back(de.back());
                de.pop_back();
            }
        }
    }
};