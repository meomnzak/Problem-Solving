#include <bits/stdc++.h>


using namespace std;





int main(){
    int n;
    cin>>n;
    int num;
    vector<int> vec;
    for(int i = 0 ; i<n ; i++){
        cin>>num;
        vec.push_back(num);
    }
    int count = n;
    sort(vec.begin(),vec.end());

    
    int l=0;
    int r= n/2;
    
    while(l<n/2){
        while(r<n){
            if(vec[l]*2<=vec[r]){
                count--;
                r++;
                break;
            }
            r++;
        }
        l++;
    }
    
    cout<<count<<endl;
    return 0;
    
}