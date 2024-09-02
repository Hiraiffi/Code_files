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
class MyStack {
public:
    int size;
    node *head;
    node *tail;
    MyStack() {
        x=0;
    }
    
    void push(int x) 
	{
		node *temp=head;
    	if(head==NULL)
    	{
    		head=temp;
    		tail=temp;
    		return;
		}
        temp->ptr=head;
        head=temp;
        size++;
    }
    
    void pop(int x)
	{
        node *temp=head;
        head=head->ptr;
        delete temp;
        size--;
    }
    
    int top() {
        return head->num;
    }
    
    bool empty() {
        if(size==0)
        {
            cout<<"Stack is empty"<<endl;
            return true;
        }
        else
        {
            return false;
        }
    }
    void print()
    {
    	if(head==NULL)
    	{
    		cout<<"Stack is empty"<<endl;
		}
		else
		{
			
		}
	}
};

int main()
{
	MyStack s;
	s.push();
	s.pop();
	s.empty();
	s.top();
	return 0;
}