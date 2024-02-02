#include <bits/stdc++.h>
using namespace std;

int increasingSubsequence(vector<int> &arr)
{
    int n = arr.size();
    int ans = 0;
    vector<int> dp(n);
    for (int i = 0; i < n; i++)
    {
        int mx = 0;
        for (int j = 0; j < i; j++)
        {
            if (i == 0)
                dp[0] = 1;
            else if (arr[j] < arr[i])
            {
                mx = max(mx, dp[j]);
            }
        }
        dp[i] = mx + 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (dp[i] > ans)
            ans = dp[i];
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << increasingSubsequence(arr);
}
