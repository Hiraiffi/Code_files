#include<iostream>
#define SIZE 4
using namespace std;

class heap
{
public:
    int arr[SIZE];
    int ind;

    heap()
    {
        for (int i = 0; i < SIZE; i++)
        {
            arr[i] = 0;
        }
        ind = 0;
    }

    void heapifyUp(int i)
    {
        int index = i;
        while (index > 0)
        {
            int parent = (index - 1) / 2;
            if (arr[index] < arr[parent])
            {
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else
            {
                break;
            }
        }
    }

    void heapifyDown(int i)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < SIZE && arr[left] > arr[largest])
        {
            largest = left;
        }
        if (right < SIZE && arr[right] > arr[largest])
        {
            largest = right;
        }
        if (largest != i)
        {
            swap(arr[largest], arr[i]);
            heapifyDown(largest);
        }
    }
    void insert(int val)
    {
        if (ind < SIZE)
        {
            arr[ind] = val;
            heapifyUp(ind);
           // heapifyDown(ind);
            ind++;
        }
        else
        {
            cout << "Heap Tree is full" << endl;
        }
    }
    void deleteHeap(int val)
    {
    	int last=arr[ind-1];
    	arr[0]=last;
    	ind--;
    	heapifyDown(ind);
	}
    void display()
    {
        for (int i = 0; i < SIZE; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    heap h;
    h.insert(5);
    h.insert(10);
    h.insert(2);
    h.insert(20);
    h.display();
    h.deleteHeap(10);
    h.display();

    return 0;
}
