#include<iostream>
#include<stack>
#include<queue>
#define SIZE 10
using namespace std;

//void display()
//{
//	Stack s[100];
//	int top;
//	if(top<0)
//	{
//		for(int i=top;i>=0;i--)
//		{
//			cout<<s[i]<<" ";
//		}
//		cout<<endl;
//	}
//}
int main()
{
	int m=5;
	queue<int>centerpile;
	int highest=centerpile.front();
	stack<int>cards[52];
	stack<int>players[m];
	stack<string>winnerset[52];
	
	//push and pop function
	for(int i=0;i<52;i++)
	{
		centerpile.push(cards[i].top());
		cards[i].pop();
	}
	int i;
	while(i!=52)
	{
		centerpile[i].push(highest);
		centerpile[i].pop();
		winnerset[i].push(cards[i]);
		i++;
    }
		
	while(!winnerset.empty())
	{
		cout<<winnerset.top()<<" ";
		winnerset.pop();
	}
	return 0;
}