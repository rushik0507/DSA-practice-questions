#include<bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int> &arr, int n,int i){
    if(n==1||n==0)return;
    if(i==n-1){
        bubble_sort(arr,n-1,0);return;
    }
    if(arr[i]>arr[i+1]){
        swap(arr[i],arr[i+1]);
    }
    bubble_sort(arr,n,i+1);
   
}

int main(){
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    bubble_sort(arr,n,0);
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
}