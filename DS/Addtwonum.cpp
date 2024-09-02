#include<iostream>
using namespace std;
//Definition for singly-linked list.
class ListNode 
{
	public:
 	int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution 
{
	public:
	ListNode *head;
	Solution()
	{
		head=NULL;
	}
	ListNode* additems(int val)
	{
   		ListNode *temp = head;
    	ListNode* n = new ListNode(val);
	
	    if (temp == NULL)
	    {
	        head = n;
	        return n;
	    }
	    else
	    {
	        while (temp->next != NULL)
	        {
	            temp = temp->next;
	        }
	        temp->next = n;
	    }
	    return temp;
	}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
	{
		ListNode* temp=new ListNode;
        if(l1==nullptr && l2==nullptr)
        {
            return 0;
        }
        else
        {
            temp->val=l1->val+l2->val;
            return addTwoNumbers(l1->next,l2->next);
        }
    }
    ListNode* removeElements(ListNode* head, int val) 
	{
        if(head==NULL)
        {
            return head;
        }
        else if(head->val==val)
        {
            ListNode* temp=head;
            head=head->next;
            delete temp;
        }
        else 
        {
            ListNode* prev=head;
            ListNode* curr=head->next;

            while(curr!=NULL)
            {
                if(curr->val==val)
                {
                    prev->next=curr->next;
                    delete curr;
                    curr=prev->next;
                }
                prev = curr;
               	curr=curr->next;
            }
        }
        return head;
    }
    void display()
    {
    	ListNode* temp=head;
    	if(temp==nullptr)
    	{
    		return;
		}
		while(temp!=NULL)
		{
			cout<<temp->val<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
};
int main()
{
	Solution s;
	ListNode *l;
	ListNode * ll;
	s.additems(5);
	s.additems(10);
	//s.addTwoNumbers(l,ll);
	s.removeElements(l,10);
	s.display();
	
	return 0;
}