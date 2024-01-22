// https://www.spoj.com/problems/PRATA/

#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &ranks, int k, int target)
{
    cout<<target<<endl;
    int sum = 0;
    for (int i = 0; i < ranks.size(); i++)
    {
        if (ranks[i] > target)
        {
            sum =sum + (ranks[i]-target);
        }
        cout<<ranks[i]<<" "<<sum<<endl;
    }
    if (sum >= k)
        return true;
    else
        return false;
}
int maxheigth(vector<int> &ranks, int k)
{
    int ans = 0;
    int start = 0;
    int sum = 0;
    int end = 0;
    for (int i = 0; i < ranks.size(); i++)
    {
        if (ranks[i] > end)
        {
            end = ranks[i];
        }
    }
    cout<<end<<endl;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (check(ranks, k, mid))
        {
            cout<<"start"<<endl;
            ans = mid;
            start = mid + 1;
        }
        else
        {
            cout<<"end"<<endl;
            end = mid - 1;
        }
    }
    return ans;
}

int main()
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
    cout << maxheigth(ranks, k) << endl;
}
