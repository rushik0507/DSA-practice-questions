#include<bits/stdc++.h>
using namespace std;

int maxRound(vector<int> &loads,int n){
    vector<int> presum(n);
    presum[0] = loads[0];
    for(int i=1;i<n;i++){
        presum[i]=presum[i-1]+loads[i];
    }
    for(int i=0;i<n;i++)cout<<presum[i]<<" ";
    if(presum[n-1]%n!=0) return -1;
    int avg = presum[n-1]/n;
    int mx = INT_MIN;
    for(int i=0;i<n;i++){
        mx =max(mx,abs(presum[i]-(avg*(i+1))));
    }
    return mx;
}


int main(){
    int n;
    cin>>n;
    vector<int>loads(n);
    for(int i=0;i<n;i++  ){
        cin>>loads[i];
    }
    cout<<maxRound(loads,n);
}