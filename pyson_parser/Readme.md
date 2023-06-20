
#Pyson Parser

Pyson Parser is a Python program that allows you to parse and manipulate JSON-like files with the extension ".pyson". This program provides a 
simple command-line interface for interacting with the JSON-like data. You can retrieve values, update existing keys or create new ones, 
delete keys and their values, and save changes to the file.

#Usage
To run the Pyson Parser, follow these steps:

Make sure you have Python 3 installed on your system.

Clone or download the Pyson Parser repository to your local machine.

Open a terminal or command prompt and navigate to the project directory.

Run the main file using the following command:

"""python main.py
The program will prompt you to enter the name of the ".pyson" file you want to parse. If the file doesn't exist, 
it will be created automatically. Please provide the file name with the ".pyson" extension.

Once the file is loaded or created, you can start entering commands.

#Commands

The Pyson Parser supports the following commands:

"""Print a value: 
To print the value of a key, enter the key's path using dot notation. For example:

key1.key2.keyN

The program will search for the key and display its value if found.

"""Update or create a key-value pair: 
To update the value of an existing key or create a new key-value pair, 
enter the key's path using dot notation, followed by an equals sign (=), 
and the new value. For example:

key1.key2.keyN = value

If key1, key2, ..., keyN-1 are already present, and they are all dictionaries, 
the program will update the value of keyN. If any of the intermediate keys 
are missing or not a dictionary, the command will not work.

"""Delete a key and its value: 
To delete a key and its corresponding value, enter the key's path using 
dot notation, preceded by the "del" keyword. For example:

del key1.key2.keyN
If the key exists and is a dictionary, it will be deleted along with its value.

"""Exit the program: 
To save any changes made to the JSON-like file and exit the program, enter the command:

exit

The program will write the modified data back to the original ".pyson" file and terminate.

File Structure
The Pyson Parser expects the ".pyson" file to contain nested dictionaries, strings, and integer values.
It does not support complex data types such as arrays, nested arrays, or nested objects. The structure 
should resemble a simplified JSON format.

Here's an example of a valid ".pyson" file:

{
  "key1": {
    "key2": {
      "key3": "value",
      "key4": 42
    },
    "key5": {
      "key6": "another value"
    }
  }
}

#Notes

"The Pyson Parser assumes that the JSON file is valid and follows the correct syntax.
If the file contains syntax errors, the program may not work as expected.
"Make sure to backup your ".pyson" file before using the Pyson Parser, as it will modify
the file directly.
