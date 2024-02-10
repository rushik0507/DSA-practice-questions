#include <bits/stdc++.h>
using namespace std;

void buildTree(vector<long long> &arr, vector<long long> &tree, long long start, long long end, long long index)
{
    if (start == end)
    {
        tree[index] = arr[start];
        return;
    }
    long long mid = (start + end) / 2;
    buildTree(arr, tree, start, mid, 2 * index);
    buildTree(arr, tree, mid + 1, end, 2 * index + 1);
    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
    return;
}

void update(vector<long long> &tree, long long start, long long end, long long index, long long u_index, long long val)
{
    if (start > u_index || end < u_index)
        return;
    if (start == end)
    {
        tree[index] = val;
        return;
    }

    long long mid = (start + end) / 2;

    update(tree, start, mid, 2 * index, u_index, val);
    update(tree, mid + 1, end, 2 * index + 1, u_index, val);

    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
}

long long query(vector<long long> &tree, long long start, long long end, long long index, long long query_start, long long query_end)
{
    if (start >= query_start && end <= query_end)
        return tree[index];
    if (end < query_start || start > query_end)
        return 1e9;
    long long mid = (start + end) / 2;
    long long l = query(tree, start, mid, 2 * index, query_start, query_end);
    long long r = query(tree, mid + 1, end, 2 * index + 1, query_start, query_end);
    return min(l, r);
}

int main()
{
    long long n;
    long long qn;
    cin >> n >> qn;
    vector<long long> arr(n);
    vector<long long> tree(4 * n + 1);
    for (long long i = 0; i < n; i++)
        cin >> arr[i];

    buildTree(arr, tree, 0, n - 1, 1);
    for (long long i = 0; i < qn; i++)
    {
        char c;
        cin >> c;
        int x, y;
        cin >> x >> y;
        if (c == 'q')
        {

            cout << query(tree, 0, n - 1, 1, x - 1, y - 1) << endl;
        }
        else if (c == 'u')
        {

            update(tree, 0, n - 1, 1, x - 1, y);
        }
    }
}