#include <bits/stdc++.h>
using namespace std;
int equilibrium(int m, int arr[][4])
{
    int sum[m][m];
    int ramu = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(i==0 && j==0){
                sum[0][0] = arr[0][0];
            }
            else if (i == 0)
            {
                sum[i][j] = sum[i][j - 1] + arr[i][j];
            }
            else if (j == 0)
            {
                sum[i][j] = sum[i - 1][j] + arr[i][j];
            }
            else
            {
                sum[i][j] = sum[i - 1][j] + sum[i][j - i] + arr[i][j]- sum[i - 1][j - 1] ;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }
    // for (int i = 0; i < m; i++)
    // {
    //     int q1, q2, q3, q4, temp = -1;
    //     for (int j = 0; j < m; j++)
    //     {
    //         q1 = sum[i][j];
    //         q2 = sum[i][m - 1] - q1;
    //         q3 = sum[m - 1][j] - q1;
    //         q4 = sum[m - 1][m - 1] - (q1 + q2 + q3);
    //     }
    //     cout << q1 << " " << q2 << " " << q3 << " " << q4 << " " << endl;
    //     temp = min(q1, min(q2, min(q3, q4)));
    //     ramu = max(ramu, temp);
    // }
    return ramu;
}

int main()
{
    int n = 4;
    int arr[4][4];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }
    cout << equilibrium(n, arr);
}