#include <bits/stdc++.h>
using namespace std;

void print_board(vector<vector<string>> board)
{
    for (auto raw : board)
    {
        for (auto box : raw)
        {
            cout << box << " ";
        }
        cout << endl;
    }
}

bool ispossible(vector<vector<string>> board, int n, int i, int j)
{
    int temp = i;
    for (int x = temp; temp >= 0; temp--)
    {
        if (board[x][j] == "Q")
            return false;
    }
    int temp1 = i, tempj = j;
    while (i >= 0 && j >= 0)
    {
        if (board[temp1][tempj] == "Q")
            return false;
        temp1--;
        tempj--;
    }
    while (i >= 0 && j != n - 1)
    {
        if (board[i][j] == "Q")
            return false;
        i--;
        j++;
    }
    cout<<"true"<<endl;
    return true;
}

void possible_Board(vector<vector<string>> &board, int n, int i)
{
    if (i == n)
    {
        print_board(board);
        return;
    }
    for (int j = 0; j < n; j++)
    {
        if (ispossible(board, n, i,j))
        {
            board[i][j] = "Q";
            possible_Board(board, n, i + 1);
        }
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<string>> board(n, vector<string>(n, "."));
    print_board(board);
    possible_Board(board, n, 0);
}