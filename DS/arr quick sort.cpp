#include<iostream>
using namespace std;
//Given an array arr[ ] of length N consisting cost of N toys and an integer K the amount with you.
//The task is to find the maximum number of toys you can buy with K amount.
int partition(int arr[],int p,int q)
{
	int i=p;
	int pivot;
	pivot=arr[i];
	for(int j=p+1;j<=q;j++)
	{
		if(arr[j]<pivot)
		{
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[p],arr[i]);
	return i;
}
int max1(int arr[],int N,int K)
{
	int sum=0,count=0;
	for(int i=0;i<N;i++)
	{
		if((sum+arr[i])<=K)
		{
			sum+=arr[i];
			count++;
		}
		else
		{
			break;
		}
	}
	return count;
}
int partition1(int arr[],int start,int end)
{
	int i=start;
	int pivot=arr[start];
	
	for(int j=start+1;j<=end;j++)
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
void quicksort(int arr[],int start,int end)
{
	if(start>=end)
	{
		return;
	}
	else
	{
		int mid=partition1(arr,start,end);
		quicksort(arr,start,mid-1);
		quicksort(arr,mid+1,end);
	}
}
int main()
{
	//N = 7
    //K = 50
	int arr[ ]={20,30,50};
	
	int N=3;
	int K=100;
	quicksort(arr,0,2);
	for(int i=0;i<3;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	cout<<max1(arr,N,K);
	return 0;
	
}