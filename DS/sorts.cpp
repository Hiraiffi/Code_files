#include<iostream>
using namespace std;

class Sort {
public:
    void insertionSort(int arr[], int n) {
        int key, j;
        for (int i = 1; i < n; i++) {
            key = arr[i];
         	j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
	void selectionsort(int arr[],int n)
	{
		int min_idx=0;
		for(int i=0;i<n-1;i++)
		{
			min_idx=i;
			for(int j=i+1;j<n;j++)
			{
				if(arr[j]<arr[min_idx])
				min_idx=j;
			}
			if(min_idx!=i)
			{
				swap(arr[min_idx],arr[i]);
			}
		}
	}
	void mergeSort(int arr[],int start,int end)
	{
		if(start>=end)
		{
			return;
		}
		else{
			int mid = (start+end)/2;
			mergeSort(arr,start,mid);
			merge(arr,start,mid,end);
			mergeSort(arr,mid+1,end);
		}
	}
	void merge(int arr[],int start,int mid,int end)
	{
		int sizeleft=start+mid+1;
		int sizeright=mid-end;
		int *arrleft= new int [sizeleft];
		int *arrright=new int[sizeright];

		for(int i=0;i<sizeleft;i++)
		{
			arrleft[i]=arr[i];
		}
		for(int i=0;i<sizeright;i++)
		{
			arrright[i]=arr[i];
		}
		int i=0,j=0,k=start;
		while(i<sizeleft && j<sizeright)
		{
			if(arrleft[i]<=arrright[j])
			{
				arr[k]=arrleft[i];
				i++;
			}
			else
			{
				arr[k]=arrright[j];
				j++;
			}
		}
		k++;
		while(i>sizeleft)
		{
			arr[i]=arrleft[i];
			i++;
			k++;
		}
		while(j>sizeright)
		{
			arr[j]=arrright[j];
			j++;
			k++;
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
			int mid = partition(arr,start,end);
			quicksort(arr,start,mid-1);
			quicksort(arr,mid+1,end);
		}
	}
	int partition(int arr[],int start,int end)
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
			swap(arr[start],arr[i]);
		}
		return i;
	}
	void shellsort(int arr[],int n)
	{
		int gap;
		for(gap=n/2;gap>=0;gap/=2)
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
    void display(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int arr[5] = {12, 11, 13, 5, 6};
    Sort s;
    int n = sizeof(arr) / sizeof(arr[0]);
    s.insertionSort(arr, n);
    s.display(arr, n);
	s.selectionsort(arr,n);
	s.display(arr,n);
//	s.mergeSort(arr,0,5);
	s.quicksort(arr,0,5);
	s.display(arr,5);
    return 0;
}
