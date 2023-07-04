/*********************************************************************
** Program Filename: menu.cpp
** Author: Joshua Spisak
** Date: 2/19/2023
** Description: menu class
*********************************************************************/

#include "menu.h"
#include "shop.h"
#include "order.h"
#include "coffee.h"
#include <iostream>

/*********************************************************************
** Function: Menu
** Description: default constructor
** Parameters: none
** Pre-Conditions: object declared
** Post-Conditions: object initialized
*********************************************************************/ 

Menu::Menu(){

    last_search = NULL;
    coffee_arr = NULL;
    num_coffee = 0;
    num_coffee_search = 0;

}

/*********************************************************************
** Function: load_data
** Description: loads menu data for member variables
** Parameters: ifstream, ofstream
** Pre-Conditions: fstreams declared
** Post-Conditions: menu data populated
*********************************************************************/ 

int Menu::load_data(ifstream &fi, ofstream& fo){

    int duplicates = 0;

    fi.open("menu.txt");

    /* 
     * checks if file opened
     */

    if(fi.is_open()){

        fi >> this->num_coffee;

        this->coffee_arr = new Coffee[this->num_coffee];

        for(int i = 0; i < this->num_coffee; i++){

            this->coffee_arr[i].load_data(fi);

        }

        this->confirm_menu();

        this->update_menu_file(fo);

        fi.close();

        return 1;

    }

    return 0;

}

/*********************************************************************
** Function: print_menu
** Description: default constructor
** Parameters: none
** Pre-Conditions: menu has data
** Post-Conditions: menu printed
*********************************************************************/ 

void Menu::print_menu(){

    cout << endl << "Here is our menu:" << endl;

    /* 
     * loops through coffees
     */

    for (int i = 0; i < this->num_coffee; i++)

    {

        cout << i+1 << ". ";

        coffee_arr[i].print_coffee();

    }

    cout << endl;

}

/*********************************************************************
** Function: check_negative
** Description: checks for negative
** Parameters: int
** Pre-Conditions: int declared
** Post-Conditions: 1 or 0 returned
*********************************************************************/ 

int Menu::check_negative(int price){

    if(price <= 0){

        cout << endl << "Enter positive values." << endl << endl;

        return 1;

    }

    return 0;

}

/*********************************************************************
** Function: confirm_menu
** Description: process for ensuring no duplicates
** Parameters: none
** Pre-Conditions: manu initialized
** Post-Conditions: no duplicates in menu
*********************************************************************/ 

void Menu::confirm_menu(){

    int duplicates = 0;

    int new_menu_size = 0;

    Coffee* new_menu = new Coffee[new_menu_size];

    /* 
     * looops through coffees
     */

    for(int i = 0; i < this->num_coffee; i++){

        if(!this->check_duplicates(new_menu, new_menu_size, this->coffee_arr[i].get_name())){

            new_menu = this->add_to_arr(new_menu, this->coffee_arr[i], new_menu_size);

        }

        else{

            duplicates++;

        }

    }

    /* 
     * frees memory
     */

    if(this->coffee_arr != NULL){

        delete [] this->coffee_arr;

        coffee_arr = NULL;

    }

    this->coffee_arr = new_menu;

    this->num_coffee -= duplicates;

}

/*********************************************************************
** Function: check_duplicates
** Description: checks duplicates
** Parameters: Coffee* int& string
** Pre-Conditions: menu declared
** Post-Conditions: 1 or 0 returned
*********************************************************************/ 

int Menu::check_duplicates(Coffee* new_menu, int& new_menu_size, string name){

    /* 
     * loops through array
     */

    for (int i = 0; i < new_menu_size; i++)

    {

        if(name == new_menu[i].get_name()){

            return 1;

        }

    }

    return 0;

}


/*********************************************************************
** Function: add_to_arr
** Description: adds a Coffee object to an arr
** Parameters: Coffee* Coffee& int&
** Pre-Conditions: object declared
** Post-Conditions: object added
*********************************************************************/ 

