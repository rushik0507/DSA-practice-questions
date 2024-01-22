// https://www.spoj.com/problems/PRATA/

#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &ranks, int k, int target)
{
    int sum = 0;
    for (int i = 0; i < ranks.size(); i++)
    {
        int temp = ranks[i];
        int j = 2;
        while (temp <= target)
        {
            sum++;
            temp = temp + (j * ranks[i]);
            j++;
        }
    }
    if (sum >= k)
    {
        return true;
    }
    return false;
}
int minoftime(vector<int> &ranks, int k)
{
    int ans = 0;
    int start = 0;
    int sum = 0;
    int end = k / 2 * (2 * ranks[0] + (k - 1) * ranks[0]);
    while (start <= end)
    {
        int mid = (start + end) / 2;
        // cout<<"mid:"<<mid;
        if (!check(ranks, k, mid))
        {
            start = mid + 1;
        }
        else
        {
            ans = mid;
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> k >> n;
        vector<int> ranks;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            ranks.push_back(temp);
        }
        cout << minoftime(ranks, k) << endl;
    }
}
