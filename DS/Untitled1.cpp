#include <iostream>
#include <string>
using namespace std;
class Laptop
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
		Laptop *ptr;
		Laptop()
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
};
void checkout(Laptop *root)
{
    int ch;
    printing(root);
    cout << "Select payment method: \n 1- Cash 2- Card";
    cin >> ch;

    if (ch == 1)
    {
        cout << "Please prepare $" << totalcost << " in cash. Thank you!" << endl;
    }
    else if (ch == 2)
    {
        int num;
        int pincode;
        cout << "Enter your card details: " << endl;
        cout << "Enter your Card number: ";
        cin >> num;

        // Check if the card number is valid
        if (isValidCardNumber(num))
        {
            cout << "Enter your PIN code: ";
            cin >> pincode;

            // Check if the PIN code is valid
            if (isValidPin(pincode))
            {
                cout << "Your order has been paid. Thank you for shopping!" << endl;
            }
            else
            {
                cout << "Invalid PIN code. Payment failed. Please try again." << endl;
            }
        }
        else
        {
            cout << "Invalid card number. Payment failed. Please try again." << endl;
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
    return (cardStr.length() == 16);
}

bool isValidPin(int pincode)
{
    // Check if the PIN code has a valid length (for example, 4 digits)
    string pinStr = to_string(pincode);
    return (pinStr.length() == 4));
}

int main()
{
    // Example usage
    long long cardNumber;
    int pincode;

    cout << "Enter your Card number: ";
    cin >> cardNumber;

    if (isValidCardNumber(cardNumber))
    {
        cout << "Enter your PIN code: ";
        cin >> pincode;

        if (isValidPin(pincode))
        {
            cout << "Card and PIN are valid. Proceed with the payment." << endl;
        }
        else
        {
            cout << "Invalid PIN code. Payment failed. Please try again." << endl;
        }
    }
    else
    {
        cout << "Invalid card number. Payment failed. Please try again." << endl;
    }

    return 0;
}
