#include<iostream>
using namespace std;

int main()
{
	int M=5,N=2;
	int arrayA[M];
	int arrayB[N];
	int arrayC[M*N];
	
	for(int i=0;i<M;i++)
	{
		cin>>arrayA[i];
	}
	for(int i=0;i<N;i++)
	{
		cin>>arrayB[i];
	}
	for(int i=0;i<M;i++)
	{
		arrayC[i]=arrayA[i];
	}
	for(int j=0;j<N;j++)
	{
		arrayC[j]=arrayB[j];
	}
	for(int i=1;i<N;i++)
	{
		int temp=i;
		int j=i-1;
		while(j>=0 && arrayC[j+1]>temp)
		{
			arrayC[j+1]=arrayC[j];
			j--;
		}
		arrayC[j+1]=temp;
	}
	for(int i=0;i<M*N;i++)
	{
		cout<<arrayC[i]<<endl;
	}
	
	return 0;
}