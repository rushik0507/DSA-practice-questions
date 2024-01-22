#include <bits/stdc++.h>
using namespace std;

int pivot(vector<int> &arr, int n)
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = (start + end)/2;
        cout<<mid<<endl;
        if(arr[mid]>arr[start]){
            start = mid+1;
        }
        if(arr[mid]>arr[mid+1]&& arr[mid]>arr[mid-1]) return arr[mid + 1];
        if(arr[mid]<arr[mid+1]&& arr[mid]<arr[mid-1]) return arr[mid];
        else{
            end = mid-1;
        }
    }
}

int main()
{

    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    cout << pivot(arr, n) << endl;
}