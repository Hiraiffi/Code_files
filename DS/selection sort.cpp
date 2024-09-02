#include<iostream>
using namespace std;
#define N 4

// Function to sort a 2D array in ascending order
void Sort(int array[N][N])
{
    for(int j=0;j<N;j++)
    {
        for(int i=0;i<N;i++)
        {
            int min_idx=i;
            int min_idx2=j;
            int l=i;
            for(int k=j;k<N;k++)
            {
                for(;l<N;l++)
                {
                    if(array[l][k]<array[min_idx][min_idx2])
                    {
                        min_idx = l;
                        min_idx2 = k;
                    }
                }
                l=0;
            }
            if(min_idx!=i || min_idx2!=j)
            {
                swap(array[i][j],array[min_idx][min_idx2]);
            }
        }
    }
}
void print(int array[N][N])
{
    cout << "Original Array:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    Sort(array);

    cout << "Sorted Array:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

}
int main()
{
    int array[N][N] = {
        {2, 3, 2, 8}
,{9 ,4 ,54, 5}
,{1, 7, 4 ,11}
,{6 ,1, 9 ,2}
    };
    print(array);
    return 0;
}
