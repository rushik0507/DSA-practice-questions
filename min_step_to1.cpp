#include <bits/stdc++.h>
using namespace std;

// recurcive

int noStep(int n, vector<int> &dp)
{
    if (n == 1)
        return 0;
    if (dp[n] != -1)
        return dp[n];

    int ans = noStep(n - 1, dp)+1;
    if (n % 2 == 0)
        ans = min(ans, noStep(n / 2, dp) + 1);
    if (n % 3 == 0)
        ans = min(ans, noStep(n / 3, dp) + 1);
    dp[n] = ans;
    return ans;
}



int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << noStep(n, dp);
}