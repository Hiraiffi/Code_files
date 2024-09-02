#include<iostream>
using namespace std;
#define N 5
int sol[N][N];
bool validate(int maze[N][N], int x, int y)
{
    if (x >= 0 && x < N && y >= 0 && y < N)
    {
        return true;
    }
    return false;
}

bool recurse(int maze[N][N], int r, int c)
{
    int key = maze[r][c];

    if (validate(maze, r, c))
    {  
        if (key == 0)
        {
        cout << "Found" << endl;
        for (int i = 0; i < N; i++)
        {
        for (int j = 0; j < N; j++)
        {
            cout << sol[i][j] << " ";
        }
        cout << endl;
        }

        return true;
    }
    	sol[r][c]=key;
        if (recurse(maze, r + key, c) == true)
        {
            return true;
        }
        if (recurse(maze, r, c + key) == true)
        {
            return true;
        }
        sol[r][c]=0;
        return false;
    }
    return false;
}

int main()
{
    int maze[N][N] = {
        {2,2,4,4,3},
        {3,4,3,2,2},
        {1,2,0,3,2},
        {3,2,2,1,2},
        {3,3,4,3,1}
    };

    int startRow = 0;
    int startCol = 0;

    cout << "Maze:" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }

    bool result = recurse(maze, startRow, startCol);

    if (!result)
    {
        cout << "Not Found" << endl;
    }

    return 0;
}
