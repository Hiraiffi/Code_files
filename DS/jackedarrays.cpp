#include<iostream>
using namespace std;

int main()
{
	int students = 5;
	int **ptr = new int*[students];
	int courses;
	
	for(int i=0;i<students;i++)
	{
		cout<<"Enter the no of courses: ";
		cin>>courses;
		ptr[i] = new int[courses];
		
	}
}