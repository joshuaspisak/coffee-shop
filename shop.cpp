/*********************************************************************
** Program Filename: shop.cpp
** Author: Joshua Spisak
** Date: 2/19/2023
** Description: shop class
*********************************************************************/

#include "shop.h"
#include <iostream>

/*********************************************************************
** Function: Shop
** Description: default constructor
** Parameters: none
** Pre-Conditions:Shop object is declared
** Post-Conditions:Shop object is initialized
*********************************************************************/ 

Shop::Shop(){

    this->order_arr = NULL;
    num_orders = 0;
    phone = "Some Phone";
    address = "Some Address";
    revenue = 0;

}

/*********************************************************************
** Function: load_data
** Description:loads data into the shop member variables
** Parameters: ifstream and ofstream
** Pre-Conditions:fstreams are declared
** Post-Conditions:member variables are full
*********************************************************************/ 

int Shop::load_data(ifstream &fi, ofstream& fo){

    fi.open("shop_info.txt");

    if(!fi.is_open()){

        return 0;

    }

    getline(fi, this->phone);

    getline(fi, this->address);
    
    fi.close();

    if(!this->m.load_data(fi, fo)){

        return 0;

    }

    fi.open("orders.txt");

    /* 
     * checks if file opened
     */

    if(!fi.is_open()){

        return 0;

    }

    fi >> this->num_orders;

    this->order_arr = new Order[this->num_orders];

    /* 
     * loops through orders
     */

    for (int i = 0; i < this->num_orders; i++)

    {

        this->order_arr[i].load_data(fi);

    }

    for (int j = 0; j < this->num_orders; j++)

    {

        this->revenue += this->m.calculate_cost(this->order_arr[j].get_name(), this->order_arr[j].get_coffee_size(), this->order_arr[j].get_quantity());

    }

    return 1;

}

/*********************************************************************
** Function: place_order
** Description: adds order to array
** Parameters: order object
** Pre-Conditions: object is declared
** Post-Conditions: order added
*********************************************************************/ 

void Shop::place_order(Order& order){

    //allocate a new order array with size (num_order) + 1
	Order* new_arr = new Order[this->num_orders + 1];

	//loop thru all order objs in order_arr, 
	//copy them into our new array

	for (int i = 0; i < this->num_orders; i++)
	{

		new_arr[i] = this->order_arr[i];

	}

	//add the new coffee
	new_arr[this->num_orders] = order; 
	
	//free our old array pointed by order_arr
	if (this->order_arr != NULL){

		delete [] this->order_arr;

        this->order_arr = NULL;

    }

	//set our order_arr to new_array
	this->order_arr = new_arr;

	//increment your size of the array, num_order
	this->num_orders++;

    cout << endl << "Your order has been placed. Your order number is " << order.get_id() << "." << endl;
}

/*********************************************************************
** Function: update_order_file
** Description: matches file to array
** Parameters: ofstream
** Pre-Conditions: ofstream declared
** Post-Conditions: order file updated
*********************************************************************/ 

void Shop::update_order_file(ofstream& fo){

    fo.open("orders.txt");

    fo << this->num_orders << endl;

    /* 
     * loops through orders
     */
    
    for (int i = 0; i < this->num_orders; i++)
    {

        fo << i+1 << " " << this->order_arr[i].get_name() << " " << this->order_arr[i].get_coffee_size() << " " << this->order_arr[i].get_quantity() << endl;
    
    }

    fo.close();

}

/*********************************************************************
** Function: process_e
** Description: main process for employee
** Parameters: ofstream
** Pre-Conditions: ofstream declared
** Post-Conditions: process ends
*********************************************************************/ 

int Shop::process_e(ofstream& fo){

    while(true){

        cout << endl << "What would you like to do?" << endl;

        cout << "1. View shop revenue" << endl << "2. View orders" << endl << "3. Add an item to coffee menu" << endl << "4. Remove an item from coffee menu" << endl << "5. View coffee menu" << endl << "6. View address" << endl << "7. View phone" << endl << "8. Log out" << endl << "Selection: "; 
        
        int choice;

        cin >> choice;

        /* 
         * gets choice for action
         */

        if(choice == 1){

            cout << endl << "The shop revenue is: $" << this->revenue << endl;

        }

        if(choice == 2){

            for (int i = 0; i < this->num_orders; i++)
            {

                this->order_arr[i].print_order();

            }
        }

        if(choice == 3){

            this->m.add_to_menu();

            if(!this->m.update_menu_file(fo)){

                return 0;

            }

        }

        if(choice == 4){

            this->m.remove_from_menu();

            if(!this->m.update_menu_file(fo)){

                return 0;

            }

        }

        if(choice == 5){

            this->m.print_menu(); 

        }

        if(choice == 6){

            cout << endl << "The shop address is: " << this->address << endl;

        }

        if(choice == 7){

            cout << endl << "The shop phone is: " << this->phone << endl;

        }

        if(choice == 8){

            break;

        }

    }

    return 1;

}

