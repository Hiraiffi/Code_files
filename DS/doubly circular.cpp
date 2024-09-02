#include<iostream>
using namespace std;

class node  //node class
{
	public:
	string artistName;
	string songName;
	node *prev;
	node*next;
	
	node()
	{
		artistName=" ";
		songName=" ";
		prev=NULL;
		next=NULL;
	}
	node(string artname,string sngname)
	{
	   this->artistName=artname;
	   this->songName=sngname;
	   prev=NULL;
	   next=NULL;
	}
};
class Playlist
{
	public:
		node *head;
		node *tail=head;
		int len=0;
		Playlist()
		{
			head=NULL;
		}
		void insert(string n1)
		{
			node *n=new node(n1,"YS");
			if(head==NULL)
			{
				head=n;
				n->next=head;
				n->prev=head;
				return;
			}
			node *temp=head;
			while(temp->next!=head)
			{
				temp=temp->next;
			}
			temp->next=n;
			n->prev=temp;
			n->next=head;
			head->prev=n;
		}
		void display()
		{
			if(head==NULL)
			{
				cout<<"List doesn't exists"<<endl;
			}
			else
			{
				node *temp=head;
				do
				{
					cout<<temp->artistName<<" "<<temp->songName<<" "<<endl;
					temp=temp->next;
				}while(temp!=head);
			}
		}
		void length()
		{
			len=0;
			node *temp=head;
			do
			{
				len++;
				temp=temp->next;
			}while(temp!=head);
		}
		void deleteList(int pos)
		{
			length();
			node *temp=head;
			node *curr=head->next;
			
			if(pos<1 || pos>len)
			{
				cout<<"Invalid Position"<<endl;
			}
			else if(pos==1)
			{
				temp=head;
				head=head->next;
				head->prev=temp->prev;
				(temp->prev)->next=head;
				delete temp;
			}
			else if(pos==len)
			{
				temp=head->prev;
				(temp->prev)->next=head;
				head->prev=temp->prev;
				delete temp;
			}
			else
			{
				for(int i=0;i<pos-1;i++)
				{
					temp=curr;
					curr=curr->next;
				}
				(temp->prev)->next=curr;
				curr->prev=temp->prev;
				delete temp;
			}
		}
		void reverse()
		{
			node *temp=head;
			
			do
			{
				node *temp2;
				temp2=temp->prev;
				temp->next=temp->prev;
				temp->next=temp2;
				
				temp=temp->next;
				
			}while(temp!=head);
			head=temp->prev;
		}
};
int main()
{
    Playlist p;
	p.insert("1");
	p.insert("2");
	p.insert("3");
	p.insert("4");
	p.insert("5");
	p.insert("6");
	p.display();
	cout<<endl;
	p.reverse();
	p.display();
}