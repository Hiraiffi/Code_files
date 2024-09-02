#include<iostream>
using namespace std;
int num[5][3];
int i, j,r,c;

void input(int r, int c)
{ 
    cout<<"Enter the elements into the array"<<endl;
    for(i=0; i<r; i++)
    {
        for(j=0;j<c;j++)
        cin>>num[i][j];
    }
}
void sort(int r, int c)
{
    for(i=0; i<r; i++)
    {
	    for(j=0; j<c; j++)
	    {
            if(i%2==0)
            {
     		    int min=num[i][j],pos=i;
     			for(int k=i+1; k<r; k++)
                { 
    				if(num[k][j]<min)
    				{
                        num[k][j]=min;
                        pos=k;
		    		}
		    	}
                num[pos][j]=num[i][j];
                num[i][j]=min;
            }
            else
            {  
				int max=num[i][j],pos1=i;
                        
				for(int l=i+1; l<r; l++ )
                {
				    if(num[l][j]>max)
					{
                        num[l][j]=max;
                        pos1=l;
                    }
                    num[pos1][j]=num[i][j];
                    num[i][j]=max;
                }
            }
        }
    }
}
void display(int r, int c)
{ 
    cout<<endl<<"Array  is: "<<endl;
    for(i=0; i<r; i++)
    { 
	    cout<<"\n";
        for(j=0; j<c;j++)
        {
            cout<<num[i][j]<<"\t";
        }
    }
}
int main()
{ 
   cout<<"Enter the no of rows"<<endl;
   cin>>r;
   cout<<"Enter the no of columns"<<endl;
   cin>>c;
   if(r<=5 && c<=3)
   {
    input(r,c);
    cout<<" Before sorting"<<endl;
    display(r,c);
    sort(r,c);
    cout<<"\n After sorting"<<endl;
    display(r,c);
    }
    else cout<<"Invalid no of rows and columns";
}