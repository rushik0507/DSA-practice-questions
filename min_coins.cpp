#include<bits/stdc++.h>
using namespace std;

int countIndianCoin(int n){
    int coins[9] = {1,2,5,10,20,50,100,200,500};
    int count =0 ;
    int i =8;
    while(n!=0){
        if(coins[i]<=n){
            n-=coins[i];
            count++;
        }
        else i--;
    }
    return count;
}

// recurcive

int noCoinsRecursive(int amount, vector<int> &coins ,vector<int> &dp  ){
    if(amount==0)return 0;
    if(dp[amount]!=-1)return dp[amount];

    int ans = INT_MAX;
    for(int c : coins){
        if(amount-c >=0){
            int subproblem = noCoinsRecursive(amount-c,coins,dp);
            ans = min(ans,subproblem+1);
        }
    }
    dp[amount]=ans;
    return ans;
}
int main(){
    int n;
    cin>>n;
    int amount;
    cin>>amount ;
    vector <int> dp(amount+1,-1);
    vector<int>coins(n);
    for(int i=0;i<n;i++  ){
        cin>>coins[i];
    }
    cout<<noCoinsRecursive(amount,coins,dp);
}