#include <bits/stdc++.h>


using namespace std;

bool mySort(pair<char,int> p1 , pair<char,int> p2){
    return p1.second<p2.second;
}

int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    string s;
    cin>>s;
    vector<pair<char,int>> vec;
    for(int i = 0 ; i<n; i++){
        vec.push_back(make_pair(s[i],i));
    }
    sort(vec.begin(),vec.end());
    map<int,int> m;
    for(int i = 0 ; i<k ; i++){
        m[vec[i].second] = 1;
    }
    sort(vec.begin(),vec.end(),mySort);
    for(int i = 0 ;i<n ; i++){
        if(m[i]==0){
            cout<<vec[i].first;
        }
    }
    cout<<endl;
    return 0;
}