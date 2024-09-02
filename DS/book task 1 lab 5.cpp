#include<iostream>
using namespace std;

class node
{
	public:
	string booktitle;
	string authorname;
	int ISBN number;
	node *next;
	node *prev;
	node()
	{
		booktitile=" ";
		authorname=" ";
		ISBN=0;
		prev=NULL;
		next=NULL;
	}
	node(string title,string name,int ISBN)
	{
		booktitle=title;
		authorname=name;
		this-ISBN=ISBN;
		prev=NULL;
		next=NULL;
	}
};
class Book
{
	public:
		node *head;
		node *tail;
		Book()
		{
			head=NULL;
			tail=NULL;
		}
		
};