#include <bits/stdc++.h>
using namespace std;

int getrandom(int start, int end)
{
    srand(time(0)); 
    int r = rand();
    return ((r % (end - start + 1)) + start);
}
vector<int> random(vector<int> &arr, int end){
    for(int i=end-1;i>0;i--){
        int index = getrandom(0,i-1);
            swap(arr[index],arr[i]);
    }
    return arr;
}
int main()
{
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout << getrandom(0, n) << endl;
    arr= random(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}