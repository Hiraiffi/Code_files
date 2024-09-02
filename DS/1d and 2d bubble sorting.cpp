#include<iostream>
using namespace std;
//void BubbleSort2(int arr[][2],int r,int c);
////1d array
//void BubbleSort(int arr[],int n)
//{
//	int temp;
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<n-i-1;j++)
//		{
//			if(arr[j]>arr[j+1])
//			{
//				temp=arr[j];
//				arr[j]=arr[j+1];
//				arr[j+1]=temp;
//			}
//		}
//	}
//}
void display1(int arr[][2],int r,int c)
{
	cout<<"2d Array: "<<endl;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cout<<arr[i][j]<<endl;
		}
	}
}
//void display(int arr[],int n)
//{
//	cout<<"1d Array: "<<endl;
//	for(int i=0;i<n;i++)
//	{
//		cout<<arr[i]<<" ";
//	}
//	cout<<endl;
//}
void insertionsort(int arr[][2],int r,int c)
{
	int temp[r*c];
	int k=0;
	int key,j;
	
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			temp[k]=arr[i][j];
			k++;
		}
	}
//	display(temp,r*c);
	for(int i=1;i<r;i++)
	{
		key=temp[i];
		j=i-1;
		while(j>=0 && temp[j]>key)
		{
			temp[j+1]=temp[j];
			j=j-1;
		}
		temp[j+1]=key;
	}
//	display(temp,r*c);
	k=0;
	for(int i=0;i<r;i++)
	{
		for (int j=0;j<c;j++)
		{
			arr[i][j]=temp[k];
			k++;
		}
	}
	display1(arr,2,2);
}
////2d array
//void BubbleSort2(int arr[][2],int r,int c)
//{
//	int temp;
//	int i=0;
//	if(r<0 || r>3)
//	{
//		cout<<"Array out of bound"<<endl;
//	}
//	for (int i = 0; i < c; i++) 
//    {
//    for (int j = 0; j < r; j++) 
//    {
//      for (int k = 0; k < r - j - 1; k++) 
//      {
//        if (arr[k][i] > arr[k+1][i]) 
//        {
//          swap(arr[k][i], arr[k+1][i]);
//        }
//      }
//    }
//    display1(arr,r,c);
//  }
//}

int main()
{
	int arr[10];
	int arr1[2][2];
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			cin>>arr1[i][j];
		}
	}
//	bubblesrt(arr1,2,2);
//	BubbleSort(arr,10);
//	BubbleSort2(arr1,2,2);
//	//display(arr,10);
//	display1(arr1,3,3);
    insertionsort(arr1,2,2);
	return 0;
}