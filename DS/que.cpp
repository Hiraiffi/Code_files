#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue<int>que;
	
	cout<<"Empty: "<<que.empty()<<endl;
	que.push(12);
	cout<<que.front()<<endl;
	cout<<que.back()<<endl;
	cout<<"Empty: "<<que.empty()<<endl;
	que.push(155);
	cout<<"Empty: "<<que.empty()<<endl;
	cout<<que.front()<<endl;
	cout<<que.back()<<endl;
	que.pop();
	que.pop();
	cout<<"Empty: "<<que.empty()<<endl;
	return 0;
}