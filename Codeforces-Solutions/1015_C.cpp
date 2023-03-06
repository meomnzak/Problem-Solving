#include <bits/stdc++.h>


using namespace std;

bool mySort(pair<int,int> p1 , pair<int,int> p2){
    return p1.first-p1.second>p2.first-p2.second;
}

int main(){
    int n;
    cin>>n;
    long long tot;
    cin>>tot;
    int one,two;
    vector<pair<int,int>> vec;
    long long sum = 0;
    while(n--){
        cin>>one>>two;
        sum+=one;
        vec.push_back(make_pair(one,two));
    }
    sort(vec.begin(),vec.end(),mySort);
    int count= 0;
    for(int i = 0 ; i<vec.size() ; i++){
        if(sum<=tot){
            break;
        }
        count++;
        sum+=vec[i].second;
        sum-=vec[i].first;
    }
    if(sum<=tot){
        cout<<count<<endl;
    }else{
        cout<<-1<<endl;
    }
    return 0;
}