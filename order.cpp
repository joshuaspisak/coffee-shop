/*********************************************************************
** Program Filename: order.cpp
** Author: Joshua Spisak
** Date: 2/19/2023
** Description: order class
*********************************************************************/

#include "order.h"
#include <iostream>
#include <fstream>

/*********************************************************************
** Function: Order
** Description: default constructor
** Parameters: none
** Pre-Conditions:  object declared
** Post-Conditions: robject initialized
*********************************************************************/

Order::Order(){

    id = 0;
    coffee_name = "Some Coffee Order";
    coffee_size = 'X';
    quantity = -1;

}

/*********************************************************************
** Function: Order
** Description: constructor
** Parameters: int, string, char, int
** Pre-Conditions:  object declared
** Post-Conditions: initialized
*********************************************************************/

Order::Order(const int id, const string coffee_name, const char coffee_size, const int quantity){

    this->id = id;
    this->coffee_name = coffee_name;
    this->coffee_size = coffee_size;
    this->quantity = quantity;

}

/*********************************************************************
** Function: load_data
** Description: loads order data
** Parameters: ifstream
** Pre-Conditions:  ifstream declared
** Post-Conditions: order populated
*********************************************************************/

void Order::load_data(ifstream& fi){

    fi >> this->id >> this->coffee_name >> this->coffee_size >> this->quantity;

}

/*********************************************************************
** Function: print_order
** Description: prints order data
** Parameters: none
** Pre-Conditions:  order exists
** Post-Conditions: data printed
*********************************************************************/

void Order::print_order(){

    cout << endl << "Order " << this->id << ": " << this->quantity << " ";

    /* 
     * prints size based off size data
     */

    if(this->coffee_size == 's'){

        cout << "small";

    }

    if(this->coffee_size == 'm'){

        cout << "medium";

    }

    if(this->coffee_size == 'l'){

        cout << "large";

    }

    cout << " " << this->coffee_name << endl;

}

/*********************************************************************
** Function: set_last_search
** Description: setter
** Parameters: int
** Pre-Conditions:  called
** Post-Conditions: changed
*********************************************************************/

void Order::set_id(const int id){

    this->id = id;

}

/*********************************************************************
** Function: set_last_search
** Description: setter
** Parameters: string
** Pre-Conditions:  called
** Post-Conditions: changed
*********************************************************************/

void Order::set_coffee_name(const string coffee_name){

    this->coffee_name = coffee_name;

}

/*********************************************************************
** Function: set_last_search
** Description: setter
** Parameters: char
** Pre-Conditions:  called
** Post-Conditions: changed
*********************************************************************/

void Order::set_coffee_size(const char coffee_size){

    this->coffee_size = coffee_size;

}

/*********************************************************************
** Function: set_last_search
** Description: setter
** Parameters: int
** Pre-Conditions:  called
** Post-Conditions: changed
*********************************************************************/

void Order::set_quantity(const int quantity){

    this->quantity = quantity;

}

/*********************************************************************
** Function: get_id
** Description: getter
** Parameters: none
** Pre-Conditions:  called
** Post-Conditions: returned
*********************************************************************/

int Order::get_id(){

    return this->id;

}

/*********************************************************************
** Function: get_name
** Description: getter
** Parameters: none
** Pre-Conditions:  called
** Post-Conditions: returned
*********************************************************************/

string Order::get_name(){

    return this->coffee_name;

}

/*********************************************************************
** Function: get_coffee_size
** Description: getter
** Parameters: none
** Pre-Conditions:  called
** Post-Conditions: returned
*********************************************************************/

char Order::get_coffee_size(){

    return this->coffee_size;

}

/*********************************************************************
** Function: get_quantity
** Description: getter
** Parameters: none
** Pre-Conditions:  called
** Post-Conditions: returned
*********************************************************************/

int Order::get_quantity(){

    return this->quantity;

}