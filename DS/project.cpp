#include<iostream>
#include<string>
#include<cstring>
#include<stack>
#include<fstream>
#include<stdlib.h>
#include<Windows.h>
using namespace std;

class Inventory;
class AVL;

class Profile
{
protected:
	string userName, password;
public:
	Profile() {}
	virtual bool login() = 0;
	Profile(string userName, string password) :userName(userName), password(password) {}
	void setPassWord(string password) { this->password = password; }
	string get_name() { return userName; }
	string get_password() { return password; }
};

class Admin : public Profile
{
public:
	Admin()
	{
		userName = "admin";
		password = "pass";
	}
	bool login()
	{
		int flag = 0;
		string user, pass;
		system("cls");
		cout << "\n\n\t\t\tLOGIN ";
		cout << "\n\t\t\t-----";
		cout << "\n\n\t\t\tUSERNAME :";
		cin >> user;
		cout << "\n\t\t\tPASSWORD :";
		cin >> pass;


		if (user == userName && pass == password)
		{
			cout << "\n\n\t\t\tLogging In...";
			Sleep(1000);
			system("cls");
			return true;
		}
		else return false;
	}
	string get_name()
	{
		return userName;
	}
};

class User : public Profile
{
public:
	bool login()
	{
		int flag = 0;
		string user, pass;
		system("cls");
		cout << "\n\n\t\t\tLOGIN ";
		cout << "\n\t\t\t-----";
		cout << "\n\n\t\t\tUSERNAME :";
		cin >> userName;
		cout << "\n\t\t\tPASSWORD :";
		cin >> password;

		ifstream input("Citizen.txt");
		while (input >> user >> pass)
		{
			if (user == userName && pass == password)
			{
				flag = 1;
				cout << "\n\n\t\t\tLogging In...";
				Sleep(1000);
				system("cls");
			}
		}
		input.close();

		if (flag == 1) return true;
		else return false;
	}
};
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
		void display()
		{
			cout<<"Price: "<<Price<<"\nColour: "<<Color<<"\nName: "<<Brand<<"\nStorage: "<<StorageCapacity<<"\nScreen Size: "<<screenSize<<"\nCamera resolution: "<<CameraResolution<<"\nBattery life: "<<BatteryLife<<endl;
			cout.flush();
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
	int noofprod=0;
	float totalcost=0.0;
	shoppingcart()
	{
		head = NULL;
	}
	void additems(product *prod)
	{
		additems(prod->ISBN,prod->Price,prod->Color,prod->Brand,prod->StorageCapacity,prod->screenSize,prod->CameraResolution,prod->BatteryLife);
	}
	void additems(string ISBN,float p,string col,string br,int storage,int screen,int camera,string battery)
	{
		product *temp=head;
		product *n=new product(ISBN,p,col,br,storage,screen,camera,battery);
		totalcost+=p;
		noofprod++;
		if(temp==NULL)
		{
			head = n;
			return;
		}
		else
		{
			while(temp->ptr!=NULL)
			{
				temp=temp->ptr;
			}
			temp->ptr=n;	
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
			product *temp=head;
			cout<<"Total Cost: "<<totalcost<<endl;
			cout<<"No of products: "<<noofprod<<endl;
			cout<<"Items of your list are: "<<endl;
			while(temp!=NULL)
			{
				temp->display();
				cout<<endl;
				temp = temp->ptr;
			}
			cout<<endl;
		}
	}
	void checkout()
	{
		int ch;
		print();
		cout<<"What would be the payment method: \n1-By cash 2-By card";
		cin>>ch;
		if(ch==1)
		{
			cout<<"Please keep "<<totalcost<<" amount of money readyyy!!"<<endl;
		}
		if(ch==2)
		{
			int num;
			int pincode;
			cout<<"Enter the details of your card: "<<endl;
			cout<<"Enter your Card number: "<<endl;
			cin>>num;
			cout<<"Your pin code: "<<endl;
			cin>>pincode;
			cout<<"Your order has been paid. Thank you for shopping!!"<<endl;
		}
	}
};
void Menu()
{
	LLdisplay l;
	char choice,ch;
	product *temp=l.head;
	int i=1;
	do
	{
		cout<<"\t("<<i++<<")"<<endl;
		temp->display();	
		temp=temp->ptr;
	}
	while(temp!=l.head);
	while(1)
	{
		cout<<"Which product do you want to buy: Choose from the products and press N for : ";
	}
}

