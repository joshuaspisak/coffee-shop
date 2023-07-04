/*********************************************************************
** Program Filename: menu.h
** Author: Joshua Spisak
** Date: 2/19/2023
** Description: header for menu class
*********************************************************************/

#ifndef MENU_H
#define MENU_H 

#include <string>
#include <fstream>
#include "coffee.h"
#include "order.h"

using namespace std;

class Menu {
  private:

    int num_coffee;
    int num_coffee_search;
    Coffee* coffee_arr;
    Coffee* last_search;

  public:

    //need to include accessor functions and mutator functions for private member when appropriate
    //need to include constructors, copy constructors, assignment operator overload,
    //and destructors where appropriate
    //need to use 'const' when appropriate

    Menu();

    // Suggested functions:
    Order search_coffee_by_name(string name); 
    int check_for_any_valid_sizes(int coffee_index, float budget);
    Order search_coffee_by_price(float budget); 
    void add_to_menu(); //add a coffee object into the Menu
    void add_to_last_search(Coffee new_coffee);
    void remove_from_menu(); //remove a coffee object from the Menu
    int update_menu_file(ofstream&);
    void get_info(string& new_n, float& new_s, float& new_m, float& new_l);
    void confirm_menu();
    int check_duplicates(Coffee* new_menu, int& new_menu_size, string name);
    int check_negative(int price);
    Coffee* add_to_arr(Coffee* old_arr, Coffee& coffee, int& new_menu_size);
    float calculate_cost(string, char, int);
    int load_data(ifstream &, ofstream& fo);
    void print_menu();
    void print_last_search();
    int get_num_coffee_search();
    int get_num_coffee();
    Coffee* get_last_search();
    Coffee* get_coffee_arr();
    void make_new_search(float budget);
    void choice1(Order& new_order, int& order_made, string name);
    void get_order(Order& new_order);

    /* 
     * Big Three
     */


    /* 
     * destructor
     */
    ~Menu();

    /* 
     * AOO
     */
    Menu& operator=(const Menu&);

    /* 
     * copy constructor
     */
    Menu(const Menu&);


};

#endif