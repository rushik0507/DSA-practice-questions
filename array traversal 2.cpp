/*
Akash got an interesting assignment. He got K balls, every ball has its diameter inscribed. Write a programming solution, to help akash to find the largest ball. He is supposed to solve assignment N times.

Input Format

1st line contain N(nos. of problem)
2nd line contain space separated diameter from K balls
Constraints

K=6
N>0 & N<5
Output Format

Return diameter of highest ball. For Every assignment, output should be on a new line.

Sample Input 0

2
4 1 8 34 23 18 
34 23 45 11 7 55
Sample Output 0

34
55
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int i;
    int n[6] = {0};
    int N;
    cin >> N;
    int max;
    int arr[N];
    for (int j = 0; j < N; j++)
    {
        for (i = 0; i < 6; i++)
        {
            cin >> n[i];
        }
        for (i = 0; i < 6; i++)
        {
            if (n[i] > max)
            {
                max = n[i];
            }
        }
        arr[j] = max;
    }
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}
