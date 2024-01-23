#include <bits/stdc++.h>
using namespace std;

class Heap
{
public:
    vector<int> arr;
    Heap()
    {
        arr.push_back(-1);
    }
    void heapify(int index){
        int l = index*2;
        int r = index*2+1;
        int mx= index;
        if(l < arr.size() && arr[index] < arr[l]){
            mx=l;
        }
        if(r < arr.size() && arr[mx] < arr[r]){
            mx=r;
        }
        if(mx!=index){
            swap(arr[index],arr[mx]);
            heapify(mx);
        }
    }
    void push(int data)
    {
        arr.push_back(data);
        int index = arr.size() - 1;
        while (arr[index / 2] < data && index > 1)
        {
            swap(arr[index / 2], arr[index]);
            index = index / 2;
        }
    }
    void pop(){
        swap(arr[1],arr[arr.size()-1]);
        arr.pop_back();
        heapify(1);
    }
    void showheap(){
        for(int i=0;i<arr.size();i++){
            cout<< arr[i]<<" ";
        }
        cout<<endl;
    }
    void top(){
        if(arr.size()!=1)
        cout<<arr[1];
        else cout<<"heap is empty"<<endl;
    }
};

int main(){
    int n ;
    cin>>n;
    Heap hp;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        hp.push(temp);
    }
    hp.showheap();
    hp.pop();
    hp.showheap();
}