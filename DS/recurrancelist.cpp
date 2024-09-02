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
	Linkedlist()
	{
		head=NULL;
	}
	void insert(int number)
	{
		Node *temp;
		temp = head;
		Node *n = new Node(number);
		
		if(head == NULL)
		{
			head = n;
		}
		else if(temp->ptr==NULL)
		{
			temp->ptr=n;
		}
		else 
		{   
		    while(temp->ptr != NULL)
		    {
			    temp = temp->ptr;
		    }
		    temp->ptr=n;
	}
}
//	void findRecurrance()
//    {
//    	Node *temp=head;
//    	if(head==NULL)
//    	{
//    		cout<<"List doesn't exists"<<endl;
//		}
//		else
//		{
//			while(temp->ptr!=NULL)
//			{
//				Node *curr=temp->ptr;
//				Node *prev=temp;
//				while(curr->ptr!=NULL)
//				{
//					if(curr->num==temp->num)
//					{
//						prev->ptr=curr->ptr;
//		         		curr=curr->ptr;
//		         		//delete curr;
//						cout<<"Bubyee"<<endl;
//						continue;
//					}
//				prev=curr;
//				curr=curr->ptr;
//		    	}
//		    	temp=temp->ptr;
//			}
//		}
//    }
    void print()
    {
    	Node *temp=head;
    	while(temp!=NULL)
    	{
    		cout<<"Elements of list: "<<temp->num<<endl;
    		temp=temp->ptr;
		}
	}
};
void merge(Linkedlist l1,Linkedlist l2)
{
   Node *temp=l1.head;
   Node *temp2=l2.head;
   
   while(temp->ptr!=NULL)
   	{
   	    temp=temp->ptr;
    }
    temp->ptr=temp2;
    temp=l1.head;
    
    while(temp->ptr!=NULL)
    {
    	Node *min=temp;
        temp2=temp->ptr;
        
        while(temp2!=NULL)
        {
        	if(temp2->num < min->num)
        	{
        		min=temp2;
			}
			temp2=temp2->ptr;
		}
		if(min!=temp)
		{
			swap(min->num,temp->num);
		}
		temp=temp->ptr;
		}
}
int main()
{
	Linkedlist l;
	Linkedlist l1;
	l.insert(2);
	l.insert(2);
	l.insert(5);  
	l.insert(2);
	l1.insert(9);
	l1.insert(18);
	l1.insert(3);
	l1.insert(7);
	merge(l,l1);
	l.print();
}