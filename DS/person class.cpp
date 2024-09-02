#include<iostream>
using namespace std;

class person
{
	public:
		string name;
		int age;
		person(string n,int a)
		{
			name=n;
			age=a;
		}
};
void merge(person p[],int const start,int const mid,int const end);
	//merge sort 
	void mergeSort(person p[],int start,int end)
	{
		if(start>=end)
		{
			return;
		}
		else
		{
			int mid=(start+end)/2;
			
			mergeSort(p,start,mid);
			mergeSort(p,mid+1,end);
			merge(p,start,mid,end);
		}
	}
	void merge(person p[],int const start,int const mid,int const end)
	{
		int sizeleft=start+mid+1;
		int sizeright=end-mid;
		
		string *arrleft=new string[sizeleft];
		string *arrright=new string[sizeright];
		int *arrleftage=new int[sizeleft];
		int *arrrightage=new int[sizeright];
		
		for(int i=0;i<sizeleft;i++)
		{
			arrleft[i]=p[start+i].name;
			arrleftage[i]=p[start+i].age;
		}
		for(int j=0;j<sizeright;j++)
		{
			arrright[j]=p[mid+j+1].name;
			arrrightage[j]=p[mid+j+1].age;
		}
		int i=0,j=0,k=start;
		while(i<sizeleft &&j<sizeright)
		{
			if(arrleft[i]<=arrright[j])
			{
			    p[k].name=arrleft[i];
				p[k].age=arrleftage[i];				
			    i++;
			}
			else
			{
				p[k].name=arrright[j];
				p[k].age=arrrightage[j];	
				j++;
			}
			k++;
		}
		while(i<sizeleft)
		{
			p[k].name=arrleft[i];
			p[k].age=arrleftage[i];
			i++;
			k++;
		}
		while(j<sizeright)
		{
			p[k].name=arrright[j];
			p[k].age=arrrightage[i];
			j++;
			k++;
		}
	}
	
int main()
{
	person p[3]={{"Hira",12},{"Ahmed",18},{"Hamza",20}};
	mergeSort(p,0,2);
	
	for(int i=0;i<3;i++)
	{
		cout<<p[i].name<<endl;
		cout<<p[i].age<<endl;
	}
	
	return 0;
}