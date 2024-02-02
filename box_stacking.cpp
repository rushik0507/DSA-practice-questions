#include <bits/stdc++.h>
using namespace std;

bool canPlace(vector<int> i, vector<int> j)
{
    return (i[0] > j[0] && i[1] > j[1]);
        
}

bool compareInterval(vector<int> i1, vector<int> i2)
{
    return (i1[0] > i2[0]);
}

int increasingSubsequence(vector<vector<int>> &box)
{
    int n = box.size();
    int ans = 0;
    sort(box.begin(), box.end());
    vector<int> dp(n);
    for (int i = 0; i < n; i++)
    {
        cout << box[i][0] << box[i][1] << box[i][2] << endl;
    }
    dp[0] = box[0][2];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (canPlace(box[i], box[j]))
            {
                dp[i] = max(dp[i], dp[j] + box[i][2]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout<<dp[i]<<" ";
        if (dp[i] > ans)
            ans = dp[i];
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    cout << increasingSubsequence(arr);
}
