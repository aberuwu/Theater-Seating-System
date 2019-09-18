/*
File: TheaterSeating.cpp
Written by: Cesar I. Mendoza (aberuwu)
Fall 2018 - CIS2541 - C++

Purpose: Simulate a theater seating system.  
		 -Allow user to load predifined seating scheme and seating 
		  prices from external .dat file.  
		 -Allow user to 'purchase' seats.
		 -Allow user to change prices by row.
		 -Allow user to visualize entire seating scheme
		 -Keeps track of total sales
		 -Saves all changes to seperate .dat files
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

// Function prototypes
void loadSeats(char[][30]);
void displaySeatingChart(char[][30], float[]);
void loadPrices(float[]);
float purchaseTickets(char[][30], float[]);
int menu(int ticketTotals);
void savePrices(float price[]);
void saveSeats(char[][30], int);
void changePrices(float[]);


// Global Variables
const int ROWS = 15;
const int SEATS = 30;
const int PRICE_SEAT = 15;
const char TAKEN = '*';
const char EMPTY = '#';
float total = 0;
int numTickets = 0;
float total2 = 0;
float price[PRICE_SEAT];
char seats[ROWS][SEATS];


// Function: loadingFunction (used to load parameters before running main function)
// Parameters: none
// Returns: nothing
void loadingFunction()
{
	loadSeats(seats);
	loadPrices(price);
}
class Base {
public:
	Base() { loadingFunction(); }
};

Base b;


// Function: main()
// Parameters: mainMenu
// Returns: function outputs and 0
int main()
{
	int mainMenu;

	system("CLS");
	mainMenu = menu(total2);

	if (mainMenu == 1)
	{
		system("CLS");
		cout << setw(29) << right << "Seats" << endl;
		displaySeatingChart(seats, price);
		cout << endl;
		system("pause");
		system("CLS");
		main();
	}
	else if (mainMenu == 2)
	{
		system("CLS");
		cout << setw(29) << right << "Seats";
		purchaseTickets(seats, price);

	}
	else if (mainMenu == 3)
	{
		system("CLS");
		changePrices(price);
	}
	else if (mainMenu == 4)
	{
		exit(0);
	}

	while (mainMenu > 4 || mainMenu < 1)
	{
		cout << "*** Invalid Choice ***" << endl;
		system("pause");
		system("CLS");
		main();
	}

	return 0;
}


// Function: loadSeats (char seats)
// Parameters: seats - array of seats
// Returns: nothing
void loadSeats(char seats[][SEATS])
{
	string fileName = "seatingChart.dat";
	int numSeats = 0;
	char newSeat = EMPTY;

	ifstream inFile;

	inFile.open(fileName);

	if (!inFile)
	{
		cout << "seatingChart.dat not found...loading pre-defined seating chart..." << endl;

		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < SEATS; j++)
			{
				seats[i][j] = EMPTY;
			}
		}
	}
	else
	{
		cout << "Found file...loading saved seating chart..." << endl;

		(inFile, newSeat);

		while (!inFile.eof())
		{
			for (int i = 0; i < ROWS; i++)
			{
				for (int j = 0; j < SEATS; j++)
				{
					inFile >> seats[i][j];
				}
			}

		}

	}

	inFile.close();

	system("pause");
	system("CLS");
}

// Function: loadPrices (float price)
// Parameters: price - array of row priceing
// Returns: nothing
void loadPrices(float price[])
{
	string fileName = "rowPrice.dat";
	int numSeats = 0;
	string newSeat;

	ifstream inFile;

	inFile.open(fileName);

	if (!inFile)
	{
		cout << "rowPrice.dat not found...loading default price to $15..." << endl;

		for (int i = 0; i < ROWS; i++)
		{
			price[i] = PRICE_SEAT;
		}
	}
	else
	{
		cout << "Found file...loading custom prices..." << endl;

		for (int i = 0; i < ROWS; i++)
		{
			inFile >> price[i];
		}
	}

	system("pause");
	system("CLS");
}

// Function: changePrices (float price)
// Parameters: price
// Returns: nothing
void changePrices(float price[])
{
	int choice;
	float newPrice;
	char exitSelection;

	cout << "*** " << "Change Seating Price" << " ***" << endl;
	cout << endl;

	cout << setprecision(2) << fixed;
	for (int i = 0; i < ROWS; i++)
	{

		cout << "Row " << i + 1 << "\t  " << "$" << price[i] << endl;
	}


	do
	{
		cout << endl;
		cout << "Enter Row Number to Change: ";
		cin >> choice;

		while (choice > 15 || choice <= 0)
		{
			cout << "Error! Please enter a value between 1 and " << ROWS << endl;
			cout << "Try again: ";
			cin >> choice;
		}

		cout << "Enter New Price: ";
		cin >> newPrice;

		while (newPrice < 0)
		{
			cout << "Error! Price cannot be less than 0.00" << endl;
			cout << "Try again: ";
			cin >> newPrice;
		}


		if (choice == 1)
		{
			price[0] = newPrice;
		}
		else if (choice == 2)
		{
			price[1] = newPrice;
		}
		else if (choice == 3)
		{
			price[2] = newPrice;
		}
		else if (choice == 4)
		{
			price[3] = newPrice;
		}
		else if (choice == 5)
		{
			price[4] = newPrice;
		}
		else if (choice == 6)
		{
			price[5] = newPrice;
		}
		else if (choice == 7)
		{
			price[6] = newPrice;
		}
		else if (choice == 8)
		{
			price[7] = newPrice;
		}
		else if (choice == 9)
		{
			price[8] = newPrice;
		}
		else if (choice == 10)
		{
			price[9] = newPrice;
		}
		else if (choice == 11)
		{
			price[10] = newPrice;
		}
		else if (choice == 12)
		{
			price[11] = newPrice;
		}
		else if (choice == 13)
		{
			price[12] = newPrice;
		}
		else if (choice == 14)
		{
			price[13] = newPrice;
		}
		else if (choice == 15)
		{
			price[14] = newPrice;
		}


		system("CLS");
		cout << "*** " << "Change Seating Price" << " ***" << endl;
		cout << endl;
		for (int i = 0; i < ROWS; i++)
		{

			cout << "Row " << i + 1 << "\t  " << "$" << price[i] << endl;
		}

		cout << endl;
		cout << "Do you want to change another? (y/n): ";
		cin >> exitSelection;

	} while (exitSelection == 'y' || exitSelection == 'Y');

	savePrices(price);

	main();
}

// Function: savePrices (float price)
// Parameters: price
// Returns: nothing
void savePrices(float price[])
{
	string fileName = "rowPrice.dat";

	ofstream outFile;

	outFile.open(fileName);

	for (int i = 0; i < ROWS; i++)
	{
		outFile << price[i] << endl;
	}

	outFile.close();
}

// Function: saveSeats (char seats, int ticketTotals)
// Parameters: seats, ticketTotals
// Returns: nothing
void saveSeats(char seats[][30], int ticketTotals)
{
	string fileName = "seatingChart.dat";

	ofstream outFile;

	outFile.open(fileName);

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < SEATS; j++)
		{
			outFile << seats[i][j] << endl;
		}
	}

	outFile.close();
}

// Function: menu (int total2)
// Parameters: total2 - The total sales of current session
// Returns: choice
int menu(int total2)
{
	int choice;

	cout << "*** Main Menu***" << endl;
	cout << "*** Sales This Session " << "($" << total2 << ")" << " ***" << endl;
	cout << endl;
	cout << "1. Display Seating Chart" << endl;
	cout << "2. Purchase Tickets" << endl;
	cout << "3. Change Ticket Prices" << endl;
	cout << "4. Exit" << endl;
	cout << "Enter Choice: ";
	cin >> choice;

	return choice;
}

// Function: displaySeatingChart (char seats, float price)
// Parameters: seats - Seats in array
//             price - price per row
// Returns: nothing
void displaySeatingChart(char seats[][SEATS], float price[])
{
	int displayChart = 0;
	char choice;
	cout << endl << "            ";


	for (int i = 0; i < 30; i++)
	{

		displayChart = displayChart++;

		while (displayChart > 9)
		{
			displayChart = -1;
			displayChart = displayChart++;
		}

		cout << displayChart;
	}

	for (int j = 0; j < ROWS; j++)
	{
		cout << endl << " Row " << j + 1 << setw(6) << right;

		if (j < 9)
		{
			cout << "";
		}
		for (int i = 0; i < SEATS; i++)
		{
			cout << seats[j][i] << "";
		}

		cout << setprecision(2) << fixed;
		cout << "      " << "$" << price[j];
	}

}

// Function: purchaseTickets (char seats, float price)
// Parameters: seats - Seats in array
//             price - price per row
// Returns: nothing
float purchaseTickets(char seats[][SEATS], float price[])
{
	int displayChart = 0;
	int rowNumber = 0;
	int columnNumber = 0;
	int ticketTotal = 0;
	char choice;
	cout << endl << "            ";

	displaySeatingChart(seats, price);

	do
	{
		cout << endl << endl;
		cout << "Enter Row: ";
		cin >> rowNumber;
		rowNumber -= 1;

		while (rowNumber < 0 || rowNumber > ROWS - 1)
		{
			cout << "Error! Please enter a number between 1 and " << ROWS << endl;
			cout << "Try again: ";
			cin >> rowNumber;
			rowNumber -= 1;
		}

		cout << "Enter Seat: ";
		cin >> columnNumber;
		columnNumber -= 1;

		while (columnNumber < 0 || columnNumber > SEATS - 1)
		{
			cout << "Error! Please enter a number between 1 and " << SEATS << endl;
			cout << "Try again: ";
			cin >> columnNumber;
			columnNumber -= 1;
		}
		while (seats[rowNumber][columnNumber] == TAKEN)
		{
			cout << "One or more of the selected seats is taken" << endl;
			cout << "Try again - Enter seat number: ";
			cin >> columnNumber;
			columnNumber -= 1;
		}

		cout << "Number of tickets: ";
		cin >> numTickets;

		while (numTickets > SEATS)
		{
			cout << "Error! You entered an invalid ammount of seats!" << endl;
			cout << "Try again: ";
			cin >> numTickets;
		}
		if (numTickets == 1)
		{
			seats[rowNumber][columnNumber] = TAKEN;
			ticketTotal++;
		}
		else if (numTickets > 1)
		{
			for (int i = columnNumber; i < numTickets + (columnNumber); i++)
			{
				seats[rowNumber][i] = TAKEN;

				if (seats[rowNumber][i] == TAKEN)
				{
					ticketTotal++;
				}
			}

		}

		system("CLS");
		displaySeatingChart(seats, price);


		cout << endl;
		cout << numTickets << " @ " << "$" << price[rowNumber] << " = " << "$" << ticketTotal * price[rowNumber] << endl;
		total2 += ticketTotal * price[rowNumber];

		ticketTotal = 0;

		cout << "Do you want to purchase more? (y/n): " << endl;
		cin >> choice;

	} while (choice == 'y' || choice == 'Y');

	saveSeats(seats, ticketTotal);

	main();

	return ticketTotal;
}