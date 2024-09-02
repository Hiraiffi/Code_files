#include<iostream>
using namespace std;
class Node
{
	public:
		int num;
		Node *ptr;
		Node()
		{
			num=0;
			ptr=NULL;
		}
		Node(int num)
		{
			this->num=num;
			ptr=NULL;
		}
};
class Linkedlist
{
	public:
	Node *head;
	int size;
	
	Linkedlist()
	{
		head=NULL;
	}
	void calc_size()
	{
		Node*temp=head;
		while(temp!=NULL) {
		size++;
		temp=temp->ptr;}
	}
	void Insert(int num,int x)
	{
		Node *temp=head;
		Node *n=new Node(num);
		
		if(head==NULL)
		{
			head=n;
			return;
		}
		else
		{
			while(temp!=NULL)
			{
				if(temp->num==x)
				{
					temp->ptr=n->ptr;
					temp->ptr=n;
					break;
				}
				temp=temp->ptr;
			}
		}
	}
	void display()
	{
		Node *temp=head;
		if(head==NULL)
    	{
    		cout<<"List doesn't exists"<<endl;
   		}
	    while(temp!=NULL)
    	{
    		if(temp->ptr==NULL)
    		{
    			cout<<temp->num;
    			return;
			}
			else
			{
    	        cout<<temp->num<<"->";
    		    temp=temp->ptr;
    		}
		}
	}
	Node* operator[](int mid)
    {
    	Node *temp=head;	
    	while(mid--)
    	{
    		temp=temp->ptr;
    	}
    	return temp;
    }
};
void Merge(Linkedlist l,int const left,int const mid,int const right)
{
	int sizeleft=mid-left+1;
	int sizeright = right - mid;
	int *leftarray=new int[sizeleft];
	int *rightarray=new int[sizeright];
	
	for(int i=0;i<sizeleft;i++)
	{
		leftarray[i]=(l[left+i])->num;
	}
	for(int i=0;i<sizeleft;i++)
	{
		rightarray[i]=(l[mid+i+1])->num;
	}
	int i,j,k=left;
	
	while(i<sizeleft && j<sizeright)
	{
		if(leftarray[i] <= rightarray[j])
		{
			(l[k])->num=rightarray[j];
			j++;
		}
		else
		{
			(l[k])->num=leftarray[i];
			i++;
		}
		k++;
	}
	while(i<sizeleft)
	{
		(l[k])->num=leftarray[i];
		k++;
		i++;
	}
	while(j<sizeright)
	{
		(l[k])->num=leftarray[j];
		k++;
		j++;
	}
	delete [] leftarray;
	delete [] rightarray;
}
void MergeSort(Linkedlist l,int start,int  end)
{
	Node *temp=l.head;
	int mid;
	
	if(start>=end)
	{
		return;
	}
	while(temp->ptr!=NULL)
	{
		mid=(l.head->num+temp->num)/2.0;
		temp=temp->ptr;
	}
	
	MergeSort(l,start,mid);
	MergeSort(l,mid+1,end);
	Merge(l,start,mid,end);
}
int main()
{
	Linkedlist l;
	l.Insert(4,0);
	l.Insert(2,4);
	l.Insert(8,2);
	l.Insert(3,8);
	l.Insert(12,3);
	l.Insert(11,12);
	l.Insert(1,11);
	l.Insert(18,1);
	l.Insert(22,18);
	l.calc_size();
	MergeSort(l,0,l.size-1);
	l.display();
	
	return 0;
}