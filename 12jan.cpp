#include <bits/stdc++.h>
using namespace std;

void findnumber(int p, int close, int open, int n, vector<string> &ans)
{
    cout << "close:" << close;
    static char s[1000];
    if (close == n)
    {
        ans.push_back(s);
        return;
    }
    else
    {
        if (open > close)
        {
            s[p] = ']';
            cout << "case1" << endl;
            findnumber(p + 1, close + 1, open, n, ans);
        }
        if (open < n)
        {
            s[p] = '[';
            cout << "case2" << endl;
            findnumber(p + 1, close, open + 1, n, ans);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<string> ans;
    char s[2 * n];
    findnumber(0, 0, 0, n, ans);
    for (string a : ans)
    {
        cout << a << endl;
    }
}