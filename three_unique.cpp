#include <bits/stdc++.h>
using namespace std;

void uniqueNum(int arr[], int n)
{
    vector<int> bits(32, 0);
    for (int i = 0; i < n; i++)
    {
        int count =0;
        int temp=arr[i];
        while(temp!=0){
            cout<<temp<<" "<<count<<endl;
            if(1&temp==1)bits[count]++;
            cout<<bits[0]<< " "<< bits[1]<< " "<< bits[2]<<endl;
            count++;
            temp=temp>>1;
        }
    }
    for(int i=0;i<32;i++){
        cout<<bits[i]<<" ";
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    uniqueNum(arr, n);
}


// https://www.spoj.com/problems/SUBSUMS/