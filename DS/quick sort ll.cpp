#include<iostream>
using namespace std;

class node {
	public:
	    int num;
	    node *ptr;
	node()
	{
		num = 0;
		ptr = NULL;
	}
	node(int num)
	{
		this->num =num;
		ptr = NULL;
	}
};
class linkedList 
{
	public:
		node *head;
		
	linkedList()
	{
		head=NULL;
	}
	void insert(int number,int val)
	{
    	node *temp=head;
		node *n = new node(number);
		
		if(head == NULL)
		{
			head = n;
			return;
		}
        else 
		{  
		    while(temp!= NULL)
		    {
		    	if(temp->num==val)
		    	{
		    		n->ptr = temp ->ptr;
		        	temp->ptr = n;
		        	break;
				}
				temp = temp->ptr;
		    }
	    }
    }
    int length()
    {
    	int l=0;
    	node *temp=head;
    	while(temp!=NULL)
    	{
    		l++;
    		temp=temp->ptr;
		}
		return l;
	}
    void insertAt(int val,int pos)
    {
    	int len=length();
    	node *temp=head;
    	node *n=new node(val);
    	
    	if(head==NULL)
    	{
    		head=n;
    		return;
		}
    	if(pos<0 || pos>len+1)
    	{
    		cout<<"List out of bound"<<endl;
    		return;
		}
		if(pos==1)
		{
			n->ptr=head;
			head=n;
		}
		else if(pos==len)
		{
			while(temp!=NULL)
			{
				temp=temp->ptr;
			}
			temp->ptr=n;	
		}
		else
		{
			temp=head;
    		node *temp2=temp;
    		
    	    for(int i=0;i<pos-1;i++)
    	    {
    	    	temp2=temp;
    	    	temp=temp->ptr;
		    }
		    temp2->ptr=n;
		    n->ptr=temp;
	}
}
    node* operator[](int size)
    {
    	node *temp=head;
    	while(size--)
    	{
    		temp=temp->ptr;
		}
		return temp;
	}
    void display()
    {
    	node* temp=head;
    	
    	if(head==NULL)
    	{
    		cout<<"List doesn't exists"<<endl;
   		}
   		cout<<"List: "<<endl;
	    while(temp!=NULL)
    	{
    	    cout<<temp->num<<" ";
    		temp=temp->ptr;
		}
		cout<<endl;
	}
};
int partition(linkedList l,int start,int end)
{
	int i=start;
	int pivot;
	pivot=(l[start])->num;
	
	for(int j=start+1;j<=end;j++)
	{
		if((l[j])->num<pivot)
		{
		    i++;
		    swap((l[i])->num,(l[j])->num);
		}
	}
	swap(l[start]->num,(l[i])->num);
	return i;
}
void quicksort(linkedList l,int start,int end)
{
	if(start>=end)
	{
		return;
	}
	else
	{
		int mid = partition(l,start,end);
	 
	   quicksort(l,start,mid-1);
	    quicksort(l,mid+1,end);
	}
}
int main()
{
//	linkedList l;
//	l.insert(1,0);
//	l.insert(5,1);
//	l.insert(2,5);
//	l.insert(20,2);
//	l.insert(1,20);
//	l.insert(100,5);
//	l.display();
//	quicksort(l,0,5);
//	l.display();
	linkedList l2;
	l2.insertAt(12,1);
	l2.insertAt(2,2);
	l2.insertAt(5,3);
	l2.insertAt(2,1);
//	l2.insertAt(20,6);
	l2.display();
}