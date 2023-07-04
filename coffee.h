/*********************************************************************
** Program Filename: coffee.h
** Author: Joshua Spisak
** Date: 2/19/2023
** Description: header for coffee class
*********************************************************************/

#ifndef COFFEE_H
#define COFFEE_H

#include <string>
#include <fstream>

using namespace std;

class Coffee {
  
  private:

    string name;
    float small_cost;
    float medium_cost;
    float large_cost;
    
  public:

    //need to include accessor functions and mutator functions for private member when appropriate
    //need to include constructors and destructors where appropriate
    //need to use 'const' when appropriate

    Coffee();
    Coffee(const string, const float, const float, const float);

    void load_data(ifstream &);
    void print_coffee();
    string get_name();
    float get_small_cost();
    float get_medium_cost();
    float get_large_cost();
    void set_small_cost(const float);
    void set_medium_cost(const float);
    void set_large_cost(const float);
};

#endif