#include<iostream>
using namespace std;

void Merge(int arr[],int left,int mid,int right);

void MergeSort(int arr[],int left,int right)
{
	if(left>=right)
	{
		return;
	}
	int mid=(left+right)/2;
	MergeSort(arr,left,mid);
	MergeSort(arr,mid+1,right);
	Merge(arr,left,mid,right);
}
void Merge(int arr[],int const left,int const mid,int const right)
{
	int sizeLeft=mid-left+1;
	int sizeRight=right-mid;
	
	int arrLeft[sizeLeft];
	int arrRight[sizeRight];
	
	for(int i=0;i<sizeLeft;i++)
	{
		arrLeft[i]=arr[left+i];
	}
	for(int i=0;i<sizeRight;i++)
	{
		arrRight[i]=arr[mid+i+1];
	}
	int i=0,j=0,k=left;
	while(i<sizeLeft && j<sizeRight)
	{
		if(arrLeft[i]<=arrRight[j])
		{
			arr[k]=arrLeft[i];
			i++;
		}
		else
		{
			arr[k]=arrRight[j];
			j++;
		}
		k++;	
	}
	while(i<sizeLeft)
	{
		arr[k]=arrLeft[i];
		i++;
		k++;
	}
	while(j<sizeRight)
	{
		arr[k]=arrRight[j];
		j++;
		k++;
	}
}
int main()
{
	int arr[6]={1,55,255,12,5,21};
	MergeSort(arr,0,5);
	for(int i=0;i<6;i++)
	{
		cout<<"Array: "<<arr[i]<<endl;
	}
	return 0;
}