#include <bits/stdc++.h>


using namespace std;

const long long N = 504;

long long mat[N][N];

long long n;

vector<long long> vec;

vector<long long> ans;

void floyd(){
    long long summ = 0;
    for(long long k = 0 ; k<n; k++){
        for(long long a= 0 ; a<n ; a++){
            for(long long b = 0 ; b<n ; b++){
                mat[vec[a]][vec[b]] = min(mat[vec[a]][vec[b]],mat[vec[a]][vec[k]]+mat[vec[k]][vec[b]]);
                if(a>k || b>k) continue;
                summ+=mat[vec[a]][vec[b]];
            }
        }
        ans.push_back(summ);
        summ = 0;
    }
    

}
int main(){
    cin>>n;
    for(long long i = 0 ; i<n ; i++){
        for(long long j = 0 ; j<n ; j++){
            cin>>mat[i][j];
        }
    }
    long long num;
    for(long long i = 0 ; i<n; i++){
        cin>>num;
        num--;
        vec.push_back(num);
    }
    reverse(vec.begin(),vec.end());
    floyd();
    for(long long i = ans.size()-1 ; i>=0 ; i--){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}