#include <bits/stdc++.h>
using namespace std;

int minimumWindow(int arr[], int n)
{
    int mx = INT_MIN;
    int mn = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        mx = max(arr[i], mx);
        mn = min(arr[i], mn);
    }

    int mx_index = -1;
    int mn_index = -1;
    int ans = n + 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] == mx)
        {
            mx_index = i;
            if (mn_index != -1)
            {
                int lan = abs(mx_index - mn_index) + 1;
                ans = min(ans, lan);
            }
        }
        if (arr[i] == mn)
        {
            mn_index = i;
            if (mx_index != -1)
            {
                int lan = abs(mx_index - mn_index) + 1;
                ans = min(ans, lan);
            }
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i]; 
    }
    cout<<minimumWindow(arr,n);
}
