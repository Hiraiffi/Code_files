#include<iostream>
using namespace std;

class node
{
	public:
		int key;
		node *lchild;
		node* rchild;
		int height;
	node()
	{
		key=0;
		lchild=NULL;
		rchild=NULL;
		height=1;
	}
	node(int k)
	{
		key=k;
		lchild=NULL;
		rchild=NULL;
		height=1;
	}
};
class AVL
{
	public:
		node *root;
	AVL()
	{
		root=NULL;
	}
	int Height(node* temp)
	{
		if(temp==NULL)
		{
			return 0;
		}
		else
		{
			return temp->height;
		}
	}
	int maximum(int a,int b)
	{
		return (a > b) ? a : b;
	}
	int getBalance(node* temp)
	{
		if(temp==NULL)
		{
			return 0;
		}
		else
		{
			return Height(temp->lchild) - Height(temp->rchild);
		}
	}
	node* leftrotate(node* x)
	{
		node *y=x->rchild;
		node* T2 =y->lchild;
		y->lchild=x;
		x->rchild=T2;
		
		y->height = maximum(Height(y->lchild),Height(y->rchild)) + 1;
		x->height = maximum(Height(x->lchild),Height(x->rchild)) + 1;
		return y;
	}
	node* rightrotate(node* y)
	{
		node *x=y->lchild;
		node* T2 =x->rchild;
		x->rchild=y;
		y->lchild=T2;
		
		y->height = maximum(Height(y->lchild),Height(y->rchild)) + 1;
		x->height = maximum(Height(x->lchild),Height(x->rchild)) + 1;
		return x;
	}
	node* insert(node* temp,int val)
	{
		if(temp==NULL)
		{
			return new node(val);
		}
		else if (val < temp->key)
	    {
	        temp->lchild = insert(temp->lchild, val);
	    }
	    else if (val > temp->key)
	    {
	        temp->rchild = insert(temp->rchild, val);
	    }
		else
		{
			return temp;
		}
		temp->height = 1 + maximum(Height(temp->lchild), Height(temp->rchild));
        int balance = getBalance(temp);

        if (balance > 1 && val < temp->lchild->key)
        {
            return rightrotate(temp);
        }
        else if (balance < -1 && val > temp->rchild->key)
        {
            return leftrotate(temp);
        }
        else if (balance > 1 && val > temp->lchild->key)
        {
            temp->lchild = leftrotate(temp->lchild);
            return rightrotate(temp);
        }
        else if (balance < -1 && val < temp->rchild->key)
        {
            temp->rchild = rightrotate(temp->rchild);
            return leftrotate(temp);
        }
        return temp;
    }
   node* minval(node* n)
{
    node* curr = n;
    while (curr->lchild != NULL)
    {
        curr = curr->lchild;
    }
    return curr;
}

node* remove(node* temp, int val)
{
    if (temp == NULL)
    {
        return temp;
    }

    if (val < temp->key)
    {
        temp->lchild = remove(temp->lchild, val);
    }
    else if (val > temp->key)
    {
        temp->rchild = remove(temp->rchild, val);
    }
    else
    {
        if (temp->lchild == NULL || temp->rchild == NULL)
        {
            node* n = (temp->lchild) ? temp->lchild : temp->rchild;
            if (n == NULL)
            {
                n = temp;
                temp = NULL;
            }
            else
            {
                *temp = *n;
                delete n;
            }
        }
        else
        {
            node* n = minval(temp->rchild);
            temp->key = n->key;
            temp->rchild = remove(temp->rchild, n->key);
        }

        if (temp == NULL)
        {
            return temp;
        }

        temp->height = 1 + maximum(Height(temp->lchild), Height(temp->rchild));
        int balance = getBalance(temp);

        if (balance > 1 && getBalance(temp->lchild) >= 0)
        {
            return rightrotate(temp);
        }
        else if (balance > 1 && getBalance(temp->lchild) < 0)
        {
            temp->lchild = leftrotate(temp->lchild);
            return rightrotate(temp);
        }
        else if (balance < -1 && getBalance(temp->rchild) <= 0)
        {
            return leftrotate(temp);
        }
        else if (balance < -1 && getBalance(temp->rchild) > 0)
        {
            temp->rchild = rightrotate(temp->rchild);
            return leftrotate(temp);
        }
    }
    return temp;
}

	void inorder(node* temp)
	{
		if(temp==NULL){
			return ;
		}
		else
		{
			inorder(temp->lchild);
			cout<<temp->key<<" ";
			inorder(temp->rchild);
		}
	}
	node* min(node* n)
	{
		node *curr=root;
		while(curr->lchild)
		{
			curr=curr->lchild;
		}
		return curr;
	}
	void deletenode(node *temp,int val)
	{
		if(temp==NULL)
		{
			return;
		}
		else if(val < root->lchild)
		{
			root->lchild = deletenode(root->lchild,val);
		}
		else if(val > root->rchild)
		{
			root->rchild = deletenode(root->rchild,val);
		}
		else
		{
			if(root->lchild==NULL)
			{
				node *temp = root->rchild;
				free(root);
				return temp;
			}
			else if(root->rchild==NULL)
			{
				node *temp=root->lchild;
				free(root);
				return temp;
			}
			else
			{
			node* succParent = ptr;
			node* succ = ptr->rchild;
			while (succ->lchild != NULL)
			{
			succParent = succ;
			succ = succ->lchild;
			}
			if (succParent != ptr)
			succParent->lchild = succ->rchild;
			else
			succParent->rchild = succ->rchild;
			ptr->data = succ->data;
			delete succ;
			return ptr;
			}
		}
  		return root;
	}
};
int main()
{
    AVL a;
    a.root = a.insert(a.root, 5);
    a.root = a.insert(a.root, 10);
   a.root = a.insert(a.root,14);
   a.root = a.remove(a.root,14);
    a.inorder(a.root);
    return 0;
}