Coffee* Menu::add_to_arr(Coffee* old_arr, Coffee& coffee, int& new_menu_size){
    
    //allocate a new coffee array with size (num_coffee) + 1
	Coffee* new_arr = new Coffee[new_menu_size + 1];

	//loop thru all coffee objs in coffee_arr, 
	//copy them into our new array
	for (int i = 0; i < new_menu_size; i++)

	{

		new_arr[i] = old_arr[i];

	}

	//add the new coffee
	new_arr[new_menu_size] = coffee; 
	
	//free our old array pointed by coffee_arr
	if (old_arr != NULL){

		delete [] old_arr;

        old_arr = NULL;

    }

    new_menu_size++;

    return new_arr;
}

/*********************************************************************
** Function: get_info
** Description: gets new menu item info
** Parameters: string float& float& float&
** Pre-Conditions: user chose to add item
** Post-Conditions: info changed
*********************************************************************/ 

void Menu::get_info(string& new_n, float& new_s, float& new_m, float& new_l){

    cout << "Enter the name of the new coffee drink (in 1 word): ";

    cin >> new_n;

    /* 
     * loops until valid number is inputted
     */

    while(true){

        cout << "Enter price of small size (8oz): ";
    
        cin >> new_s;

        if(!this->check_negative(new_s)){

            break;

        }

    }

    while(true){

        cout << "Enter price of medium size (12oz): ";
    
        cin >> new_m;

        if(!this->check_negative(new_s)){

            break;

        }

    }

    while(true){

        cout << "Enter price of large size (16oz): ";
    
        cin >> new_l;

        if(!this->check_negative(new_s)){

            break;

        }

    }
}

/*********************************************************************
** Function: add_to_menu
** Description:  adds item to menu
** Parameters: none
** Pre-Conditions: user chose to add to menu
** Post-Conditions: object added
*********************************************************************/

void Menu::add_to_menu(){
    
    string new_n;

    float new_s;

    float new_m;

    float new_l;

    this->get_info(new_n, new_s, new_m, new_l);

    Coffee new_coffee(new_n, new_s, new_m, new_l);

    //allocate a new coffee array with size (num_coffee) + 1
	Coffee* new_arr = new Coffee[this->num_coffee + 1];

	//loop thru all coffee objs in coffee_arr, 
	//copy them into our new array
	for (int i = 0; i < this->num_coffee; i++)

	{

		new_arr[i] = this->coffee_arr[i];

	}

	//add the new coffee
	new_arr[this->num_coffee] = new_coffee; 
	
	//free our old array pointed by coffee_arr
	if (this->coffee_arr != NULL){

		delete [] this->coffee_arr;

        this->coffee_arr = NULL;

    }

	//set our coffee_arr to new_array
	this->coffee_arr = new_arr;

	//increment your size of the array, num_coffee
	this->num_coffee++;
}

/*********************************************************************
** Function: add_to_last_search
** Description: adds item to last search arr
** Parameters: Coffee
** Pre-Conditions: object declared
** Post-Conditions: object added
*********************************************************************/

void Menu::add_to_last_search(Coffee new_coffee){

    //allocate a new coffee array with size (num_coffee) + 1
	Coffee* new_arr = new Coffee[this->num_coffee_search];

	//loop thru all coffee objs in coffee_arr, 
	//copy them into our new array
	for (int i = 0; i < this->num_coffee_search - 1; i++)
	{

		new_arr[i] = this->last_search[i];

	}

	//add the new coffee
	new_arr[this->num_coffee_search - 1] = new_coffee; 
	
	//free our old array pointed by coffee_arr
	if (this->last_search != NULL){

		delete [] this->last_search;

        this->last_search = NULL;

    }

	//set our last_search to new_array
	this->last_search = new_arr;
}

/*********************************************************************
** Function: remove_from_menu
** Description: removes menu item
** Parameters: none
** Pre-Conditions: user chose to remove
** Post-Conditions: an item is removed
*********************************************************************/

