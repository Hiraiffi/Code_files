#include<iostream>
using namespace std;

class node
{
	public:
		int num;
		node *ptr;
	node()
	{
		num=0;
		ptr=NULL;
	}
	node(int num)
	{
		this->num=num;
		ptr=NULL;
	}
};
class Linkedlist
{
	public:
	node *head;
	node *tail;
		Linkedlist()
		{
			head=NULL;
			tail=NULL;
		}
		void Insert(int num)
		{
			node *n=new node(num);
			if(head==NULL)
			{
				head=n;
				tail=n;
				n->ptr=head;
				return;
			}
			else
			{
				tail->ptr=n;
				n->ptr=head;
				tail=n;
			}
		}
		void display()
        {
        	node* temp=head;
    	
        	if(head==NULL)
        	{
        		cout<<"List doesn't exists"<<endl;
     		}
    	    do
			{
        		if(temp->ptr==head)
        		{
        			cout<<temp->num;
				}
				else
				{
					cout<<temp->num<<"->";
				}
       	    	temp=temp->ptr;
	    	}
			while(temp!=head);
			cout<<endl;
    	}
		void circular_list()
		{
			node *temp=head;
			node *curr=head;
			do
			{
				head=head->ptr;
				tail=tail->ptr;
				temp=head;
				head=head->ptr;
				tail->ptr=head;
				delete temp;
				display();
				curr=curr->ptr;
			}
			while(curr!=tail);
		}
};

int main()
{
	Linkedlist l1;
	cout<<"JOSEPH PROBLEM: "<<endl;
	
	for(int i=0;i<5;i++)
	{
		l1.Insert(i+1);
	}
	l1.circular_list();
	cout<<endl;
	cout<<"Lone Survivor: "<<endl;
	l1.display();
}