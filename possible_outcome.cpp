#include<bits/stdc++.h>
using namespace std;
vector<string> s = {" ","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
void possible_string(string input,int i,string output){
    if(i==input.length()){
        cout<<output<<endl;
        return;
    }
    int digit = input[i]-'0';
    if(digit==0)return possible_string(input,i+1,output);
    for(char c: s[digit]){
        possible_string(input,i+1,output+c);
    }
}

int main(){
    string input;
    cin>>input;
    possible_string(input,0,"");
}