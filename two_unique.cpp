#include<bits/stdc++.h>
using namespace std;

void uniqueNum(int arr[],int n){
    cout<<"endter";
    int xor_ans =0;
    for(int i=0;i<n;i++){
        xor_ans = xor_ans^arr[i];
    }
    int count =0;
    while(!(xor_ans&1)){
        count++;
       xor_ans= xor_ans >> 1;
    }
    int one = 0 ;
    int two =0;
    for(int i=0; i<n ;i++){
        int temp = arr[i];
        if((temp>>count)&1 == 1){
            one=one ^ arr[i];
        }
        else{
            two = two^ arr[i];
        }
    }
    cout<<one << " " <<two ;
}

int main(){
    int n;cin >>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    uniqueNum(arr,n);
}