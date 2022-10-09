/*
Insert lower case characters just after only upper case characters of the same alphanumeric symbol. The size of array(N) should be greater than 0 and less than equal to 20. If the size of array is not in the mention range then program should display “Invalid size of array”. And if no upper case character is present then display same array.

Input Format

First line will represent size of array and second line will represent elements of array.

Constraints

N > 0 && N <= 20, Where N is the size of array

Output Format

Should display the resultant array after insertion of lower case crossponding to uppercase. If no upper case character is present then display same array.

Sample Input 0
20
H e L L O 2

Sample Output 0
H h e L l L l O o 2

Sample Input 1
24

Sample Output 1
Invalid size of array
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    char arr[21];
    int cnt=0;
    if(n>20 ||n<0){
        cout<<"Invalid size of array"<<endl;
    }
    else{
        for(int i=0;i<n;i++){
          cin>>arr[i];
            if(arr[i]==0){
                break;
            }
            cnt++;
        }
        for(int i=0;i<cnt;i++){
            if(arr[i]>=65 && arr[i]<=90){
                cout<<arr[i]<<" "<<char(arr[i]+32)<<" ";
            }
            else{
                cout<<arr[i]<<" ";
            }
        }
    }
    return 0;
}
