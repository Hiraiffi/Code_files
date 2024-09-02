#include<iostream>
using namespace std;

struct TreeNode 
{
	int val;
    TreeNode *left;
    TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)
        {
            return false;
        }
        else
        {
            while(p!=NULL && q!=NULL)
            {
                if(p->val==q->val)
                {
                     return true;
                }
                if(p->left->val==q->left->val)
                {
                    return true;
                }
                if(p->right->val==q->right->val)
                {
                    return true;
                }
            }
        }
        return false;
}
int main()
{
	TreeNode *p={1,2,3};
	TreeNode *q={1,2};
	cout<<isSameTree(p,q);
}