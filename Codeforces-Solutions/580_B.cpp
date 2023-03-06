#include <bits/stdc++.h>


using namespace std;

long long sum[100007];


binarySearch(int low , int high , vector<pair<int,int>> arr , int key){
    int res = -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid].first<key){
            res = mid;
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return res;
}

int main(){
    vector<pair<int,int>> vec;
    int x,y;
    int n,diff;
    scanf("%d%d",&n,&diff);
    for(int i = 0 ; i<n ; i++){
        scanf("%d%d",&x,&y);
        vec.push_back(make_pair(x,y));
    }
    sort(vec.begin(),vec.end());
    sum[0] = vec[0].second;
    for(int i = 1 ; i<n ; i++){
        sum[i] = sum[i-1] + vec[i].second;
    }
    int index;
    long long result = 0;
    long long maxx = 0;
    for(int i=0 ; i<n ; i++){
        index = lower_bound(vec.begin(),vec.end(),make_pair(vec[i].first+diff,-1))-vec.begin()-1;
        if(index==-1){
            result = vec[i].second;
        }else{
            if(i==0){
                result = sum[index];
            }else{
                result = sum[index] - sum[i-1];
            }
        }
        if(result > maxx){
            maxx = result;
        }
    }
    printf("%lld\n",maxx);
    return 0;
}