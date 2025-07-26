#include <iostream>

#include "email_template.h"


void if_event_generic_complete_then_pass() {
	std::string name = "Coffee Morning";
	std::string desc = "An event which takes place from 10am until 12pm in the hall.";
	event_generic* basic_event = new event_generic(name, desc); 


	if (basic_event->getName() != "Coffee Morning" || basic_event->getDesc() != "An event which takes place from 10am until 12pm in the hall.") {
		std::cout << "if_event_generic_complete_then_pass FAILED" << std::endl;
	}
	else {
		std::cout << "if_event_generic_complete_then_pass PASSED" << std::endl;
	}
	delete basic_event;
}

void if_event_special_complete_then_pass() {
	std::string name = "Games night";
	std::string desc = "An event which takes place from 6pm until 10pm in the boardroom.";
	std::string collaborators = "Games Society";
	event_special* basic_event = new event_special(name, desc, collaborators);


	if (basic_event->getName() != "Games night" || 
		basic_event->getDesc() != "An event which takes place from 6pm until 10pm in the boardroom."||
		basic_event->getCollaborators() != "Games Society") {
		std::cout << "if_event_special_complete_then_pass FAILED" << std::endl;
	}
	else {
		std::cout << "if_event_special_complete_then_pass PASSED" << std::endl;
	}
}


void if_email_reader_correct_then_pass_event_generic() {

}


int main() {
	if_event_generic_complete_then_pass();
	if_event_special_complete_then_pass();
	return 0;
}