/*********************************************************************
** Program Filename: coffee.cpp
** Author: Joshua Spisak
** Date: 2/19/2023
** Description: coffeev class
*********************************************************************/

#include "shop.h"
#include "order.h"
#include "menu.h"
#include <iostream>

/*********************************************************************
** Function: Coffee
** Description: default constructor
** Parameters: none
** Pre-Conditions:  object declared
** Post-Conditions: object initialized
*********************************************************************/

Coffee::Coffee(){

    name = "Some Coffee";
    small_cost = 0;
    medium_cost = 0;
    large_cost = 0;

}

/*********************************************************************
** Function: Coffee
** Description:  constructor
** Parameters: string, float, float, floatS
** Pre-Conditions:  object declared
** Post-Conditions: object initialized
*********************************************************************/

Coffee::Coffee(const string n, const float s, const float m, const float l){
    
    name = n;
    small_cost = s;
    medium_cost = m;
    large_cost = l;

}

/*********************************************************************
** Function: load_data
** Description: populates coffee member variables
** Parameters: ifstream
** Pre-Conditions:  ifstream declared
** Post-Conditions: data populated
*********************************************************************/

void Coffee::load_data(ifstream &fi){

    fi >> this->name >> this->small_cost >> this->medium_cost >> this->large_cost;

}

/*********************************************************************
** Function: print_coffee
** Description: prints coffee data
** Parameters: none
** Pre-Conditions:  object exists
** Post-Conditions: data printed
*********************************************************************/

void Coffee::print_coffee(){

    cout << this->name << endl;

    /* 
     * checks to make sure cost is eligible
     */

    if(this->small_cost != -1){

        cout << "   Small - " << this->small_cost << endl;

    }
    
    if(this->medium_cost != -1){

        cout << "   Medium - " << this->medium_cost << endl;

    }
    
    if(this->large_cost != -1){

        cout << "   Large - " << this->large_cost << endl;

    }
}

/*********************************************************************
** Function: get_name
** Description: getter
** Parameters: none
** Pre-Conditions:  called
** Post-Conditions: returned
*********************************************************************/

string Coffee::get_name(){

    return this->name;

}

/*********************************************************************
** Function: get_small_cost
** Description: getter
** Parameters: none
** Pre-Conditions:  called
** Post-Conditions: returned
*********************************************************************/

float Coffee::get_small_cost(){

    return this->small_cost;

}

/*********************************************************************
** Function: get_medium_cost
** Description: getter
** Parameters: none
** Pre-Conditions:  called
** Post-Conditions: returned
*********************************************************************/

float Coffee::get_medium_cost(){

    return this->medium_cost;

}

/*********************************************************************
** Function: get_large_cost
** Description: getter
** Parameters: none
** Pre-Conditions:  called
** Post-Conditions: returned
*********************************************************************/

float Coffee::get_large_cost(){

    return this->large_cost;

}

/*********************************************************************
** Function: set_last_search
** Description: setter
** Parameters: float
** Pre-Conditions:  called
** Post-Conditions: changed
*********************************************************************/

void Coffee::set_small_cost(const float s){

    this->small_cost = s;

}

/*********************************************************************
** Function: set_last_search
** Description: setter
** Parameters: float
** Pre-Conditions:  called
** Post-Conditions: changed
*********************************************************************/

void Coffee::set_medium_cost(const float m){

    this->medium_cost = m;

}

/*********************************************************************
** Function: set_last_search
** Description: setter
** Parameters: float
** Pre-Conditions:  called
** Post-Conditions: changed
*********************************************************************/

void Coffee::set_large_cost(const float l){

    this->large_cost = l;
    
}