#include <iomanip>
#include<iostream>
#include<cstdlib>
using namespace std;

void printmatrix(float A[][4]);
void RowReduce(float A[][4]);

int main()
{
    float A[3][4] = {{5, 6, 7,   7},
                     {3, 2,  5, 7},
                     {2,  4, 3,  29}}; 

    printmatrix(A);
    RowReduce(A);
}

void printmatrix(float A[][4]) 
{
    int p=3;
    int q=4;

    for (int i=0; i<p; i++) {
            for (int j=0; j<q; j++) {
                    cout << setw(7) << setprecision(4) << A[i][j] << " ";
            }
            cout << endl;
    }

    cout << endl;
}

void RowReduce(float A[][4])
{
    const int nrows = 3;
    const int ncols = 4;

    int lead = 0; 

    while (lead < nrows) {
        float d, m;

        for (int r = 0; r < nrows; r++) 
		{ 
            d = A[lead][lead];
            m = A[r][lead] / A[lead][lead];

            for (int c = 0; c < ncols; c++) 
			{ 
                if (r == lead)
                    A[r][c] /= d;               
                else
                    A[r][c] -= A[lead][c] * m;  
            }
        }

        lead++;
        printmatrix(A);
    }
}