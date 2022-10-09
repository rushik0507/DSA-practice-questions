/*
Alice went for shopping and bought 8 goods costing different prices. At the time of billing she realises that she did not have enough money. Now, she have decided to remove the item costing maximum amount and replace it with another item whose price is same as the item costing minimum amount. Help Alice and display final prices on the screen.

Note: if more than one element cost maximum price, replace the first item.

Example 1: Input: 250 1000 50 20 10 100 200 25 Output: 250 10 50 20 10 100 200 25

Example 2: Input: 2500 2500 50 20 10 100 200 25 Output: 10 2500 50 20 10 100 200 25

Input Format

Input Format:

Sample Input: 250 1000 50 20 10 100 200 25

Constraints

8 items prices are required

Output Format

Prints the final prices of different items after replacing

Sample Output: 10 2500 50 20 10 100 200 25

Sample Input 0

250 250 250 250 250 250 250 250
Sample Output 0

250 250 250 250 250 250 250 250
*/
#include <iostream>
using namespace std;

int main()
{
    int maxp = 0;
    int minp = 0;
    int arr[8] = {0};
    for (int i = 0; i < 8; i++)
    {
        cin >> arr[i];
    }
    int max = arr[0];
    for (int i = 1; i < 8; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            maxp = i;
        }
    }
    int min = arr[0];
    for (int i = 0; i < 8; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            minp = i;
        }
    }
    if (max == min)
    {
        for (int i = 0; i < 8; i++)
        {
            cout << arr[i] << " ";
        }
        exit(0);
    }
    arr[maxp] = arr[minp];
    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }
}
