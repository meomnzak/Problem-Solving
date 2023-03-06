#include <bits/stdc++.h>


using namespace std;

map<long long,long long> m;
 vector<pair<long long,long long>> vec;


bool valid(long long mid , long long money){
    for(long long i = 0 ; i<3; i++){
        if(m[i]*mid > vec[i].first){
            long long diff = (m[i] * mid) - vec[i].first;
            diff*=vec[i].second;
            if(money<diff){
                return false;
            }else{
                money-=diff;
            }
        }
    }
    return true;
}

long long binarySearch(long long low , long long high, long long money){
    long long res = -1;
    while(low<=high){
        long long mid = low + (high-low)/2;
        if(valid(mid,money)){
            res = mid;
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return res;
}


int main(){
    string s;
    cin>>s;
    for(long long i = 0 ; i<s.size() ; i++){
        if(s[i]=='B'){
            m[0]++;
        }else if(s[i]=='S'){
            m[1]++;
        }else{
            m[2]++;
        }
    }
    long long num;
   for(long long i = 0 ; i<3; i++){
       cin>>num;
       vec.push_back({num,0});
   }
   
   for(long long i = 0 ; i<3; i++){
       cin>>num;
       vec[i].second = num;
   }
   long long money;
   cin>>money;
   long long val = binarySearch(0,1e15*1LL,money);
   cout<<val<<endl;
    return 0;
}