#include <iostream>
 
 
using namespace std;
int main(){
    int jokes = 0;
    int sum = 0;
    int numOfSongs;
    int durationOfTheShow;
    cin>>numOfSongs;
    cin>>durationOfTheShow;
    int durationOfTheSong;
    for(int i = 0 ; i<numOfSongs ; i++){
        cin>>durationOfTheSong;
        sum+=durationOfTheSong;
        if(i != numOfSongs-1){
            sum+=10;
            jokes+=2;
        }
    }
    if(sum<=durationOfTheShow){
        jokes+=(durationOfTheShow-sum) / 5;
        cout<<jokes<<endl;
    } else {
        cout<<"-1"<<endl;
    }
    return 0;
}