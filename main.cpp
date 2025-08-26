#include <iostream>
#include <string>
#include "email_template.h"






int main() {

	email_reader* email_maker = new email_reader();
	char userInput = '0';
	std::cout << "Welcome to the email creator programme. What type of event would you like to create?\n1:generic event\n2:special event\n3:Review email\n4:Modify Email\n5:Delete Event\n6:Save Email\n7:Retrieve Email\n8:Shift Event\n9:Quit" << std::endl;

	
	while (userInput != '9') {
		std::cin >> userInput;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		switch (userInput) {
		case '1':
			email_maker->result_creator_generic();
			break;
		case '2':
			email_maker->result_creator_special();
			break;
		case '3':
			for (std::string events : email_maker->getResult()) std::cout << events << std::endl;
			break;
		case '4':
			email_maker->modify_result();
			break;
		case '5':
			email_maker->delete_event();
			break;
		case '6':
			email_maker->save_email();
			break;
		case '7':
			email_maker->retrieve_email();
			break;
		case '8':
			email_maker->shift_event();
			break;
		case'9':
			return 0;
		default:
			std::cout << "Please choose a valid option.";
			break;
		}
		std::cout << "\nYour options are as follows:\n1:generic event\n2:special event\n3:Review email\n4:Modify Email\n5:Delete Event\n6:Save Email\n7:Retrieve Email\n8:Shift Event\n9:Quit" << std::endl;

	}



	return 0;
}