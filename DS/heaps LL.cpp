#include<iostream>
#include<queue>
using namespace std;
class node
{
	public:
		int data;
		node *lchild;
		node *rchild;
	node()
	{
		data=0;
		lchild=NULL;
		rchild=NULL;
	}
	node(int data)
	{
		this->data=data;
		lchild=NULL;
		rchild=NULL;
	}
};
class heap
{
	public:
	int arr[100];
	int ind;
	heap()
	{
		for(int i=0;i<100;i++)
		{
			arr[i]=0;
		}
		ind=0;
	}
	void insert(int val)
	{
		arr[ind]=val;
		ind++;
	}
	void heapifyUp()
	{
		int index= 100;
		while(index > 0)
		{
			int parent = (index-1) / 2;
			if(arr[index] < arr[parent])
			{
				swap(arr[index],arr[parent]);
				index=parent;
			}
			else
			{
				break;
			}
		}
	}	
	void heapifydown()
	{
		int index=0;
		while(1)
		{
			int left = 2 * index + 1;
			int right = 2 * index + 2;
			int largest=index;
			if(right>=100)
			{
				break;
			}
			if(left < 100 && arr[left] < arr[largest])
			{
				largest=left;
			}
			if(right < 100 && arr[right] < arr[largest])
			{
				largest=right;
			}
			if(largest!=index)
			{
				swap(arr[index],arr[largest]);
				index=largest;
			}else
			{
				break;
			}
		}
	}
	void display()
	{
		for(int i=0;i<ind;i++)
		{
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
};
int main()
{
	heap h;
	node* root;
	h.insert(5);
	h.insert(10);
	h.insert(15);
	h.insert(12);
	h.insert(2);
	h.display();
	
	return 0;
}