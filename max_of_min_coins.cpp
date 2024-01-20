#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &coins, int k, int target)
{
    int sum = 0;
    // cout << target << endl;
    for (int i = 0; i < coins.size(); i++)
    {
        sum += coins[i];
        cout << "->" << sum;
        if (sum >= target)
        {
            // cout << endl
                //  << "cut" << sum << " " << k << endl;
            sum = 0;
            k--;
        }
        if (k == 0)
        {
            // cout << "true" << endl;
            return true;
        }
    }
    cout << endl;

    // cout << "false" << endl;
    return false;
}
int minofcoins(vector<int> &coins, int k)
{
    int ans = 0;
    int start = 0;
    int sum = 0;
    for (int i = 0; i < coins.size(); i++)
    {
        sum += coins[i];
    }
    int end = sum;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (check(coins, k, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> coins;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        coins.push_back(temp);
    }
    cout << minofcoins(coins, k);
}