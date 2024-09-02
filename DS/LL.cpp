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
    void display()
    {
    	node* temp=head;
    	
    	if(head==NULL)
    	{
    		cout<<"List doesn't exists"<<endl;
   		}
	    while(temp!=NULL)
    	{
    	    cout<<"Values: "<<temp->num<<" ";
    		cout<<endl;
    		temp=temp->ptr;
		}
	}
	void deleteList(int val)
	{
		node *prev=NULL;
		node *curr=head;
		
		do{
			if(curr->num==val)
			{
				node *temp=curr;
				prev->ptr=curr->ptr;
				curr=curr->ptr;
				delete temp;
				continue;
			}
			prev=curr;
			curr=curr->ptr;
			
		}while(curr!=NULL);
	}
};
int main()
{
	linkedList l;
	l.insert(2,0);
	l.insert(8,2);
	l.insert(12,8);
//	l.insert(50,12);
//	l.insert(1,50);
	l.display();
	l.deleteList(8);
	l.display();
	return 0;
}