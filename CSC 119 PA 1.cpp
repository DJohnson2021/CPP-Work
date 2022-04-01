#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
using namespace std;

struct menuItemType
{
	//string type component
	string menuItem;
	//double type component
	double menuPrice;
}; //end of struct menuItemType

//constant declaration
const double TAX = 0.05;
const int MAXITEMS= 10;

int s = 0;

//function prototype declaration
void getData(menuItemType menuList[], int &s);
void showMenu(menuItemType menuList[], int s);
void printCheck(menuItemType menuList[], int s);

//main function
int main()
{
	//create an array for menuItemType
	menuItemType menuList[MAXITEMS];
	
	//call getData function
	getData(menuList, s);
	
	//call showMenu function and display menu
	//get order from user
	showMenu(menuList, s);
	int j = 0;    //literally to track the customer's order
	//track customer order
	int customerOrderList[MAXITEMS];
	
	//get the customer's order 
	while(true)
	{
		int customerItem;
		cout <<"\nEnter Desired Menu Item Number" 
			"(Enter any other number to exit): " << endl;
		cin >> customerItem; //read the customer's chosen item number
		
		if(customerItem < 1 || customerItem> s)
			break;
		customerOrderList[j] = customerItem;
		j++;
	}
	//call print check or bill function
	printCheck(menuList, s);
	
	system("pause");
	return 0;
}//end of main function

//getData function definition
//this function loads the data into the array menuList
//describes the name and price of each member of array menuList
void getData(menuItemType menuList[], int &s)
{
	menuList[0].menuItem = "Plain Egg";
	menuList[0].menuPrice = 1.45;
	
	menuList[1].menuItem = "Bacon and Egg";
	menuList[1].menuPrice = 2.45;
	
	menuList[2].menuItem = "Muffin";
	menuList[2].menuPrice = 0.99;;
	
	menuList[3].menuItem = "French Toast";
	menuList[3].menuPrice = 1.99;
	
	menuList[4].menuItem = "Fruit Basket";
	menuList[4].menuPrice = 2.49;
	
	menuList[5].menuItem = "Cereal";
	menuList[5].menuPrice = 0.69;
	
	menuList[6].menuItem = "Coffee";
	menuList[6].menuPrice = 0.50;
	
	menuList[7].menuItem = "Tea";
	menuList[7].menuPrice = 0.75;
	
	s = 8;
}//end of getData function

//showMenu function definition
//function shows the different items offered on the menu and tells the user how to select the items.
void showMenu(menuItemType menuList[], int s)
{
	cout<< "Welcome to Johnnny's Restaurant!" << endl;
	cout << "--------------MENU-------------" << endl;
	for(int j = 0; j < s; j++)
	{
		cout<< (j + 1) << ". " << left << setw(21)
			<< menuList[j].menuItem << "$" << setw(6)
			<< setprecision(2) << fixed << menuList[j].menuPrice
			<< endl;
	}
}//end of showMenu function

//printCheck function definition
//function calculates and prints the check
void printCheck(menuItemType menuList[], int s)
{
	int k;
	double price = 0;
	double tax = 0;
	double total;
	
	cout << "\n-----------Your Bill-----------" << endl;
	cout << "Welcome to Johnny's Restaurnant!" << endl;
	cout << setprecision(2) << fixed;
	
	for(k = 0; k < s; k++)
	{	
		cout << setw(15)
		<< left << menuList[k].menuItem
		<< right << setw(10) << "$"
		<< setprecision(2) << fixed << menuList[k].menuPrice
		<< endl;
			
		//calculate the price without tax
		price = price + menuList[k].menuPrice;	
	}
	//calculate tax and the total price of the order
	tax = TAX*price;
	total = tax + price;
	
	//print tax 
	cout << setw(15) << left << "Tax: "
		<< right << setw(10) << "$"
		<< tax << endl;
	
	//print total amount due
	cout << setw(15) << left << "Amount Due: "
		<< right << setw(10) << "$"
		<< total << endl;
}//end of printCheck function
