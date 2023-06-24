# Address Book
Description
The Address Book program is a command-line tool written in C++ that allows users to manage a list of contacts. The program provides various functionalities such as listing all contacts, adding or updating contacts, deleting contacts, searching for specific contacts, and exiting the program. The contact information is stored in a file named "DB.pyson", and the program interacts with this file using system calls to execute Python command line interfaces for pyson_parser.py and pyson_cli.py.

## Compilation and Execution

To compile the program, follow these steps:

g++ main.cpp -o main

To run the program, use the following command:

./main

## Instructions
### 1) List of Contacts

When you select this option by entering "1", the program will display a list of all contacts stored in the "DB.pyson" file.

### 2) Add or Update Contact

To add or update a contact, select option "2".
The program will prompt you to input the contact's name, phone number, and email.
Each input will be validated by the program, and if the information is incorrect, you will be asked to input it again.
If a contact with the same name already exists in the "DB.pyson" file, the program will update the contact with the new phone number and email.
If the contact does not exist, it will be added to the address book.

### 3) Delete Contact

To delete a contact, choose option "3".
The program will ask you to enter the name of the contact you wish to delete.
If the contact exists in the "DB.pyson" file, it will be deleted.

### 4) Search Contact

If you want to search for a specific contact, select option "4".
The program will prompt you to input the name of the contact you want to search for.
If the contact exists in the "DB.pyson" file, the program will display its phone number and email.

### 5) Exit

To exit the program, select option "5".
This will terminate the program and return you to the command line.
Note: All contact information is saved in the "DB.pyson" file, which is accessed and manipulated through system calls that execute the Python command line interfaces for pyson_parser.py and pyson_cli.py.
