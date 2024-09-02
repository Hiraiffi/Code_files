#include<iostream>
using namespace std;

void shellsort(int arr[],int n)
{
	int gap;
	
	for(gap=n/2;gap>0;gap/=2)
	{
		for(int i=gap;i<n;i++)
		{
			int temp=arr[i];
			int j;
			for(j=i;j>=gap && arr[j-gap]>temp;j-=gap)
			{
				arr[j]=arr[j-gap];
			}
			arr[j-gap]=temp;
		}
	}
}
void selectionsort(int arr[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		int min=i;
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]<arr[min])
			{
				min=j;
			}
		}
		if(min!=i)
		{
			swap(arr[min],arr[i]);
		}
	}
}
void insertionsort(int arr[],int n)
{
	int key,j;
	for(int i=0;i<n;i++)
	{
		key = arr[i];
		j=i-1;
		while(j>=0 && arr[j]>key)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}
void merge(int arr[],int const start,int const mid,int const end)
{
	int sizeleft=left+mid+1;
	int sizeright=right-mid;
	
	int *arrayLeft=new int[sizeleft];
	int *arrayRight = new int[sizeright];
	for(int i=0;i<sizeleft;i++)
	{
		arrleft[i]=arr[start+i];
	}
	for(int j=0;j<sizeright;j++)
	{
		arrright[j]=arr[mid+1+j];
	}
	int i=0,j=0;k=start;
	while(i<sizeleft && j<sizeright)
	{
		if(arrayleft[i]<=arrRight[j])
		{
			arr[k]=arrleft[i];
			i++;
		}
		else
		{
			arr[k]=arrRight[j];
			j++;
		}
		k++;
	}
	while(i<sizeleft)
	{
		arr[k]=arrRight[i];
		i++;
		k++;
	}
	while(j<sizeright)
	{
		arr[k]=arrRight[j];
		j++;
		k++;
	}
}
void mergeSort(int arr[],int start,int end)
{
	if(start>=end)
	{
		return;
	}
	else
	{
		int mid=(start+end)/2;
		mergeSort(arr,start,mid);
		mergeSort(arr,mid+1,end);
		merge(arr,start,mid,end);
	}
}
void quicksort(int arr[],int start,int end)
{
	if(start>=end)
	{
		return;
	}
	else
	{
		int mid=partition(arr,start,end);
		quicksort(arr,start,mid-1);
		quicksort(arr,mid+1,end);
	}
}
int partition1(int arr[],int start,int end)
{
	int i=start;
	int pivot=arr[start];
	
	for(int j=start+1;j<end;j++)
	{
		if(arr[j]<pivot)
		{
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[start],arr[i]);
	
	return i;
}
//for j
int partition(int arr[],int start,int end)
{
	int i=end;
	int pivot=arr[i];
	
	for(int j=i-1;j>=start;j--)
	{
		if(arr[j]>pivot)
		{
			i--;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[end],arr[i]);
	
	return i;
}