/*********************************************************************
** Function: check_negative
** Description: checks if number is negative
** Parameters: int
** Pre-Conditions: int declared
** Post-Conditions: 0 or 1 returned
*********************************************************************/ 

int Shop::check_negative(int price){

    if(price <= 0){

        cout << endl << "Enter positive values." << endl << endl;

        return 1;

    }

    return 0;

}

/*********************************************************************
** Function: search_by_price
** Description: searches menu by budget
** Parameters: ofstream
** Pre-Conditions: ofstream declared
** Post-Conditions: search finishes
*********************************************************************/ 

void Shop::search_by_price(ofstream& fo){

    float budget;

    /* 
     *  loops until breaks
     */

    while(true){

        cout << endl << "Enter your budget for one drink, and I will list out our products that meet your requirement: ";

        cin >> budget;

        if(!this->check_negative(budget)){

            break;

        }

    }

    /* 
     *  makes new order
     */

    Order new_order1 = this->m.search_coffee_by_price(budget);

    if(new_order1.get_id() != -1){

        new_order1.set_id(this->num_orders+1);

        this->place_order(new_order1);

        this->update_order_file(fo);

        this->revenue += this->m.calculate_cost(new_order1.get_name(), new_order1.get_coffee_size(), new_order1.get_quantity());

    }
}

/*********************************************************************
** Function: search_by_name
** Description: searches menu by name
** Parameters: ofstream
** Pre-Conditions: ofstream declared
** Post-Conditions: search finishes
*********************************************************************/ 

void Shop::search_by_name(ofstream& fo){

    cout << "Enter the coffee name: ";

    string coffee_name;

    cin >> coffee_name;

    Order new_order2 = this->m.search_coffee_by_name(coffee_name);

    /* 
     * checks if order was valid
     */

    if(new_order2.get_id() != -1){

        new_order2.set_id(this->num_orders+1);

        this->place_order(new_order2);

        this->update_order_file(fo);
        
        this->revenue += this->m.calculate_cost(new_order2.get_name(), new_order2.get_coffee_size(), new_order2.get_quantity());

    }

    else{

        cout << endl << "Sorry, we don’t have that product at the moment." << endl;

    }
}

/*********************************************************************
** Function: get_order_for_order_option
** Description: gets order for an order from last search
** Parameters: string&, char&, int&
** Pre-Conditions: string&, char&, int& declared
** Post-Conditions: string&, char&, int& full
*********************************************************************/ 

void Shop::get_order_for_order_option(string& name, char& size, int& quantity){

    this->m.print_last_search();

    cout << "Select the number associated with the coffee you want to order: ";

    int selection;

    cin >> selection;

    /* 
     * loops through search
     */

    for (int t = 0; t < this->m.get_num_coffee_search(); t++)
    {

        if(selection == t+1){

            name = this->m.get_last_search()[t].get_name();

        }

    }

    cout << "Enter the size: s-small, m-medium, l-large: ";

    cin >> size;

    cout << "Enter quantity: ";

    cin >> quantity;

    cout << endl << "Your total cost is: $" << this->m.calculate_cost(name, size, quantity) << endl;

}

/*********************************************************************
** Function: confirm_order
** Description: confirms order
** Parameters: ofstream&, Order&, string&, char&, int&
** Pre-Conditions: ofstream declared
** Post-Conditions: order confirmed or denied
*********************************************************************/ 

void Shop::confirm_order(ofstream& fo, Order& new_order3, string& name, char& size, int& quantity){

    cout << "Confirmed? 1-yes, 0-no: ";

    int choice2;

    cin >> choice2;

    /* 
     * confirms choice
     */

    if(choice2 == 1){

        new_order3.set_coffee_name(name);

        new_order3.set_coffee_size(size);

        new_order3.set_quantity(quantity);

        new_order3.set_id(this->num_orders+1);

        this->place_order(new_order3);

        this->update_order_file(fo);

        this->revenue += this->m.calculate_cost(new_order3.get_name(), new_order3.get_coffee_size(), new_order3.get_quantity());

    }
}

/*********************************************************************
** Function: entire_menu_order
** Description: orders off whole menu
** Parameters: ofstream&, Order&
** Pre-Conditions: ofstream declared
** Post-Conditions: order finishes
*********************************************************************/ 