class Laptop
{

	string ISBN;
	int quantity;
	float Price;
	int year;
	string Color;
	string Brand;
	string StorageCapacity;
	string screenSize;
	string CameraResolution;
	string BatteryLife;
	stack<string> reviews;

	int key;
	Laptop* left;
	Laptop* right;
	int height;

public:
	Laptop()
	{
		this->ISBN = to_string(1 + rand() % 100);
		quantity = 0;
		Price = 0;
		Color = "";
		Brand = "";
		year = 0;
		StorageCapacity = "";
		screenSize = "";
		CameraResolution = "";
		BatteryLife = "";
		left = NULL;
		right = NULL;
		height = 1;
		key = 0;
	}


	Laptop(string isb, int qty, float p, string col, string br, int yr, string storage, string screen, string camera, string battery)
	{
		this->ISBN = isb;
		quantity = qty;
		Price = p;
		Color = col;
		Brand = br;
		year = yr;
		StorageCapacity = storage;
		screenSize = screen;
		CameraResolution = camera;
		BatteryLife = battery;
		left = NULL;
		right = NULL;
		key = 0;
		height = 1;
	}
	void setISBN(string ISBN)
	{
		this->ISBN = ISBN;
	}
	string getISBN()
	{
		return ISBN;
	}
	int getQty ()
	{
		return quantity;
	}
	float getPrice()
	{
		return Price;
	}
	int getYear()
	{
		return year;
	}
	string getColor()
	{
		return Color;
	}
	string getBrand()
	{
		return Brand;
	}
	string getCamera()
	{
		return CameraResolution;
	}
	string getScreen()
	{
		return screenSize;
	}
	string getBattery()
	{
		return BatteryLife;
	}
	string getStorage()
	{
		return StorageCapacity;
	}
	
	void increaseQty()
	{
		quantity++;
	}
	void decreaseQty()
	{
		quantity--;
	}

	void operator=(const Laptop * root)
	{
		ISBN = root->ISBN;
		quantity = root->quantity;
		Price = root->Price;
		Color = root->Color;
		Brand = root->Brand;
		year = root->year;
		StorageCapacity = root->StorageCapacity;
		screenSize = root->screenSize;
		CameraResolution = root->CameraResolution;
		BatteryLife = root->BatteryLife;
		left = root->left;
		right = root->right;
		height = root->height;
		reviews=root->reviews;
		key = root->key;
		
	}
	bool operator == (const Laptop *root)
	{
		if ((Price == root->Price) && (Color == root->Color) && (Brand == root->Brand) && (year = root->year) && (StorageCapacity == root->StorageCapacity) && (screenSize == root->screenSize) && (CameraResolution == root->CameraResolution) && (BatteryLife == root->BatteryLife))		//left == root->left;
			return 1;
		return 0;
		
	}
	friend class AVL;
	friend class Inventory;
	friend ostream& operator <<(ostream& out, const Laptop&);
	friend istream& operator >>(istream& in,  Laptop&);
};

