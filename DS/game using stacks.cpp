#include<iostream>
#include<stack>
#include<conio.h>
#include<stdlib.h>
#include<string>
#include<stack>
using namespace std;

int main()
{
	string operations;
	int sum=0;
	cin>>operations;
	stack <int>results;
	
	for(int i=0;i<operations[i]!='\0';i++)
	{
		int x;
		if(operations[i]=='x')
		{
			results.push(x);	
		}
		if(operations[i]=='C')
		{
			results.pop();
		}
		else if(operations[i]=='D')
		{
			int mul;
			mul=results.top() * 2;
		}
		else if(operations[i]=='+')
		{
			int a=results.top();
			results.pop();
			int b=results.top();
			results.pop();
			results.push(a+b);
		}
	}
	for(int i=0;i<operations[i]!='\0';i++)
	{
		if(!results.empty())
		{
			cout<<"Add to the record, record is now: "<<results.top()<<" ";
			results.pop();
		}
		cout<<sum<<endl;
	}
	return 0;
}
//'x'.
//Record a new score of x.
//'+'.
//Record a new score that is the sum of the previous two scores.
//'D'.
//Record a new score that is the double of the previous score.
//'C'.
//Invalidate the previous score, removing it from the record.
//Return the sum of all the scores on the record after applying all the operations.