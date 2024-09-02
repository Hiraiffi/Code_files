#include<iostream>
#include<string>
#include<stack>
using namespace std;

class product
{
	public:
		string ISBN;
		float Price;
		string Color;
		string Brand;
		int StorageCapacity;
		int screenSize;
		int CameraResolution;
		string BatteryLife;
		stack<string> reviews;
		product *ptr;
		product()
		{
			ISBN = " ";
			Price = 0;
			Color = " ";
			Brand = " ";
			StorageCapacity = 0;
			screenSize = 0;
			CameraResolution = 0;
			BatteryLife = " ";
			ptr = NULL;
		}
		product(string ISBN,float p,string col,string br,int storage,int screen,int camera,string battery)
		{
			this->ISBN=ISBN;
			Price = p;
			Color = col;
			Brand = br;
			StorageCapacity = storage;
			screenSize = screen;
			CameraResolution = camera;
			BatteryLife = battery;
			ptr = NULL;
		}
		product(string ISBN)
		{
			this->ISBN=ISBN;
			Price = 0;
			Color = " ";
			Brand = " ";
			StorageCapacity = 0;
			screenSize = 0;
			CameraResolution = 0;
			BatteryLife = " ";
			ptr=NULL;
		}
		void display()
		{
			cout<<"ISBN: "<<ISBN<<"\nPrice: "<<Price<<"\nColour: "<<Color<<"\nName: "<<Brand;
			cout<<"\nStorage: "<<StorageCapacity<<"\nScreen Size: "<<screenSize;
			cout<<"\nCamera resolution: "<<CameraResolution<<"\nBattery life: "<<BatteryLife<<endl;
			//cout.flush();
		}
};
//circular linked list to display products
class LLdisplay
{
	public:
		product *head;
		
		LLdisplay()
		{
			head=NULL;
		}
		void insert(string ISBN,float p,string col,string br,int storage,int screen,int camera,string battery)
		{
			product *temp=head;
			product *n=new product(ISBN,p,col,br,storage,screen,camera,battery);
			if(temp==NULL)
			{
				head = n;
				n->ptr=head;
				return;
			}
			else
			{
				while(temp->ptr!=head)
				{
					temp=temp->ptr;
				}
				temp->ptr=n;
				n->ptr=head;	
			}
		}
};
class shoppingcart
{
	public:
	product *head;
	int noofprod;
	float totalcost;
	shoppingcart()
	{
		noofprod=0;
		totalcost=0.0;
		head = NULL;
	}
	void additems(product *prod)
	{
		additems(prod->ISBN);
	}
	void additems(string ISBN)
	{
		float p;
   		product *temp = head;
    	product *n = new product(ISBN);
    	p=n->Price;
    
	    totalcost += p;
	    noofprod++;
	
	    if (temp == NULL)
	    {
	        head = n;
	        return;
	    }
	    else
	    {
	        while (temp->ptr != NULL)
	        {
	            temp = temp->ptr;
	        }
	        temp->ptr = n;
	    }
	}
	void deleteitems(string x)
	{
		if(head==NULL)
		{
			cout<<"Cart is currently empty"<<endl;
			return;
		}
		else
		{
			product *curr=head->ptr;
			product *prev=head;
			//delete from beginning
			if(prev->ISBN==x)
			{
				head=curr;
				totalcost-=prev->Price;
				noofprod--;
				cout<<"Item: "<<prev->Brand<<" has been deleted successfully!!"<<endl;
				delete prev;
				return;
			}
			//delete from middle
			while(curr!=NULL)
			{
				if(curr->ISBN==x)
				{
					prev->ptr = curr->ptr;
					totalcost-=curr->Price;
					noofprod--;
					cout<<"Item: "<<curr->Brand<<" has been deleted successfully!!"<<endl;
					delete curr;
					curr=prev->ptr;
					return;
				}
				prev = curr;
				curr = curr->ptr;
			}	
			cout<<"This item does not exists in the cart"<<endl;
		}
	}
	void print()
	{
		if(head==NULL)
		{
			cout<<"There are no items in this cart"<<endl;
		}
		else
		{
			cout<<"Total Cost: "<<totalcost;
			cout<<" No of products: "<<noofprod<<endl;
			product *temp=head;
			while(temp!=NULL)
			{
				temp->display();
				temp = temp->ptr;
			}
			cout<<endl;
		}
	}
	void checkout(product *root)
	{
    int ch;
    print();
    cout << "Select payment method: \n 1- Cash 2- Card ";
    cin >> ch;

    if (ch == 1)
    {
        cout << "Please prepare $" << totalcost << " in cash. Thank you!" << endl;
    }
    else if (ch == 2)
    {
        int num;
        int pincode;
        L2:
        cout << "Enter your card details: " << endl;
        cout << "Enter your Card number (Enter last 4 digits): ";
        cin >> num;

        // Check if the card number is valid
        if (isValidCardNumber(num))
        {
        	L1:
            cout << "Enter your PIN code (Enter 4 digits): ";
            cin >> pincode;

            // Check if the PIN code is valid
            if (isValidPin(pincode))
            {
                cout << "Congratulations! Your order is now officially confirmed, Thank you for shopping!!!!" << endl;
            }
            else
            {
                cout << "Invalid PIN code. Payment failed. Please try again." << endl;
            	goto L1;
			}
            
        }
        else
        {
            cout << "Invalid card number. Payment failed. Please try again." << endl;
            goto L2;
        }
    }
    else
    {
        cout << "Invalid choice. Payment failed. Please select a valid payment method." << endl;
    }
}

bool isValidCardNumber(long long cardNumber)
{
    // Check if the card number has a valid length (for example, 16 digits)
    string cardStr = to_string(cardNumber);
    return (cardStr.length() == 4);
}

bool isValidPin(int pincode)
{
    // Check if the PIN code has a valid length (for example, 4 digits)
    string pinStr = to_string(pincode);
    return (pinStr.length() == 4);
}

	
};
int main()
{
	shoppingcart c;
	product *root;
	c.additems("978123456");
	c.additems("978123433");
	c.additems("1534646");
	//c.print();
	c.checkout(root);
	return 0;
}