ostream& operator <<(ostream& out, const Laptop& laptop)
{
	cout << "\nISBN : ";
	out << laptop.ISBN;
	cout << "\nQuantity : ";
	out << laptop.quantity;
	cout << "\nPrice : ";
	out << laptop.Price;
	cout << "\nColor : ";
	out << laptop.Color;
	cout << "\nBrand : ";
	out << laptop.Brand;
	cout << "\nYear : ";
	out << laptop.year;
	cout << "\nStorageCapacity : ";
	out << laptop.StorageCapacity;
	cout << "\nscreenSize : ";
	out << laptop.screenSize;
	cout << "\nCameraResolution : ";
	out << laptop.CameraResolution;
	cout << "\nBatteryLife : ";
	out << laptop.BatteryLife;
	//while (!laptop.reviews.empty())
	//{
	//	out << laptop.reviews.top();
	//	laptop.reviews.pop();
	//}
	cout << endl;
	return out;
}
istream& operator >>(istream& in,  Laptop& laptop)
{
	laptop.quantity=1;

	int flag = 0;
	cout << "\nEnter Price : ";
	in >> laptop.Price;
	do
	{
		if (laptop.Price > 0)
			flag = 1;
		else
		{
			cout << "Please enter a number greater than 0 " << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			cin >> laptop.Price;
		}
	} while (flag == 0);
	
	flag = 0;
	cout << "\nEnter Color : ";
	in >> laptop.Color;
	do
	{
		for (int i = 0; i < laptop.Color.length(); i++)
			laptop.Color[i]=toupper(laptop.Color[i]);
		if (laptop.Color == "BLACK" || laptop.Color == "WHITE" || laptop.Color == "SILVER" || laptop.Color == "BLUE" )
			flag = 1;
		else
		{
			cout << "\nLaptops in this color arent allowed.Please enter a correct color (Black,Silver,White,Blue) \n" << endl;
			cin >> laptop.Color;
		}
	} while (flag == 0);

	flag = 0;
	cout << "\nEnter Brand : ";
	in >> laptop.Brand;
	do
	{
		for (int i = 0; i < laptop.Brand.length(); i++)
			laptop.Brand[i] = toupper(laptop.Brand[i]);
		if (laptop.Brand == "HP" || laptop.Brand == "DELL" || laptop.Brand == "LENOVO" || laptop.Brand == "APPLE")
			flag = 1;
		else
		{
			cout << "\nLaptops in this brand arent allowed.Please enter a correct brand (HP,DELL,LENOVO,APPLE) \n" << endl;
			cin >> laptop.Brand;
		}
	} while (flag == 0);
	
	flag = 0;
	cout << "\nEnter Year : ";
	in >> laptop.year;
	do
	{
		if (laptop.year > 0)
			flag = 1;
		else
		{
			cout << "Please enter a number greater than 0 " << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			cin >> laptop.year;
		}
	} while (flag == 0);

	
	cout << "\nEnter StorageCapacity : ";
	in >> laptop.StorageCapacity;
	cout << "\nEnter screenSize : ";
	in >> laptop.screenSize;
	cout << "\nEnter CameraResolution : ";
	in >> laptop.CameraResolution;
	cout << "\nEnter BatteryLife : ";
	in >> laptop.BatteryLife;
	cout << endl;
	return in;
}




class AVL
{
	int height(Laptop* N)
	{
		if (N == NULL)
			return 0;
		return N->height;
	}

	Laptop* rightRotate(Laptop* imbalancedNode)
	{
		Laptop* lchild = imbalancedNode->left;
		Laptop* temp = lchild->right;

		lchild->right = imbalancedNode;
		imbalancedNode->left = temp;

		imbalancedNode->height = max(height(imbalancedNode->left),
			height(imbalancedNode->right)) + 1;
		lchild->height = max(height(lchild->left),
			height(lchild->right)) + 1;

		return lchild;
	}

	Laptop* leftRotate(Laptop* imbalancedNode)
	{
		Laptop* rchild = imbalancedNode->right;
		Laptop* temp = rchild->left;

		rchild->left = imbalancedNode;
		imbalancedNode->right = temp;

		imbalancedNode->height = max(height(imbalancedNode->left),
			height(imbalancedNode->right)) + 1;
		rchild->height = max(height(rchild->left),
			height(rchild->right)) + 1;

		return rchild;
	}

	int getBalance(Laptop* N)
	{
		if (N == NULL)
			return 0;
		return height(N->left) - height(N->right);
	}

	Laptop* minValueNode(Laptop* node)
	{
		Laptop* current = node;

		while (current->left != NULL)
			current = current->left;

		return current;
	}
public:

