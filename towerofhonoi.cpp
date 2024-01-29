#include<bits/stdc++.h>
using namespace std;

void hanoi(char a,char c,char b,int n){
    if(n==0)return;
    hanoi( a, b, c,n-1);
    cout<< a <<"->"<< c<<endl;
    hanoi(c,a,b,n-1);
}
int main(){
    int n;cin>>n;
    hanoi('a','c','b',n);
}