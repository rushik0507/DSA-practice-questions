#include <bits/stdc++.h>
using namespace std;

int maxSum(int arr[],int n,int k){
    int m = 0;
    for(int i =0 ;i<k;i++){
        m +=arr[i];
    }
    for(int i=0;i<n-k;i++){
        int sum = m - arr[i]+arr[i+k];
        m=max(m,sum);
    }
    return m;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << maxSum(arr, n, k);
}