	Laptop* newNode(string ISBN,int qty,float p, string col, string br, int yr, string storage, string screen, string camera, string battery)
	{
		Laptop* laptop = new Laptop(ISBN,qty,p,col,br,yr,storage,screen,camera,battery);
		laptop->left = NULL;
		laptop->right = NULL;
		laptop->height = 1;
		return(laptop);
	}
	template<typename T>
	Laptop* insert(Laptop* node, Laptop* temp, T basis)
	{

		if (node == NULL)
			return temp;

		if (typeid(basis).name() == typeid(temp->key).name())
		{
			int tempVal = temp->key;
			int nodeVal = node->key;

			if (tempVal < nodeVal)
				node->left = insert(node->left, temp, basis);
			else if (tempVal > nodeVal)
				node->right = insert(node->right, temp, basis);
			else return node;

			node->height = 1 + max(height(node->left),
				height(node->right));

			int balance = getBalance(node);

			if (balance > 1)
			{
				int leftVal = node->left->key;
				if (tempVal < leftVal)
					return rightRotate(node);
				if (tempVal > leftVal)
				{
					node->left = leftRotate(node->left);
					return rightRotate(node);
				}

			}
			if (balance < -1)
			{
				int rightVal = node->right->key;
				if (tempVal > rightVal)
					return leftRotate(node);
				if (tempVal < rightVal)
				{
					node->right = rightRotate(node->right);
					return leftRotate(node);
				}
			}
		}

		else if (typeid(basis).name() == typeid(temp->ISBN).name())
		{
			string tempVal = temp->ISBN;
			string nodeVal = node->ISBN;

			if (tempVal < nodeVal)
				node->left = insert(node->left, temp, basis);
			else if (tempVal > nodeVal)
				node->right = insert(node->right, temp, basis);
			else return node;

			node->height = 1 + max(height(node->left),height(node->right));

			int balance = getBalance(node);
			if (balance > 1)
			{
				string leftVal = node->left->ISBN;

				if (tempVal < leftVal)
					return rightRotate(node);
				else if (tempVal > leftVal)
				{
					node->left = leftRotate(node->left);
					return rightRotate(node);
				}
			}
			else if (balance < -1)
			{
				string rightVal = node->right->ISBN;

				if (tempVal > rightVal)
					return leftRotate(node);
				if (tempVal < rightVal)
				{
					node->right = rightRotate(node->right);
					return leftRotate(node);
				}
			}
		}
		return node;

	}

	Laptop* deleteNode(Laptop* root, string ISBN)
	{

		if (root == NULL)
			return root;

		if (ISBN < root->ISBN)
			root->left = deleteNode(root->left, ISBN);
		else if (ISBN > root->ISBN)
			root->right = deleteNode(root->right, ISBN);
		else
		{
			if ((root->left == NULL) || (root->right == NULL))
			{
				Laptop* temp = root->left ? root->left : root->right;

				if (temp == NULL)
				{
					temp = root;
					root = NULL;
				}
				else
					*root = *temp;
				free(temp);
			}
			else
			{
				Laptop* temp = minValueNode(root->right);


				root->ISBN = temp->ISBN;
				root->right = deleteNode(root->right, temp->ISBN);
			}
		}

		if (root == NULL)
			return root;
		root->height = 1 + max(height(root->left), height(root->right));
		int balance = getBalance(root);
		if (balance > 1 && getBalance(root->left) >= 0)
			return rightRotate(root);
		if (balance > 1 && getBalance(root->left) < 0)
		{
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}
		if (balance < -1 && getBalance(root->right) <= 0)
			return leftRotate(root);
		if (balance < -1 && getBalance(root->right) > 0)
		{
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}

		return root;
	}

	void display(Laptop* root)
	{
		if (root == NULL)
			return;
		else if (root != NULL)
		{
			display(root->left);
			cout << *root;
			display(root->right);
		}
	}

	void update(Laptop* root, string ISBN)
	{
		if (root != NULL)
		{
			update(root->left, ISBN);
			if (root->ISBN == ISBN)
			{
				cin >> *root;
				return ;
			}
			update(root->right, ISBN);
		}
		else return ;
	}

