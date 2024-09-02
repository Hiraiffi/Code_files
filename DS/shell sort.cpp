#include<iostream>
using namespace std;

void shellsort(int arr[],int n)
{
	
	for(int gap=n/2;gap>0;gap/=2)
	{
		for(int i=gap;i<n;i++)
		{
			int temp=arr[i];
			int j;
			for(j=i;j>=gap && arr[j-gap]>temp;j-=gap)
			{
				arr[j]=arr[j-gap];
			}
			arr[j]=temp;
		}
	}
}
void display(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	int arr[5]={43,12,3,87,1};
	
	shellsort(arr,5);
	display(arr,5);
	
	return 0;
}