void Menu::remove_from_menu(){
    
    cout << endl;
    
    /* 
     * loops through coffee array
     */

    for (int k = 0; k < this->num_coffee; k++)
    {

        cout << k+1 << ". " << this->coffee_arr[k].get_name() << endl;

    }

    cout << "Which of the drinks above would from our menu would you like to remove? Enter 1-" << this->num_coffee << ": ";

    int index_of_coffee_on_menu;

    cin >> index_of_coffee_on_menu;
    
    //allocate a new coffee array with size (num_coffee) - 1
	Coffee* new_arr = new Coffee[this->num_coffee - 1];

	//loop thru all coffee objs in coffee_arr, 
	//copy them into our new array except the index of the one we are removing
    int i = 0;

    while(i != index_of_coffee_on_menu - 1){

		new_arr[i] = this->coffee_arr[i];

        i++;

    }

    i++;

    if(i < this->num_coffee){

        for (int j = i; j < this->num_coffee; j++)
        {

            new_arr[j-1] = this->coffee_arr[i];

            i++;

        }
    }
	
	//free our old array pointed by coffee_arr
	if (this->coffee_arr != NULL){

		delete [] this->coffee_arr;

        this->coffee_arr = NULL;

    }

	//set our coffee_arr to new_array
	this->coffee_arr = new_arr;

	//decrease your size of the array, num_coffee
	this->num_coffee--;

    cout << endl << "This drink has been successfully removed from the menu!" << endl;
}

/*********************************************************************
** Function: update_menu_file
** Description: matches menu file to arr
** Parameters: ofstream&
** Pre-Conditions: fo declared
** Post-Conditions: file updated
*********************************************************************/

int Menu::update_menu_file(ofstream& fo){

    fo.open("menu.txt");

    if(fo.is_open()){

        fo << this->num_coffee << endl;

        /* 
         * loops through coffee array
         */

        for (int i = 0; i < this->num_coffee; i++)
        {

            fo << this->coffee_arr[i].get_name() << " " << this->coffee_arr[i].get_small_cost() << " " << this->coffee_arr[i].get_medium_cost() << " " << this->coffee_arr[i].get_large_cost() << endl;
        
        }

        fo.close();

        return 1;

    }

    return 0;

}

/*********************************************************************
** Function: search_coffee_by_name
** Description: process for searching by name
** Parameters: name
** Pre-Conditions:  user chose this option
** Post-Conditions: results shown
*********************************************************************/

Order Menu::search_coffee_by_name(string name){

    Order new_order;
    
    int order_made = 0;

    /* 
     * loops through coffee array
     */

    for (int i = 0; i < this->num_coffee; i++)

    {

        /* 
         * checks if name matches
         */

        if(name == this->coffee_arr[i].get_name()){

            this->num_coffee_search = 1;

            this->last_search = new Coffee[1];

            this->last_search[0] = this->coffee_arr[i];

            cout << "Results: " << endl << "1. ";

            this->coffee_arr[i].print_coffee();

            cout << "Would like to place an order based off the search results above? 1-yes, 0-no: ";

            int choice;

            cin >> choice;

            if(choice == 0){

                new_order.set_id(-1);

            }

            else if(choice == 1){

                this->choice1(new_order, order_made, name);

                if(order_made == 1){

                    return new_order;

                }
            }
        }
    }

    new_order.set_id(-1);

    return new_order;

}

/*********************************************************************
** Function: choice1
** Description: retrieves first choice
** Parameters: Order&, int&, string
** Pre-Conditions:  process initialized
** Post-Conditions: data changed
*********************************************************************/

void Menu::choice1(Order& new_order, int& order_made, string name){

    cout << "Enter the size: s-small, m-medium, l-large: ";

    char size;

    cin >> size;

    cout << "Enter quantity: ";

    int quantity;

    cin >> quantity;

    cout << endl << "Your total cost is: $" << this->calculate_cost(this->last_search[0].get_name(), size, quantity) << endl;

    cout << "Confirmed? 1-yes, 0-no: ";

    int choice2;

    cin >> choice2;

    /* 
     * checks if they want to confirm order
     */

    if(choice2 == 0){

        new_order.set_id(-1);

    }

    if(choice2 == 1){

        new_order.set_coffee_name(name);

        new_order.set_coffee_size(size);

        new_order.set_quantity(quantity);

        order_made = 1;

    }
}

