#include<iostream>
using namespace std;

int main()
{
	int row,column;
	
	cout<<"Enter the size of rows: ";
	cin>>row;
	cout<<"Enter the size of column: ";
	cin>>column;
	
	int MatrixA[row][column],MatrixY[row],MatrixX[row],i,j,k;
	
	for(i=0;i<row;i++)
	{
		for(j=0;j<column;j++)
		{
			cout<<"Enter the values of Matrix: ";
			cout<<"a["<< i<<"]"<< j<<"]= ";
			cin>>MatrixA[i][j];
		}
	}
	for(i=1;i<row-1;i++)
	{
		cin>>MatrixY[i];
	}
	int mik=0;
	for(i=1;i<column-1;i++)
	{
		for(j=i+1;j<row;j++)
		{
			mik = MatrixA[j][i]/MatrixA[i][i];
			for(k=i;k<column;k++)
			{
				MatrixA[j][k]-=mik * MatrixA[i][k];
			}
			MatrixY[j]-=mik*MatrixY[i];
		}
	}
	MatrixX[row-1] = MatrixY[row-1] / MatrixA[row-1][column-1];
	int sh,sum=0;
	for(i=row-2;i>=0;i--)
	{
		sum = MatrixY[i];
	    for(j=i+1;j<=column-1;j++)
	    {
	    	sh = MatrixA[i][j]*MatrixX[j];
	    	sum-=sh;
	    	MatrixX[i] = sum / MatrixA[i][i];
	    }
	}
	for(int i=1;i<=row;i++)
	{
		cout<<"X: "<<i+1<<MatrixX[i]<<endl;
	}
}