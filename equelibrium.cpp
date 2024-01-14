#include<iostream>
using namespace std;

int equilibrium(int arr[],int n){
    int sum[n];
    sum[0]=arr[0];
    for(int i=1;i<n;i++){
        sum[i]=sum[i-1]+arr[i];
        cout<<sum[i]<<" ";
    }
    for(int i=0;i<n;i++){
        if(i==0 && sum[n-1]-arr[i]==0){
            return i;
        }
        else{
            if(sum[i-1]==sum[n-1]-sum[i]){
                return i;
            }
        }
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<equilibrium;

}
