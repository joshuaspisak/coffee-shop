# Coffee Shop Management System

## Description

The Coffee Shop Management System is a program that allows employees and customers to manage coffee shop operations. It provides functionalities for adding and removing items from the menu, placing orders, displaying shop information, and more.

## Features

- File I/O: The program reads and writes information to multiple files, including menu.txt, order.txt, and shop_info.txt. Changes made to the menu and orders are reflected consistently in both the program and the files.
- Use of Big Three: The program correctly implements the Big Three (copy constructor, assignment operator, destructor) for the Menu and Shop classes, ensuring proper memory management. The const qualifier is appropriately used for the Menu class.
- Accessors and Mutators: The program uses accessors and mutators (getter and setter functions) for private variables in the Shop, Order, Menu, and Coffee classes. The const qualifier is utilized when appropriate.
- Required Classes: The program includes the following struct and classes exactly as specified: Shop, Order, Menu, and Coffee.
- Employee Functionalities: Employees can calculate and display the shop revenue, store order information, display the coffee menu, add new items to the menu, remove items from the menu, and display the shop address and phone number.
- Customer Functionalities: Customers can display the coffee menu, search the menu by price or coffee name, place orders from the entire menu or based on search results, and display the shop address and phone number.
- Other Functionalities: The program gracefully terminates if any files fail to open, re-prompts for invalid inputs until valid ones are provided, prompts for the user's identity as an employee or customer, and allows for logging out as an employee or customer.
- File Separation and Makefile: The program uses separate .h and .cpp files for each class and includes a driver file. It also provides a working makefile for easy compilation and building.

## Usage

1. Run the program.
2. Choose your identity as an employee or customer.
3. Follow the on-screen instructions to navigate through the available functionalities.
4. Make changes to the menu or place orders as needed.
5. Exit the program when finished.

## Installation

1. Clone the repository or download the source code files.
2. Ensure that you have a C++ compiler installed on your system.
3. Open a terminal or command prompt and navigate to the project directory.
4. Compile the program using the provided makefile.
5. Run the compiled executable.

## Dependencies

- C++ compiler (e.g., g++)
- make (build tool)

## File Structure

- `Makefile`: Build automation file.
- `main.cpp`: Main driver file.
- `shop.h`: Header file containing the Shop class declaration.
- `shop.cpp`: Implementation file for the Shop class.
- `order.h`: Header file containing the Order class declaration.
- `order.cpp`: Implementation file for the Order class.
- `menu.h`: Header file containing the Menu class declaration.
- `menu.cpp`: Implementation file for the Menu class.
- `coffee.h`: Header file containing the Coffee class declaration.
- `coffee.cpp`: Implementation file for the Coffee class.
