#include<bits/stdc++.h>
using namespace std;

int getIthbit(int n,int i){
    return (n>>i-1&1);
}

int setIthbit(int n,int i){
    return(n | (1<< i-1));
}

int clearIthbit(int n,int i){
    return(n&~(1<<i-1));
}

int updateIthbit(int n,int i,int bit){
    if(bit==1){
        return setIthbit( n, i);
    }
    else{
        return getIthbit( n, i);
    }

    // return clearIthbit(n,i) | (bit<<i-1);
}

int countAllbit(int n,int i){
    int count =0;
    while(n!=0){
        if(n&1==1)count++;
        n=n>>1;
    }
    // while(n){
    //     n= n&(n-1);
    //     count++;
    // }
    return count;
}

int clearRangeofBits(int n,int start , int end){
    int a  = (~0)<<(start+1);
    int b = (1<<end+1)-1;
    int mask = a|b;
    return mask&n;
}
int main(){
    int n;
    int i;cin>>n>>i;
    cout<<getIthbit(n,i)<<endl;
    cout<<setIthbit(n,i)<<endl;
    cout<<clearIthbit(n,i)<<endl;
    cout<<updateIthbit(n,i,0)<<endl;
    cout<<countAllbit(n,i)<<endl;

 }