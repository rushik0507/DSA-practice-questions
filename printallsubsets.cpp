#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> ans;
    vector<int> subset;
    for (int i = 0; i <= (1 << n) - 1; i++)
    {
        int count = 0;
        int temp = i;
        while (temp > 0)
        {
            if (temp & 1 == 1)
                subset.push_back(nums[count]);
            count++;
            temp = temp >> 1;
        }
        ans.push_back(subset);
        subset.clear();
    }
    return ans;
}

int main()
{
}