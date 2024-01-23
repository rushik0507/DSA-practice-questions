#include <bits/stdc++.h>
using namespace std;

int part(vector<int> &arr , int start ,int end){
    int p = arr[end];
    int i = start-1;
    for(int j=0;j<arr.size();j++){
        if(arr[j]<p){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[end]);
    return i+1;
}

int quickselect(vector<int> &arr , int start , int end ,int k ){
    if(start >= end){
        return -1;
    }
    int ans;
    int p = part(arr,start,end);
    cout<<"->"<<p<<endl;
    if(p==k-1)ans= p;
    else if(p>k-1){
        cout<<"~~~"<<endl;
        ans = quickselect(arr,start,p-1,k);
    }
    else{
        cout<<"---"<<endl;
        ans = quickselect(arr,p+1,end,k);
    }   
    return ans;
}

int main()
{
    int n,k;
    cin >> n >>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<quickselect(arr,0,n-1,k);
}