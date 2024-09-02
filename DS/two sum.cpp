#include<iostream>
#include<vector>
using namespace std;

int lengthOfLongestSubstring(string s) 
{
        int length=0;
        for(int i=0;i<s.length();i++)
        {
            for(int j=0;j<s.length();j++)
            {
                if(s[i]!=s[j])
                {
                    length++;
                }
            }
        }
        return length;
}
int main()
{
	string str = "bbbbb";
	int l=0;
	
	l=lengthOfLongestSubstring(str);
		
	cout<<l<<endl;
	return 0;
}