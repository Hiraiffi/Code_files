#include<iostream>
#include<fstream>
using namespace std;

int main(int argc,char *argv[])
{
	int val = stoi(argv[4]);
	
	if(strcmp(argv[1],"encrypt")==0)
	{
		ifstream myfile(argv[2],ios::in);
		if(myfile.is_open()== 0)
		{
			cout<<"File not found"<<endl;
		}
		else
		{
			string str;
			getline(myfile,str);
			cout<<str<<endl;
		
			for(int i=0;str[i] != '\0';i++)
			{
				str[i] += val;
			}
		    ofstream myfile1(argv[3],ios::out);
		    myfile1 << str;
		    cout<<str<<endl;
		    myfile.close();
		    myfile1.close();
		}
	}
	else if(strcmp(argv[1],"decrypt")==0)
	{
			ifstream myfile(argv[2],ios::in);
		if(myfile.is_open()== 0)
		{
			cout<<"File not found"<<endl;
		}
		else
		{
			string str;
			getline(myfile,str);
			cout<<str<<endl;
		
			for(int i=0;str[i] != '\0';i++)
			{
				str[i] -= val;
			}
		    ofstream myfile1(argv[3],ios::out);
		    myfile1 << str;
		    cout<<str<<endl;
		    myfile.close();
		    myfile1.close();
		}
	}
    return 0;
}