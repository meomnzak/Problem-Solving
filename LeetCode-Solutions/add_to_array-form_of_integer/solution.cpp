class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();    
        int rem = 0;
        for(int i = n-1 ; i>= 0 ; i--){
            int summ = num[i]+(k%10)+rem;
            num[i] = summ%10;
            rem = summ/10;
            k/=10;
        }
        
        while(k>0 || rem>0){
            int summ = (k%10)+rem;
            int digit = summ%10;
            num.insert(num.begin(),digit);
            rem = summ/10;
            k/=10;
        }
        
        return num;
        
    }
};