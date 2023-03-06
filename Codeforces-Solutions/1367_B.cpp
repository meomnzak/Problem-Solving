#include <bits/stdc++.h>


using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int count = 0;
        int odd = 0;
        int even= 0;
        int n;
        cin>>n;
        vector<int> vec;
        odd = floor (double(n)/2.0);
        even = ceil (double(n)/2.0);
        int num;
        for(int i = 0 ; i<n ; i++){
            cin>>num;
            if(num%2==0){
                even--;
            }else{
                odd--;
            }
            vec.push_back(num);
        }
        if(even!=0 || odd!=0){
            cout<<-1<<endl;
        }else{
            for(int i = 0 ; i<n ; i+=2){
                if(vec[i]%2==1){
                    count++;
                }
            }
            cout<<count<<endl;
        }
        
    }
    return 0;
}