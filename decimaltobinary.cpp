#include <bits/stdc++.h>
using namespace std;

string binary(int n)
{
    string s = "";
    while (n > 0)
    {
        int rem = n % 2;
        s = to_string(rem) + s;
        n/=2;
    }
    return s;
}

int main()
{
    int n;
    cin >> n;
    int  m = INT_MIN<<1;
    cout << m<<endl;
    cout << ~(n)<<endl;
    cout << binary(n);
}