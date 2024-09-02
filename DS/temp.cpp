#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	vector<int>temp(m+n,0);
	int l=0;
        int j=0;
        int k=0;
        for(int i=0;i<m+n;i++)
        {
            if(nums2.size()!=0 && nums1[j]<=nums2[k] && nums1[j]!=0)
            {
                temp[l]=nums1[j];
                j++;
            }
            else
            {
                temp[l]=nums2[k];
                k++;
            }
            cout<<temp[l];
            l++;
        }
}
int main()
{
	vector<int>x;
	vector<int>y;
	x.push_back(1);
//	y.push_back(1);	
//	x.push_back(3);
//	x.push_back(0);
//	x.push_back(0);
//	x.push_back(0);
//	y.push_back(2);
//	y.push_back(5);
//	y.push_back(6);
	merge(x,1,y,0);

}