#include<iostream>
#include<list>
using namespace std;

class hash
{
	public:
	static const int tablesize=10;
	list<int>hashtable[tablesize];
	
	int hashfunction(int key)
	{
		return key % tablesize;
	}
	//separatechaining
//	void insert(int key)
//	{
//		int index =hashfunction(key);
//		hashtable[index].push_back(key);
//	}
	//linear probing
	void insert(int key)
	{
		int index =hashfunction(key);
		
		while(hashtable[index]!=0)
		{
			++index;
			index %= tablesize;
		}
		hashtable[index]=key;
		
	}
	//quadratic probing
	void insert()
	{
		
	}
};