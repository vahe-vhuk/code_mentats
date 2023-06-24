#include <iostream>
#include <string>
#include <regex>
#include <cstdlib>

using str = std::string;

bool check_phone(const str& phone)
{
	if (phone.size() != 12) {
		return false;
	}
	if (phone[0] != '+') {
		return false;
	}
	if (phone[1] == '0') {
		return false;
	}
	for (size_t i = 1; i < phone.size(); ++i) {
		if (phone[i] < '0' || phone[i] > '9') {
			return false;
		}
	}

	return true;
}

bool check_email(const str& email)
{
	const std::regex pattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");

	return std::regex_match(email, pattern);
}

bool check_name(const str& name)
{
	const std::regex pattern(R"([A-Za-z]+[A-Za-z]+)");

	return std::regex_match(name,pattern);
}

str add_command(const str& name, const str& phone, const str& email)
{
	str comm = "python pyson_cli.py DB.pyson " + name + " = " +
											"\"{'phone':'" + phone + "', " + 
											"'email':'" + email + "'}\"";
	return comm;
}

str search_command(const str& name)
{
	str comm = "python pyson_cli.py DB.pyson " + name + " srch";
	return comm;
}

str remove_command(const str& name)
{
	str comm = "python pyson_cli.py DB.pyson del " + name;
	return comm;
}

str display_command()
{
	str comm = "python pyson_cli.py DB.pyson";
	return comm;
}

void add_contact()
{
	str name;
	str phone;
	str email;

	std::cout << "Enter the data about contact (for exit enter 'break')" << std::endl;

	while (true) {
		std::cout << "Enter the name: ";
		std::cin >> name;
		if (name == "break") {
			return;
		}
		if (check_name(name)) {
			break;
		}
		std::cout << "Uncorrect format for name" << std::endl;
	}

	while (true) {
		std::cout << "Enter the phone number (+{12digit}): ";
		std::cin >> phone;
		if (phone == "break") {
			return;
		}
		if (check_phone(phone)) {
			break;
		}
		std::cout << "Uncorrect format for phone number" << std::endl;
	}

	while (true) {
		std::cout << "Enter the email: ";
		std::cin >> email;
		if (email == "break") {
			return;
		}
		if (check_email(email)) {
			break;
		}
		std::cout << "Uncorrect format for email" << std::endl;
	}

	system(add_command(name,  phone,  email).c_str());
}

void list_of_contacts()
{
	system(display_command().c_str());
}

void remove_contact()
{
	std::cout << "Enter the name of contact: " << std::endl;
	str name;
	std::cin >> name;

	system(remove_command(name).c_str());
}

void search_contact()
{
	std::cout << "Enter the name of contact: " << std::endl;
	str name;
	std::cin >> name;

	system(search_command(name).c_str());
}


void interface()
{
	std::cout << "ADDRESS BOOK\n"
	          << "Commands:\n"
	          << "1 - list of contacts\n"
	          << "2 - add or update the contact\n"
	          << "3 - delete contact\n"
	          << "4 - search the contact\n"
	          << "5 - exit" << std::endl;
}

void process()
{
	while (true) {
		std::cout << "Enter the number of the command:" << std::endl;
		
		char n;
		std::cin >> n;
		if (n < '1' || n > '5') {
			std::cout << "Uncorrect command" << std::endl;
			continue;
		}
		if (n == '5') {
			break;
		}
		switch (n) {
			case '1': {
				list_of_contacts();
				break;
			}
			case '2': {
				add_contact();
				break;
			}
			case '3': {
				remove_contact();
				break;
			}
			case '4': {
				search_contact();
				break;
			}
		}

	}	
}

int main()
{
	interface();
	process();

	return 0;
}



