	bool search(Laptop* root, string ISBN)
	{
		if (root != NULL)
		{
			search(root->left, ISBN);
			if (root->ISBN == ISBN)
			{
				cout << *root;
				return 1;
			}
			search(root->right, ISBN);
		}
		 return 0;
	}
};


class Inventory
{
	Laptop* root = NULL;
public:
	void AVLtoFile(Laptop* root, ofstream& InventoryFile)
	{
		Laptop data = Laptop();
		if (root == NULL)
		{
			return;
		}
		else if (root != NULL)
		{
			data = root;
			InventoryFile.write((char*)&data, sizeof(data));
			AVLtoFile(root->left, InventoryFile);
			AVLtoFile(root->right, InventoryFile);
		}
	}
	Laptop* FiletoAVL(string name, Laptop& data)
	{
		Laptop* root = NULL;
		Laptop* temp = NULL;
		AVL tree;
		ifstream file;
		file.open(name, ios::in);
		if (!file)
			cout << "Error while creating the file";
		else
		{
			file.seekg(0);
			file.read((char*)&data, sizeof(data));
			while (!file.eof())
			{
				temp = tree.newNode(data.ISBN,data.quantity,data.Price,data.Color,data.Brand,data.year,data.StorageCapacity,data.screenSize,data.CameraResolution,data.BatteryLife);
				root = tree.insert(root, temp, temp->ISBN);
				file.read((char*)&data, sizeof(data));
			}
		}
		file.close();
		return root;
	}
	bool checkSimilar(Laptop *root,Laptop &data,int flag)
	{
		if (root != NULL)
		{
			if (data==root)
			{
				root->increaseQty();
				flag = 1;
				return 1;
			}
			return checkSimilar(root->left, data, flag);
			return checkSimilar(root->right, data, flag);
		}
		return flag;	
	}
	bool search(Laptop* root, string ISBN)
	{
		if (root != NULL)
		{
			search(root->left, ISBN);
			if (root->ISBN == ISBN)
			{
				return 1;
			}
			search(root->right, ISBN);
		}
		return 0;
	}
};


class Menu
{
public:
	static void showMainPage()
	{
		system("cls");
		cout << "\t\t\t                                                                 \n\n\n";
		cout << "\t\t\t______________________        MAIN        ______________________\n\n";
		cout << "                                                                                \n\n";
		cout << "\t\t\t\t\t |          1 Admin           |" << endl;
		cout << "\t\t\t\t\t |          2 User            |" << endl;
		cout << "\t\t\t\t\t |          3 Exit            |" << endl;
		cout << "\n\t\t\t\t\t   Please Enter your choice : ";
	}
	static void showAdminMenu(string name)
	{
		system("cls");
		cout << "\n\n\t\t\t\t\t\t      WELCOME ";
		cout << "\n\n\t\t\t  _______________________      " << name << "     ______________________\n\n";
		cout << "\n\n\t\t\t______________________         MENU        ______________________\n\n";
		cout << "                                                                                \n\n";
		cout << "\t\t\t\t   |              1 Insert Items                |" << endl;
		cout << "\t\t\t\t   |              2 Update Items                |" << endl;
		cout << "\t\t\t\t   |              3 Remove Items                |" << endl;
		cout << "\t\t\t\t   |              4 Search Items                |" << endl;
		cout << "\t\t\t\t   |              5 Display Items               |" << endl;
		cout << "\t\t\t\t   |              6 Log Out			|" << endl;
		cout << "\n\t\t\t\t\t   Please Enter your choice : ";
	}
	
};


