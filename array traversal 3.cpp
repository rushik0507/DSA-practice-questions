/*
Priya has purchased 6 different types of products in the shop. Now assist Priya to find the total cost of items purchased.

Sample Case 1:
6
200 50 100 60 70 80
Output
560

Input Format

Input contains two lines of input. First line contains number of elements,i.e. N Second line of Input contains space separated N numbers
Input:
6
100 50 60 70 80 90

Constraints

N>0, where N is the number of products purchased

Output Format

Output contains sum of all input numbers. 

Sample Case 1:
6
200 50 100 60 70 80
Output
560

Sample Input 0
6
100 50 60 70 80 90

Sample Output 0
450
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N;
    cin>> N;
    if(N<0){
        exit(0);
    }
    int arr[N];
    for (int i=0;i<N;i++){
        cin>> arr[i];
    }
    int sum =0;
    for (int i= 0; i<N ;i++){
        sum=sum+arr[i];
    }
    cout<<sum;
    return 0;
}