/*********************************************************************
** Function: check_for_any_valid_sizes
** Description: checks for valid results
** Parameters: int, float
** Pre-Conditions:  option for this chosen
** Post-Conditions: results limited or not in some cases
*********************************************************************/

int Menu::check_for_any_valid_sizes(int coffee_index, float budget){

    if(this->coffee_arr[coffee_index].get_small_cost() <= budget || this->coffee_arr[coffee_index].get_medium_cost() <= budget || this->coffee_arr[coffee_index].get_large_cost() <= budget){
        
        return 1;
    
    }
    
    return 0;
}

/*********************************************************************
** Function: make_new_search
** Description: creates new search
** Parameters: float
** Pre-Conditions:  option for this chosen
** Post-Conditions: search made
*********************************************************************/

void Menu::make_new_search(float budget){

    /* 
     * loops through coffee array
     */

    for (int i = 0; i < this->num_coffee; i++)

    {

        if(this->check_for_any_valid_sizes(i, budget)){

            this->num_coffee_search++;

            /* 
             * makes new coffee object
             */

            Coffee new_coffee(this->coffee_arr[i].get_name(), -1, -1, -1);

            if(this->coffee_arr[i].get_small_cost() <= budget){

                new_coffee.set_small_cost(this->coffee_arr[i].get_small_cost());

            }
            if(this->coffee_arr[i].get_medium_cost() <= budget){

                new_coffee.set_medium_cost(this->coffee_arr[i].get_medium_cost());

            }

            if(this->coffee_arr[i].get_large_cost() <= budget){

                new_coffee.set_large_cost(this->coffee_arr[i].get_large_cost());

            }

            this->add_to_last_search(new_coffee);

        }
    }

    this->print_last_search();

}

/*********************************************************************
** Function: search_coffee_by_price
** Description: process for choosing by price
** Parameters: float
** Pre-Conditions:  option for this chosen
** Post-Conditions: search done
*********************************************************************/

Order Menu::search_coffee_by_price(float budget){

    Order new_order;

    this->last_search = new Coffee[0];

    this->num_coffee_search = 0;

    this->make_new_search(budget);

    /* 
     * checks if search had something
     */

    if(this->num_coffee_search == 0){

        cout << endl << "Sorry, none of our items meet your budget" << endl;

        new_order.set_id(-1);

        return new_order;

    }

    else{

        /* 
         * asks to order or not
         */

        cout << "Would like to place an order based off the search results above? 1-yes, 0-no: ";

        int choice;

        cin >> choice;

        if(choice == 0){

            new_order.set_id(-1);

            return new_order;
            
        }

        else if(choice == 1){

            this->get_order(new_order);

            return new_order;

        }
    }
}

/*********************************************************************
** Function: get_order
** Description: gets order data
** Parameters: new_order
** Pre-Conditions:  option for this chosen
** Post-Conditions: order data changed
*********************************************************************/

void Menu::get_order(Order& new_order){

    cout << "Select the number associated with the coffee you want to order: ";

    int selection;

    cin >> selection;

    string name;

    /* 
     * loops through search
     */

    for (int k = 0; k < this->num_coffee_search; k++)

    {

        if(selection == k+1){

            name = this->last_search[k].get_name();

        }

    }

    cout << "Enter the size: s-small, m-medium, l-large: ";

    char size;

    cin >> size;

    cout << "Enter quantity: ";

    int quantity;

    cin >> quantity;

    cout << endl << "Your total cost is: $" << this->calculate_cost(name, size, quantity) << endl;

    cout << "Confirmed? 1-yes, 0-no: ";

    int choice2;

    cin >> choice2;

    /* 
     * checks for second choice
     */

    if(choice2 == 0){

        new_order.set_id(-1);

    }

    if(choice2 == 1){

        new_order.set_coffee_name(name);

        new_order.set_coffee_size(size);

        new_order.set_quantity(quantity);

    }
}

