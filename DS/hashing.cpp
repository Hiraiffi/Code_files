#include<iostream>
#include<list>
using namespace std;
//#define MP pair<int,pair<int,int>>
//#define DP pair<int,int>
//int findparent(int x) {
//		if(parent[x] == x) {
//			return x;
//		} else {
//			return findparent(parent[x]);
//		}
//	}
//
//	void makeUnion(int x, int y) {
//		int a = findparent(x);
//		int b = findparent(y);
//		parent[a] = b;
//	}
//
//	bool checkCycle(int x, int y) {
//		if(findparent(x) != findparent(y)) {
//			makeUnion(x, y);
//		} else {
//			return true;
//		}
//		return false;
//	}
//
//	void Kruskal() {
//		// priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int,int>>>> pq;
//		priority_queue<MP, vector<MP>, greater<MP>> pq;
//
//		for (int i = 0; i < vertices; i++) {
//			for (int j = 0; j < vertices; j++) {
//
//				int source_node = i;
//				int destination_node = j;
//				int weight = graph2[i][j];
//
//				if(source_node != destination_node && weight != 0) {
//
//					pq.push({weight, {source_node, destination_node}});
//
//				}
//
//			}
//		}
//
//		while(!pq.empty()) {
//
//			auto i = pq.top();
//			pq.pop();
//
//			int source_node = i.second.first;
//			int destination_node = i.second.second;
//			int weight = i.first;
//			
//			if(!checkCycle(source_node, destination_node)) {
//				cost += weight;
//				MST[source_node][destination_node] = weight;
//				MST[destination_node][source_node] = weight;
//			}
//		}
//
//		}
//		int findparent(int x)
//		{
//			if(parent[x]==x)
//			{
//				return x;
//			}
//			else
//			{
//				findparent[x];
//			}
//		}
//		int makeunion(int x,int y)
//		{
//			int a =findparent(x);
//			int b = findparent(y);
//			return parent[a]=b;
//		}
//		bool checkcycle(int x,int y)
//		{
//			if(findparent[x] != findparent[y])
//			{
//				makeunion(x,y);
//			}
//			else
//			{
//				return true;
//			}
//			return false;
//		}
//		void kruskal()
//		{
//			priorit_queue<MP,vector<MP>,greater<MP>>qp;
//			for(int i=0;i<vertices;i++)
//			{
//				for(int j=0;j<vertices;j++)
//				{
//					int source_node =i;
//					int dest_node =j;
//					int weight = arr[i][j];
//				}
//				if(source_node!=dest_node && weight!=0)
//				{
//					pq.push({weight},{source_node,dest_node});
//				}
//			}
//			while(!qp.empty())
//			{
//				auto i = qp.top();
//				qp.pop();
//				
//				int source_node = i.fisrt.second;
//				int dest_node = i.second.second;
//				int weight = i.first;
//				if(!checkcycle(source_node,dest_node))
//				{
//					cost += weight;
//					MST[source_node][dest_node]=weight;
//					MST[dest_node][source_node]=weight;
//				}
//			}
//		}

class hashing
{
	public:
	static const int tablesize=10;
	//<int>hashtable[tablesize];
	int arr[tablesize];
	hashing()
	{
		for(int i=0;i<tablesize;i++)
		{
			arr[i]=0;
		}
	}
	int hashfunction(int key)
	{
		return key % tablesize;
	}
	//separate chaining
	vector<string> h(10, " ");
	vector<string> chain[10];
	void hash2(string k, int i) 
	{
	    i = i % 10;
	
	    if(h[i] == " ") 
		{
	        h[i] = k;
	        chain[i].push_back(k);
	    } 
		else {
	        chain[i].push_back(k);
	    }
	}
	//linear probing
	void insert4(int key)
	{
		int index = hashfunction(key);
		
		while(arr[index]!=0)
		{
			++index;
			index %= tablesize;
		}
		arr[index]=key;
		
	}
	//quadratic probing
	void insert2(int key)
	{
		int index =hashfunction(key);
		int i=1;
		while(arr[index]!=0)
		{
			index = (index + i * i) % tablesize;
		}
		arr[index]=key;
	}
	int hasfunc2(int key)
	{
		return 7 - (key % 7);
	}
	void insert3(int key)
	{
		int index=hashfunction(key);
		int step = hasfunc2(key);
		int i=1;
		
		while(arr[index]!=0)
		{
			index = index + (i * step) % tablesize;
			++i;
		}
		arr[index]=key;
	}
	void display()
	{
		for(int i=0;i<tablesize;i++)
		{
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
};
int main()
{
	hashing h;
	h.hashfunction(4);
	h.insert(2);
	h.insert(4);
	h.insert(5);
	h.display();
}
//void djisktra(int source) {
//
//			priority_queue<DP, vector<DP>, greater<DP>> pq;
//			reset_visited();
//
//			distance[source] = 0;
//			pq.push({0, source});
//			displayPrioqueue(pq);
//
//			while(!pq.empty()) 
//			{
//				auto s = pq.top();
//				pq.pop();
//
//				int node = s.second;
//				int node_distance = s.first;
//
//				if(visited[node])
//					continue;
//				visited[node] = true;
//
//				for (int j = 0; j < vertices; j++) {
//					if(graph2[node][j] != 0 && node != j) {
//						
//						if(distance[j] > distance[node] + graph2[node][j]) {
//							distance[j] = distance[node] + graph2[node][j];
//							pq.push({distance[j], j});
//						}
//
//					}
//				}
//				cout << endl;
//			}
//		}
//		