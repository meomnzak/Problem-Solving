#include <bits/stdc++.h>


using namespace std;

vector<pair<long long,long long>> vec;


bool calc(long long cookies,long long magic){
    for(long long i = 0 ; i<vec.size() ; i++){
        if(vec[i].second/vec[i].first<cookies){
            if(to_string(cookies).size()+to_string(vec[i].first).size() > 20){
                return false;
            }
            long long want = cookies*vec[i].first;
            if(magic+vec[i].second<want){
                return false;
            }else{
                magic -= (want-vec[i].second);
            }
        }
    }
    return true;
}

int main(){
    long long n;
    long long magic;
    cin>>n>>magic;
    long long num;
    for(long long i = 0 ; i<n ;i++){
        cin>>num;
        vec.push_back(make_pair(num,0));
    }
     for(long long i = 0 ; i<n ;i++){
        cin>>num;
        vec[i].second= num;
    }
    long long low = 0;
    long long high = 200000000000;
    long long ans = 0;
    while(low<=high){
        long long mid = low + (high-low)/2;
        if(calc(mid,magic)){
            ans = mid;
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}