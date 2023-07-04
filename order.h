/*********************************************************************
** Program Filename: order.h
** Author: Joshua Spisak
** Date: 2/19/2023
** Description: header for order class
*********************************************************************/

#ifndef ORDER_H
#define ORDER_H 

#include <string>

using namespace std;

class Order
{

private:

	int id;
	string coffee_name;
	char coffee_size;
	int quantity;

public:

	//need to include accessor functions and mutator functions for private member when appropriate
    //need to include constructors and destructors where appropriate
    //need to use 'const' when appropriate

	Order();
	Order(const int, const string, const char, const int);

	void load_data(ifstream&);
	void print_order();
	int get_id();
	string get_name();
	char get_coffee_size();
	int get_quantity();
	void set_id(const int);
	void set_coffee_name(const string);
	void set_coffee_size(const char);
	void set_quantity(const int);
	
};
#endif