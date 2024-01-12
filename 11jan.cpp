// #include <iostream>
// using namespace std;

// int toPower(int n,int a)
// {
//     if(n==0)return 1;
//     if(n%2==0){
//         return toPower(n/2,a)*toPower(n/2,a);
//     }
//     else{
//         return toPower(n/2,a)*toPower(n/2,a)*a;
//     }
// }

// int bitPower(int a,int n){
//     int ans = 1;
//     while(n>0){
//         int last_bit = n&1;
//         if(last_bit==1){
//             ans = ans*a;
//         }
//         a =a*a;
//         n=n>>1;
//     }
// }
// int main()
// {
//     int n,a;
//     cin >>a>> n;
//     cout<<toPower(n,a)<<endl;
//     cout<<bitPower(n,a);
// }


// CPP Program to demonstrate the 
// implementation of multiset
#include<bits/stdc++.h>
using namespace std;

int firstUniqChar(string s) {
    
        map<char,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        for(int i=0;i<s.length();i++){
            cout << mp[s[i]] << endl;
            if(mp[s[i]]==1)
            return i;
        }
        return -1;
}

int main(){
    string s;
    cin >> s;
    cout<<firstUniqChar(s);
}