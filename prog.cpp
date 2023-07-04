/*********************************************************************
** Program Filename: prog.cpp
** Author: Joshua Spisak
** Date: 2/19/2023
** Description: main function for assignment 3
*********************************************************************/

#include "shop.h"
#include <iostream>

/*********************************************************************
** Function: main
** Description: runs program
** Parameters: none
** Pre-Conditions:no error
** Post-Conditions: quits program
*********************************************************************/ 

int main()
{

	/* 
     * opens fstreams
     */

	ifstream fi;

	ofstream fo;

	Shop shop;

	/* 
     * checks if files opened
     */

	if(!shop.load_data(fi, fo)){

		cout << "The files did not open.";

		return 1;

	}

	/* 
     * loops until the user quits
     */

	while(true){

		cout << endl << "Welcome to Coffee++ Shop!" << endl << endl;

		cout << "Are you a customer (C) or employee (E) or would you like to quit (Q)? ";

		string person;

		cin >> person;

		/* 
     	 * checks for user type
     	 */

		if(person == "E"){

			cout << "Welcome my boss!" << endl;

			if(!shop.process_e(fo)){

				cout << "The files did not open.";

				return 1;

			}
		}

		if(person == "C"){

			shop.process_c(fo);

		}
		if(person == "Q"){

			cout << endl << "Bye!" << endl;

			break;

		}
	}

	return 0;

}