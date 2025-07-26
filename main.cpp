#include <iostream>
#include <string>
#include "email_template.h"

/*
* Function for creating results for a generic event
* @param email_reader* email_maker 
* @result N\A
*/
void result_creator_generic(email_reader* email_maker) {
	std::string name = "";
	std::string desc = "";
	std::cout << "\nPlease input the name of the event here: ";
	std::getline(std::cin, name);
	std::cout << "\nPlease input the description of the event here: ";
	std::getline(std::cin, desc);

	event_generic* event = new event_generic(name, desc);
	email_maker->format(event);
}


/*
* Function for creating results for special event
* @param email_reader* email_maker
* @result N\A
*/
void result_creator_special(email_reader* email_maker) {
	std::string name = "";
	std::string desc = "";
	std::string collaborators = "";

	std::cout << "\nPlease input the name of the event here: ";
	std::getline(std::cin, name);
	std::cout << "\nPlease input the description of the event here: ";
	std::getline(std::cin, desc);
	std::cout << "\nPlease input the collaborators of the event here: ";
	std::cin.clear();
	std::getline(std::cin, collaborators);

	event_special* event = new event_special(name, desc, collaborators);
	email_maker->format(event);
}

int main() {

	email_reader* email_maker = new email_reader();
	char userInput = '0';
	std::cout << "Welcome to the email creator programme. What type of event would you like to create?\n1:generic event\n2:special event\n3:Review email\n9:Quit" << std::endl;


	while (userInput != '9') {
		std::cin >> userInput;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		switch (userInput) {
		case '1':
			result_creator_generic(email_maker);
			break;
		case '2':
			result_creator_special(email_maker);
			break;
		case '3':
			std::cout << email_maker->getResult() << std::endl;
			break;
		case'9':
			break;
		default:
			std::cout << "Please choose a valid option.";
			break;
		}
		std::cin.clear();
		std::cout << "\nYour options are as follows:\n1:generic event\n2:special event\n3:Review email\n9:Quit\n";
		
	}


	return 0;
}