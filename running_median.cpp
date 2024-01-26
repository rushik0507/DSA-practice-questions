#include<bits/stdc++.h>
using namespace std;

void runningMid(vector<int>arr,int n){
    priority_queue<int>mx;
    priority_queue<int,vector<int>,greater<int>>mn;
    int median = arr[i];
    cout<<median<<" ";
    for(int i=0;i<n;i++){
        if(arr[i]<median){
            mx.push(arr[i]);
        }
        else{
            mn.push(arr[i]);
        }
        if(abs(mx.size()-mn.size())>1){
            if(mx.size()>mn.size()){
                mn.push(mx.top());
                mx.pop();
            }
        }
    }
}

int main(){
    int n;cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){cin>>arr[i];}
}