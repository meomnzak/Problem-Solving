#include <bits/stdc++.h>


using namespace std;
int main(){
    string one,two;
    cin>>one>>two;
    reverse(one.begin(),one.end());
    reverse(two.begin(),two.end());
    int count = 0;
    while(!(one.empty()&&two.empty())){
        if(one==two){
            break;
        }
        if(one.size()>two.size()){
            one.pop_back();
        }else{
            two.pop_back();
        }
        count++;
    }
    cout<<count<<endl;
    return 0;
}