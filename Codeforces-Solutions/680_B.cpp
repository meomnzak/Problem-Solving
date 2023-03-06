#include <bits/stdc++.h>


using namespace std;
int main(){
    int n;
    cin>>n;
    int pos;
    cin>>pos;
    pos-=1;
    int count = 0;
    vector<int> vec;
    int num;
    for(int i = 0 ; i<n ; i++){
        cin>>num;
        vec.push_back(num);
    }
    if(vec[pos]==1){
        count++;
    }
    for(int i = 1 ; i<n ; i++){
        if(pos+i < n){
            if(pos-i > -1){
                if(vec[pos+i] == 1 && vec[pos-i]==1){
                    count+=2;
                }
            }else{
                if(vec[pos+i] == 1){
                    count++;
                }
                
            }
        }else{
            if(pos-i > -1){
                if(vec[pos-i] == 1){
                    count++;
                }
            }else{
                break;
            }
        }
    }
    cout<<count<<endl;
    return 0;
}