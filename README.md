# Theater-Seating-System
Small C++ console program that simulates a theater seating system.  <br/>

# Purpose and Usage
Created for my Intro to C++ class in 2018, this small program simulates a theater seating system.<br/>
     -Allow user to load predifined seating scheme and seating prices from external .dat file.  <br/>
		 -Allow user to 'purchase' seats.<br/>
		 -Allow user to change prices by row.<br/>
		 -Allow user to visualize entire seating scheme<br/>
		 -Keeps track of total sales<br/>
		 -Saves all changes to seperate .dat files<br/>
     
# Specific Concepts Used

-Multi-dimentional arrays <br/>
-ofstream <br/>
-ifstreawm <br/>

# Usage

-Upon startup the program will attempt to load from 'rowPrice.dat' and 'seatingChart.dat'<br/>
 If files not present it will load the default values<br/>
-Program Main menu has 4 selection options...<br/>
  1 - Display Seating Chart: Allows you to view seating chart for available seats and current prices<br/>
  2 - Purchase Tickets: Allows you to purchase tickets by inputing row number and ammount of tickets desired<br/>
  3 - Change Ticket Prices: Allows you to change ticket prices based on row<br/>
  4 - Exit: Does what it implies<br/>
 <br/>
 -All changes are automatically saved upon exit.



