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
    int x;
    int size;
    node *head;
    node *tail;
    MyStack() {
        x=0;
    }
    
    void push() {
        node *temp=head;
        temp->ptr=head;
        head=temp;
        size++;
    }
    
    void pop() {
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
};

int main()
{
	MyStack s;
	s.push();
	return 0;
}