#include<iostream>
using namespace std;
#define N 3
int main()
{
	int array[N][N];
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cin>>array[i][j];
		}
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			int min;
			int min1;
			min=i;
			min1=j;
			
			for(int k=i;k<N;k++)
        	{
        		int l=j;
    		    for(;l<N;l++)
     		    {
     		    	if(array[k][l]<array[min][min1])
     		    	{
     		    		min=k;
     		    		min1=l;
					}
     		    }
				l=0;
     		}
     		if(min!=i || min1!=j)
     		{
     			swap(array[i][j],array[min][min1]);
			}
   		}
	}
	cout<<"Array: "<<endl;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout<<array[i][j]<<endl;
		}
	}
	return 0;
}