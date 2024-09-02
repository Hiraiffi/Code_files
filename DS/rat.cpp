#include<iostream>
using namespace std;
#define N 4

bool isValid(int arr[N][N], int x, int y, int sol[N][N])
{
    if ((x >= 0 && x < N) && (y >= 0 && y < N) && arr[x][y] == 1 && sol[x][y] == 0)
    {
        return true;
    }
    return false;
}

bool recurse(int arr[N][N], int r, int c, int sol[N][N])
{
    if (r == N - 1 && c == N - 1)
    {
        cout << "Hurrah!!!!!! Path Found" << endl;
        sol[r][c] = 1;
        return true;
    }
    if (isValid(arr, r, c, sol))
    {
        sol[r][c] = 1;
        if (recurse(arr, r + 1, c, sol) == 1 || recurse(arr, r, c + 1, sol) == 1)
        {
            return true;
        }
        sol[r][c] = 0;
        return false;
    }
    return false;
}

int main()
{
    int arr[N][N] = {
        {1, 0, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 1, 1},
        {1, 1, 0, 1}};
    int sol[N][N] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}};
    bool res = recurse(arr, 0, 0, sol);

    if (res)
    {
        cout << "Solution exists: " << endl;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "Solution doesn't exist" << endl;
    }

    return 0;
}
