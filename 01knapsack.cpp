#include <bits/stdc++.h>
using namespace std;

int knapSack(vector<int> &weight, vector<int> &price, int n, int c)
{
    if (n == 0 || c == 0)
        return 0;
    int pick = INT_MIN;
    if (weight[n - 1] <= c)
        pick = price[n - 1] + knapSack(weight, price, n - 1, c - weight[n - 1]);
    int notpick = knapSack(weight, price, n - 1, c);
    return max(pick, notpick);
}

int bottomKnapsack(vector<int> &weight, vector<int> &price, int n, int c){
    vector<vector<int>>dp(n+1,vector<int>(c+1,0));
    for(int i=1;i<n+1;i++){
        for(int j=1;i<c+1;j++){
            int pick =0;
            if(weight[i-1]<= c)pick = price[n-1]+dp[i][j-weight[i-1]];
            int notpick = dp[i-1][j];
            dp[i][j]=max(pick,notpick);
        }
    }
    return dp[n][c];
}

int main()
{
    int n;
    cin >> n;
    int cap;
    cin >> cap;
    vector<int> weight(n);
    vector<int> price(n);
    for (int i = 0; i < n; i++)
        cin >> weight[i];
    for (int i = 0; i < n; i++)
        cin >> price[i];
    for (int i = 0; i < n; i++)
    {
        cout << weight[i] << " " << price[i] << endl;
    }
    cout << bottomKnapsack(weight, price, n, cap);
}