int main()
{
	system("cls");
	cout << "\n\n\n\n\t\t\t\t\t\t E - C O M M E R C E\n\n\t\t\t\t\t\t     S Y S T E M";
	printf("\n\n\n\t\t\t\t\t\t     loading....");
	Sleep(2500);

//	srand((unsigned)time(NULL));
	ofstream InventoryAdd;
	Inventory records;
	AVL tree;
	Laptop* root = NULL;
	Laptop* inputDetails = new Laptop();
	Laptop data;
	string id;

	User user;
	Admin admin;
	int  menuOption = 0, adminOption = 0,userOption=0, flag = 0;
	static int count = 0;
	fstream file;

	while (1)
	{
		menuOption = 0;
		flag = 0;
		Menu::showMainPage();
		cin >> menuOption;
		cout << endl;
		switch (menuOption)
		{
		case 1://ADMIN
			if (admin.login())
			{
				//Loading Inventory into AVL tree
				root = records.FiletoAVL("Inventory.txt", data);

				while (1)
				{
					if (flag == 1) break;
					Menu::showAdminMenu(admin.get_name());
					cin >> adminOption;
					switch (adminOption)
					{
					case 1://insert items
						system("cls");
						cin >> data;
						if (records.checkSimilar(root, data,0))
						{
							cout << "Item already exists! Stock Updated\n";
						}
						else
						{
							id = to_string(1 + rand() % 100);
							data.setISBN(id);
							inputDetails = tree.newNode(data.getISBN(), data.getQty(), data.getPrice(), data.getColor(), data.getBrand(), data.getYear(), data.getStorage(), data.getScreen(), data.getCamera(), data.getBattery());
							root = tree.insert(root, inputDetails, inputDetails->getISBN());
						}
						cout << endl << endl << endl;
						system("pause");
						break;
					case 2://update items
						system("cls");
						cin >> id;
						data.setISBN(id);
						if (records.search(root, data.getISBN()) == 0)
							cout << "\nInvalid ISBN\n";
						else
						{
							tree.update(root,data.getISBN());
							cout << "\nItem Deleted Successfully!\n\n";
						}
						system("pause");
						break;
					case 3://remove items
						system("cls");
						cin >> id;
						data.setISBN(id);
						if (records.search(root,data.getISBN())==0)
							cout << "\nInvalid ISBN\n";
						else
						{
							root=tree.deleteNode(root, data.getISBN());
							cout << "\nItem Deleted Successfully!\n\n";
						}
						//tree.display(root);
						system("pause");
						break;
					case 4://search items
						system("cls");
						cin >> id;
						data.setISBN(id);
						if (tree.search(root, data.getISBN()) == 0)
							cout << "\nInvalid ISBN\n\n";

						system("pause");
						break;
					case 5://display items
						system("cls");
						tree.display(root);
						system("pause");
						break;
					case 6://log out
						//Loading AVL into Inventory
						InventoryAdd.open("Inventory.txt", ios::out);
						records.AVLtoFile(root, InventoryAdd);
						InventoryAdd.close();
						flag = 1;
						cout << "\n\n\t\t\t\t\t         Logging Off...\n\n";
						Sleep(1000);
						break;
					default:
						cout << "\n\n\t\t\t\t   Please select from the options given above.\n" << endl;
						Sleep(1500);
						cin.clear();
						cin.ignore(1000, '\n');
					}
				}
			}
			else cout << "\n\t\t\t-Please enter the correct username and password";
			Sleep(1500);
			break;
		case 2://USER
			if (user.login())
			{
				while (1)
				{
					if (flag == 2) break;
					flag = 0;
					//Menu::showUserMenu(user.get_name());
					cin >> userOption;
					switch (userOption)
					{
					case 1://Search
						
						break;
					case 2://buy(shopping cart)
						
						break;
					case 3:
						break;
					case 4://log off
						flag = 2;
						cout << "\n\n\t\t\t\t\t         Logging Off...\n\n";
						Sleep(1000);
						break;
					default:
						cout << "\n\n\t\t\t\t   Please select from the options given above.\n" << endl;
						Sleep(2000);
						cin.clear();
						cin.ignore(1000, '\n');
					}
				}
			}
			else cout << "\n\t\t\t-Please enter the correct username and password";
			Sleep(2000);
			break;
		case 3://EXIT
			cout << "\t\t\t\t\t\t    Thank You!\n\n";
			exit(0);
			break;
		default:
			cout << "\n\n\t\t\t\t    Please select from the options given above.\n" << endl;
			Sleep(1500);
			cin.clear();//clears buffer
			cin.ignore(1000, '\n');//1000 characters ignore and skip to newline
			break;
		}
	}
}