/*********************************************************************
** Function: calculates_cost
** Description: gets cost for order
** Parameters: string, char, int
** Pre-Conditions:  order exists
** Post-Conditions: returns float
*********************************************************************/

float Menu::calculate_cost(string coffee_name, char size, int quantity){

    /* 
     * loops through coffee array
     */

    for (int i = 0; i < this->num_coffee; i++)
    {

        if(this->coffee_arr[i].get_name() == coffee_name){

            if(size == 's'){

                return quantity*this->coffee_arr[i].get_small_cost();

            }

            if(size == 'm'){

                return quantity*this->coffee_arr[i].get_medium_cost();

            }

            if(size == 'l'){

                return quantity*this->coffee_arr[i].get_large_cost();

            }
        }
    }
    
}

/*********************************************************************
** Function: print_last_search
** Description: prints last search data
** Parameters:none
** Pre-Conditions:  last search was made
** Post-Conditions: results printed
*********************************************************************/

void Menu::print_last_search(){

    /* 
     * loops through search
     */

    for (int i = 0; i < this->num_coffee_search; i++)

    {

        cout << i+1 << ". ";

        this->last_search[i].print_coffee();

    }
    
}

/*********************************************************************
** Function: get_num_coffee_search
** Description: getter
** Parameters: none
** Pre-Conditions:  called
** Post-Conditions: returned
*********************************************************************/

int Menu::get_num_coffee_search(){

    return this->num_coffee_search;

}

/*********************************************************************
** Function: get_num_coffee
** Description: getter
** Parameters: none
** Pre-Conditions:  called
** Post-Conditions: returned
*********************************************************************/

int Menu::get_num_coffee(){

    return this->num_coffee;

}

/*********************************************************************
** Function: get_last_search
** Description: getter
** Parameters: none
** Pre-Conditions:  called
** Post-Conditions: returned
*********************************************************************/

Coffee* Menu::get_last_search(){

    return this->last_search;

}

/*********************************************************************
** Function: get_coffee_arr
** Description: getter
** Parameters: none
** Pre-Conditions:  called
** Post-Conditions: returned
*********************************************************************/

Coffee* Menu::get_coffee_arr(){

    return this->coffee_arr;

}

/*********************************************************************
** Function: ~Menu
** Description: destructor
** Parameters: none
** Pre-Conditions: object exists
** Post-Conditions: object destroyed
*********************************************************************/ 

//destructor
Menu::~Menu(){

	if (this->coffee_arr != NULL){

		delete [] this->coffee_arr;

		this->coffee_arr = NULL;

	}

    if (this->last_search != NULL){

		delete [] this->last_search;

		this->last_search = NULL;

    }
}

/*********************************************************************
** Function: operator=
** Description: AOO
** Parameters: Menu&
** Pre-Conditions: object already declared
** Post-Conditions: object changed
*********************************************************************/ 

//AOO
//c3 = c4
Menu& Menu::operator=(const Menu& old_m){

	this->num_coffee = old_m.num_coffee;

	//free memory first
	if (this->coffee_arr != NULL){

		delete [] this->coffee_arr;

		this->coffee_arr = NULL;

	}

	//deep copy
	this->coffee_arr = new Coffee[this->num_coffee];

	for (int i = 0; i < this->num_coffee; i++)
	{

		this->coffee_arr[i] = old_m.coffee_arr[i];

	}
	
	//this->std_names = old_c.std_names; //not correct!!
	return *this;

}

/*********************************************************************
** Function: Menu
** Description: copy constructor
** Parameters: Menu&
** Pre-Conditions: object being declared on same line
** Post-Conditions: object initialized
*********************************************************************/ 

//copy constructor 
//Course c5 = c3;
Menu::Menu(const Menu& old_m){

	this->num_coffee = old_m.num_coffee;

	//deep copy
	this->coffee_arr = new Coffee[this->num_coffee];
    
	for (int i = 0; i < this->num_coffee; i++)
	{

		this->coffee_arr[i] = old_m.coffee_arr[i];

	}

}