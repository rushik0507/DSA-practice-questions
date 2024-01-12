#include<iostream>
using namespace std;

// int main(){
//     int n;
//     cin>>n;
//     int start = 0;
//     int end = n;
//     int mid;
//     float ans;
//     while(start <= end){
//         mid=(start+end)/2;
//         if(mid*mid > n){
//             end = mid-1;
//         }
//         else if (mid*mid <=n)
//         {
//             ans = mid;
//             start =mid+1;
//         }
//     }
//     float inc = 0.1;
//     for(int i =0 ;i<3;i++){
//         while (ans*ans <= n)
//         {
//             ans +=inc;
//         }
//         ans -= inc;
//         inc = inc/10;
        
//     }
//     cout << ans;
// }


int square(int a ,int n){
    if(n==0)return 1;
    if(n%2==0)
    return square(a,n/2)*square(a,n/2);
    else return a*square(a,n/2)*square(a,n/2);
}
int main(){
    int n,a;
    cin>>a>>n;
    cout << square(a,n);
}