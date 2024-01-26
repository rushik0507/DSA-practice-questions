#include<bits/stdc++.h>
using namespace std;

vector<int> sortedtarray(vector<vector<int>> &arr , int k){
    vector<int>sortedtarray;
    vector<int>index(k,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<int>>pq;
    for(int i=0;i<k;i++){
        pq.push({arr[i][0],i});
    }
    while(!pq.empty()){
        pair<int,int>cur = pq.top();
        sortedtarray.push_back(cur.first);
        index[cur.second]++;
        pair<int,int>temp = {arr[cur.second][index[cur.second]],cur.second};
        pq.push(temp);
    }
}


int main(){

}