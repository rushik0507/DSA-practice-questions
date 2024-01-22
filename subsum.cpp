#include <bits/stdc++.h>
using namespace std;

vector<int> subsets(vector<int> &nums)
{
    int n = nums.size();
    vector<int> sum;
    vector<int> subset;
    for (int i = 1; i <= (1 << n) - 1; i++)
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
        int subsum = 0;
        cout << "->";
        for (int i = 0; i < subset.size(); i++)
        {
            cout << subset[i] << " ";
            subsum += subset[i];
        }
        cout << endl;
        sum.push_back(subsum);
        subset.clear();
    }

    sort(sum.begin(), sum.end());
    for (int x : sum)
    {
        cout << x << " ";
    }
    cout << endl;
    return sum;
}

int binarySearchNearestSmaller(vector<int> &arr, int target)
{
    int left = 0, right = arr.size() - 1;
    int result = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] < target)
        {
            result = arr[mid];
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return result;
}

int binarySearchNearestBigger(vector<int> &arr, int target)
{
    int left = 0, right = arr.size() - 1;
    int result = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] > target)
        {
            result = arr[mid];
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return result;
}
int numOfsubset(vector<int> &nums, int n, int a, int b)
{
    vector<int> first_half;
    vector<int> second_half;
    for (int i = 0; i < n / 2; i++)
    {
        first_half.push_back(nums[i]);
    }
    for (int i = n / 2; i < n; i++)
    {
        second_half.push_back(nums[i]);
    }
    int count = 0;
    first_half = subsets(first_half);
    second_half = subsets(second_half);
    for (int i = 0; i < first_half.size(); i++)
    {
        if (a <= first_half[i] && first_half[i] <= b)
        {
            count++;
            count += binarySearchNearestBigger(second_half, b - first_half[i]) - binarySearchNearestSmaller(second_half, a - first_half[i]);
        }
    }
    return count;
}

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> nums;
    vector<int> sum;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    cout << numOfsubset(nums, n, a, b);
    return 0;
}

// spoj  min each child page can read book allocation
// painters partition
// 