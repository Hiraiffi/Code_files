#include<iostream>
using namespace std;
//int minimum=0;
//int minimum2=0;
//int ans=0;
class node 
{
	public:
	int num;
	node *lchild;
	node *rchild;
	node()
	{
		num=0;
		lchild=NULL;
		rchild=NULL;
	}
	node(int num)
	{
		this->num=num;
		rchild=NULL;
		lchild=NULL;
	}
};

class Tree
{
	public:
	node *root;
	int sum;
	Tree()
	{
		root=NULL;
		sum=0;
	}
	void insert(node* &temp, int val) 
	{
	    if (temp == NULL) 
		{
	        temp = new node(val);
	    }
		else if(val < temp->num)
		{
	        insert(temp->lchild, val);
	    }
	    else if (val > temp->num) 
		{
	        insert(temp->rchild, val);
	    }
	}
	node* Insert(node *p,int key)
	{
		node *t;
		if(p==NULL)
		{
			t=new node;
			t->num=key;
			t->lchild=t->rchild=NULL;
			return t;
		}
		if(key<p->num)
		{
			p->lchild=Insert(p->lchild,key);
		}
		else if(key>p->num)
		{
			p->rchild=Insert(p->rchild,key);
		}
		return p;
	}
	int count=0;
	
	bool isValid(node* temp,int data)
	{
		temp=root;
		if(temp==NULL)
		{
			count++;
			return 1;
		}
		else
		{
			if(data < temp->lchild->num)
			{
				isValid(temp->lchild,data);	
				count++;
			}
			else if(data > temp->lchild->num)
			{
				isValid(temp->rchild,data);
				count++;
			}
			return true;
		}
		return false;
	}
	void inordertraversal(node *temp)
	{
		if(temp==NULL)
		{
			return;
		}
		else
		{
			inordertraversal(temp->lchild);
			cout<<temp->num<<" ";
			inordertraversal(temp->rchild);
		}
	}
//	void preordertraversal(node *temp)
//	{
//		if(temp==NULL)
//		{
//			return;
//		}
//		else
//		{
//			cout<<temp->num<<" ";
//			preordertraversal(temp->lchild);
//			preordertraversal(temp->rchild);
//		}
//	}
//	void postordertraversal(node *temp)
//	{
//		if(temp==NULL)
//		{
//			return;
//		}
//		else
//		{
//			postordertraversal(temp->lchild);
//			postordertraversal(temp->rchild);
//			cout<<temp->num<<" ";
//		}
//	}
//    void searchBST(node* temp, int val)
//	{
//    	if (temp == NULL)
//    	{
//        	cout << "Value not found" << endl;
//        	return;
//    	}
//    	else if (val < temp->num)
//    	{
//        	searchBST(temp->lchild, val);
//    	}
//    	else if (val > temp->num)
//    	{
//        	searchBST(temp->rchild, val);
//    	}
//    	else
//    	{
//        	cout << "Value found" << endl;
//    	}
//	}
//
	void display(node *temp)
	{
    	if (temp == NULL)
    	{
        	cout << "Tree is empty" << endl;
        	return;
    	}
    	if (temp->lchild != NULL)
    	{
        	display(temp->lchild);
    	}
    	cout << temp->num << " ";

    	if (temp->rchild != NULL)
    	{
        	display(temp->rchild);
    	}
	}
//	void minDiffBST(node *temp)
//	{	
//		if(temp==NULL)
//		{
//			return;
//		}
//		else
//		{
//			if(temp->num<minimum)
//			{
//				minimum=temp->num;
//			}
//			minDiffBST(temp->lchild);
//			minDiffBST(temp->rchild);
//		}
//	}
//	node* deleteNode(node *temp,int val)
//	{
//		if(temp==NULL)
//		{
//			return;
//		}
//		else if(temp->num==val)
//		{
//			cout<<temp->num;
//		}
//		else if(temp->num > val)
//		{
//			deleteNode(temp->lchild,val);
//			return temp;		
//		}
//		else if(temp->num < val)
//		{
//			deleteNode(temp->rchild,val);
//			return temp;
//		}
//		if(temp->left==NULL)
//		{
//			node* n=temp->rchild;
//			delete temp;
//			return n; 
//		}
//		else if(temp->rchild==NULL)
//		{
//			deleteNode(temp->rchild,val);
//			delete temp;
//		}
//	}
	void addition(node* temp)
	{
		if(temp==NULL)
		{
			return;
		}
		else
		{
			addition(temp->rchild);
			sum+=temp->num;
			temp->num=sum;
			addition(temp->lchild); 
		}
	}
	int add(node* root)
	{
		if(root==NULL)
		{
			return 0;
		}
		else
		{
			int ans = add(root->lchild) + add(root->rchild) + root->num;
			return ans;
		}
	}
	void result(node* root,int k)
	{
		if(root==NULL)
		{
			return;
		}
		if(add(root)==k)
		{
			inordertraversal(root);
		}
		else
		{
			result(root->lchild,k);
			result(root->rchild,k);
		}
	}
};
int main()
{
	Tree t;
	node *root=NULL;
	root = t.Insert(t.root,4);
	t.Insert(root,1);
	t.Insert(root,3);
	t.Insert(root,5);
	t.Insert(root,7);
	t.insert(root,9);
	t.display(root);
//	t.isValid(root,5);
//		cout<<endl;
	cout<<endl;
	//t.addition(root);
	t.result(root,8);
	t.display(root);
// 	t.minDiffBST(root);	
//	ans=minimum2-minimum;
//	cout<<ans<<endl;
//	t.searchBST(root,3);
//	cout<<"Inorder Traversal: "<<endl;
//	t.inordertraversal(root);
//	cout<<"\nPreorder Traversal: "<<endl;
//	t.preordertraversal(root);
//	cout<<"\nPostorder Traversal: "<<endl;
//	t.postordertraversal(root);
}