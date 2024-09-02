#include<bits/stdc++.h>
using namespace std;

int main()
{
	priority_queue<int,vector<int>,greater<int>>heap;
	
	for(int i=0;i<17;i++)
	{
		int temp;
		cin>>temp;
		heap.push(temp);
	}
	while(!heap.empty())
	{
		cout<<heap.top()<<" ";
		heap.pop();
	}
	
	return 0;
}