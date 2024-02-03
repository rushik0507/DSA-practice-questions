#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (n == 1)
    {
        cout << arr[0];
        return 0;
    }
    if (n == 2)
    {
        cout << min(arr[0], arr[1]);
        return 0;
    }
    int dp[n];
    dp[0] = arr[0];
    dp[1] = arr[1];
    dp[2] = arr[2];
    for (int i = 3; i < n; i++)
    {
        dp[i] = arr[i] + min(dp[i - 1], min(dp[i - 2], dp[i - 3]));
    }
    cout << +min(dp[n - 1], min(dp[n - 3], dp[n - 2]));
}
