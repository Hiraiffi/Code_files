#include<iostream>
using namespace std;
#define N 5
//insertion sort
int main()
{
	int arr[N];
	
	for(int i=0;i<N;i++)
	{
		cin>>arr[i];
	}
	int key;
	int j;
	for(int i=1;i<N;i++)
	{
		key=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>key)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
	cout<<"Array: "<<endl;
	for(int i=0;i<N;i++)
	{
		cout<<arr[i]<<endl;
	}
	return 0;
}