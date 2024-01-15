#include <bits/stdc++.h>
using namespace std;

int numOfpair(int arr[], int n, int target)
{
    int start = 0;
    int end = 1;
    int count = 0;
    while (end < n)
    {
        // // cout<<target<<end<<" " <<start<<" "<<arr[end]-arr[start]<<endl;
        if (arr[end] - arr[start] == target)
        {
            count++;
            start++;
            end++;
        }
        else if (arr[end] - arr[start] < target)
        {
            end++;
        }
        else
            start++;
    }
    return count;
}

int numOfless(int arr[], int n, int target)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int start = i+1;
        int end = n-1;

        while (end >start)
        {
            if (arr[end] +arr[start] <= target-arr[i])
            {
                count+= end-start;
                start++;
            }
            else
                end--;
        }
    }
    return count;
}

int main()
{
    int n, target;
    cin >> n >> target;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << numOfpair(arr, n, target);
    cout << numOfless(arr, n, target);
}