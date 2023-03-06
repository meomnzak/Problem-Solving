#include <bits/stdc++.h>


using namespace std;
int main(){
    int n;
    cin>>n;
    int count = 0;
    vector<int> vec;
    int num;
    for(int i = 0 ; i<n ; i++){
        cin>>num;
        if(i!=0 && num ==1){
            vec.push_back(count);
            count = 0;
        }
        count++;
    }
    vec.push_back(count);
    cout<<vec.size()<<endl;
    for(int i = 0 ; i<vec.size() ; i++){
        cout<<vec[i];
        if(i!=vec.size()-1){
            cout<<" ";
        }
    }
    return 0;
}