void Shop::entire_menu_order(ofstream& fo, Order& new_order3){

    this->m.print_menu();

    cout << "Select the number associated with the coffee you want to order: ";

    int selection;

    cin >> selection;

    string name;

    /* 
     * loops through coffee array
     */

    for (int l = 0; l < this->m.get_num_coffee(); l++)
    {

        if(selection == l+1){

            name = this->m.get_coffee_arr()[l].get_name();

        }

    }

    cout << "Enter the size: s-small, m-medium, l-large: ";

    char size;

    cin >> size;

    cout << "Enter quantity: ";

    int quantity;

    cin >> quantity;

    cout << endl << "Your total cost is: $" << this->m.calculate_cost(name, size, quantity) << endl;

    cout << "Confirmed? 1-yes, 0-no: ";

    int choice3;

    cin >> choice3;

    /* 
     * asks third choice
     */

    if(choice3 == 1){

        new_order3.set_coffee_name(name);

        new_order3.set_coffee_size(size);

        new_order3.set_quantity(quantity);

        new_order3.set_id(this->num_orders+1);

        this->place_order(new_order3);

        this->update_order_file(fo);

        this->revenue += this->m.calculate_cost(new_order3.get_name(), new_order3.get_coffee_size(), new_order3.get_quantity());

    }
}

/*********************************************************************
** Function: place_order_option
** Description: lets user select order type
** Parameters: ofstream&
** Pre-Conditions: ofstream declared
** Post-Conditions: order type chosen
*********************************************************************/ 

void Shop::place_order_option(ofstream& fo){

    Order new_order3;

    cout << endl << "Would you like to place an order based off of your last search (1) or the entire menu (2): ";

    int order_type;

    cin >> order_type;

    /* 
     * checks for order type
     */

    if(order_type == 1 && this->m.get_num_coffee_search() != 0){

        string name;

        char size;

        int quantity;

        get_order_for_order_option(name, size, quantity);

        confirm_order(fo, new_order3, name, size, quantity);

    }

    else if(order_type == 1){

        cout << endl << "You have not made a search yet." << endl;

    }

    else if(order_type == 2){

        this->entire_menu_order(fo, new_order3);

    }

}

/*********************************************************************
** Function: process_c
** Description: main process for customer
** Parameters: ofstream
** Pre-Conditions: ofstream declared
** Post-Conditions: process ends
*********************************************************************/ 

void Shop::process_c(ofstream& fo){

    /* 
     * loops until break
     */

    while(true){

        cout << endl << "Welcome, how can I help you?" << endl;

        cout << "1. View Coffee menu" << endl << "2. Search by price" << endl << "3. Search by coffee name" << endl << "4. Place an order" << endl << "5. View address" << endl << "6. View phone" << endl << "7. Log out" << endl << "Selection: "; 
        
        int choice;

        cin >> choice;

        /* 
         * action choice
         */

        if(choice == 1){

            this->m.print_menu(); 

        }

        if(choice == 2){

            this->search_by_price(fo);

        }

        if(choice == 3){

            this->search_by_name(fo);

        }

        if(choice == 4){

            this->place_order_option(fo);

        }

        if(choice == 5){

            cout << endl << "The shop address is: " << this->address << endl;

        }

        if(choice == 6){

            cout << endl << "The shop phone is: " << this->phone << endl;

        }

        if(choice == 7){

            break;

        }

    }
}

/*********************************************************************
** Function: ~Shop
** Description: destructor
** Parameters: none
** Pre-Conditions: object exists
** Post-Conditions: object destroyed
*********************************************************************/ 

//destructor
Shop::~Shop(){

	if (this->order_arr != NULL){

		delete [] this->order_arr;

		this->order_arr = NULL;

	}
}

/*********************************************************************
** Function: operator=
** Description: AOO
** Parameters: Shop&
** Pre-Conditions: object already declared
** Post-Conditions: object changed
*********************************************************************/ 

//AOO
//c3 = c4
Shop& Shop::operator=(const Shop& old_s){

	this->m = old_s.m;

    this->phone = old_s.phone;

    this->address = old_s.address;

    this->revenue = old_s.revenue;

    this->num_orders = old_s.num_orders;

	//free memory first
	if (this->order_arr != NULL){

		delete [] this->order_arr;

		this->order_arr = NULL;

	}
	//deep copy
	this->order_arr = new Order[this->num_orders];

	for (int i = 0; i < this->num_orders; i++)
	{

		this->order_arr[i] = old_s.order_arr[i];

	}
	
	//this->std_names = old_c.std_names; //not correct!!
	return *this;
}

/*********************************************************************
** Function: Shop
** Description: copy constructor
** Parameters: Shop&
** Pre-Conditions: object being declared on same line
** Post-Conditions: object initialized
*********************************************************************/ 

//copy constructor 
//Course c5 = c3;
Shop::Shop(const Shop& old_s){
    
	this->m = old_s.m;

    this->phone = old_s.phone;

    this->address = old_s.address;

    this->revenue = old_s.revenue;

    this->num_orders = old_s.num_orders;

	//deep copy
	this->order_arr = new Order[this->num_orders];

	for (int i = 0; i < this->num_orders; i++)
	{

		this->order_arr[i] = old_s.order_arr[i];

	}

}