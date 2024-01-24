#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int n, int index)
{
    int l = index * 2;
    int r = index * 2 + 1;
    int mx = index;
    if (l < n && arr[index] < arr[l])
    {
        mx = l;
    }
    if (r < n && arr[mx] < arr[r])
    {
        mx = r;
    }
    if (mx != index)
    {
        swap(arr[index], arr[mx]);
        heapify(arr, n, mx);
    }
}

vector<int> heapsort(vector<int> &arr, int n)
{
    for (int i = n / 2-1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
    return arr;
}

int main(){
    int n; 
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int temp;cin>>temp;
        arr.push_back(temp);
    }
    arr = heapsort(arr,n);
    for(int i=0;i<n;i++){
       cout<< arr[i] <<" ";
    }
}