#include<iostream>
using namespace std;
int main(){
    int n,b;
    cin >> n >> b;
    int sig[n];
    int maxL[n];
    int maxS = 0, maxRes = -1;
    for(int i = 0; i < n; i++){
        cin >> sig[i];
        maxS = max(maxS,sig[i]);
        if(maxS - sig[i] >= b) maxL[i] = maxS - sig[i];
        else maxL[i] = 0;
    }
    maxS = 0;
    for(int i = n - 1; i >= 0; i-- ){
        maxS = max(maxS, sig[i]);
        if( (maxL[i] !=0) and maxS - sig[i] >= b ) maxRes = max(maxRes, maxL[i] + maxS - sig[i]);
    }
    cout << maxRes;
}