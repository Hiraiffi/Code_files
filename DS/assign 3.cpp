//#include<iostream>
//using namespace std;
//class node
//{
//	public:
//		string data;
//		node *next;
//	node()
//	{
//		data=" ";
//		next=NULL;
//	}
//	node(string data)
//	{
//		this->data=data;
//		next=NULL;
//	}
//};
//class priority_queue
//{
//	public:
//		node *head;
//		priority_queue()
//		{
//			head=NULL;
//		}
//		template<typename T>
//		void push(T var)
//		{
//			node *n=new node;
//			if(head==NULL)
//			{
//				head=n;
//				return;
//			}
//				n->next=head;
//				head=n;
//		}
//		void front()
//		{
//			if(head==NULL)
//			{
//				return;
//			}
//			else
//			{
//				node *temp=head;
//				while(temp!=NULL)
//				{
//					cout<<temp->data<<" ";
//					temp=temp->next;
//				}
//				cout<<endl;
//			}
//		}
//		void pop(node* top)
//		{
//			if(top==NULL)
//			{
//				return;
//			}
//			else
//			{
//				cout<<"The popped element is: "<<top->data;
//				top=top->next;
//			}
//		}
//};
//int main()
//{
//	priority_queue pq;
//	pq.push("hira");
//	pq.front();
//}
// C++ program to implement a queue using an array
#include <bits/stdc++.h>
using namespace std;

struct Queue 
{
	int front, rear, capacity;
	int* queue;
	Queue(int c)
	{
		front = rear = 0;
		capacity = c;
		queue = new int;
	}

	~Queue()
	{
		delete[] queue; 
	}

	void queueEnqueue(int data)
	{
		if(capacity==rear)
		{
			cout<<"Queue is full"<<endl;
			return;
		}
		else
		{
			queue[rear]=data;
			rear++;
		}
		return;
	}

	void queueDequeue()
	{
		if(front==rear)
		{
			cout<<"queue is empty"<<endl;
			return;
		}
		else
		{
			for(int i=0;i<rear;i++)
			{
				queue[i]=queue[i+1];
			}
			rear--;
		}
		return;
	}

	// print queue elements
	void queueDisplay()
	{
		int i;
		if (front == rear) {
			printf("\nQueue is Empty\n");
			return;
		}

		// traverse front to rear and print elements
		for (i = front; i < rear; i++) {
			printf(" %d <- ", queue[i]);
		}
		return;
	}

	// print front of queue
	void queueFront()
	{
		if (front == rear) {
			printf("\nQueue is Empty\n");
			return;
		}
		printf("\nFront Element is: %d", queue[front]);
		return;
	}
};

// Driver code
int main(void)
{
	// Create a queue of capacity 4
	Queue q(4);

	// print Queue elements
	q.queueDisplay();

	// inserting elements in the queue
	q.queueEnqueue(20);
	q.queueEnqueue(30);
	q.queueEnqueue(40);
	q.queueEnqueue(50);

	// print Queue elements
	q.queueDisplay();

	// insert element in the queue
	q.queueEnqueue(60);

	// print Queue elements
	q.queueDisplay();

	q.queueDequeue();
	q.queueDequeue();

	printf("\n\nafter two node deletion\n\n");

	// print Queue elements
	q.queueDisplay();

	// print front of the queue
	q.queueFront();

	return 0;
}
