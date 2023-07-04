/*********************************************************************
** Program Filename: shop.h
** Author: Joshua Spisak
** Date: 2/19/2023
** Description: header for shop class
*********************************************************************/

#ifndef SHOP_H
#define SHOP_H

#include <string>
#include <fstream>
#include "menu.h"
#include "order.h"

using namespace std;

class Shop {

  private:

    Menu m;
    string phone;
    string address;
    float revenue;
    Order *order_arr;
    int num_orders;

  public:
    //need to include accessor functions and mutator functions for private member when appropriate
    //need to include constructors and destructors where appropriate
    //need to use 'const' when appropriate

    //Suggested functions

    Shop();

    int load_data(ifstream &, ofstream& fo); //reads from files to correctly populate coffee, menu, etc.
    void view_menu();
    void view_address();
    void view_phone();
    void search_by_price(ofstream&);
    void search_by_name(ofstream&);
    void place_order_option(ofstream&);
    void get_order_for_order_option(string& name, char& size, int& quantity);
    void confirm_order(ofstream&, Order& new_order3, string& name, char& size, int& quantity);
    void entire_menu_order(ofstream& fo, Order& new_order3);
    void place_order(Order&);
    void add_to_menu();
    void remove_from_menu();
    void view_orders();
    void update_order_file(ofstream&);
    int check_negative(int price);
    int process_e(ofstream&);
    void process_c(ofstream&);

    /* 
     * big three
     */

    /* 
     * destructor
     */

    ~Shop();

    /* 
     * AOO
     */

    Shop& operator=(const Shop&);

    /* 
     * copy constructor
     */

    Shop(const Shop&);

};

#endif