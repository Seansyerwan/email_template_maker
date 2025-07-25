#include <iostream>

#include "email_template.h"


void if_event_generic_complete_then_pass() {
	std::string name = "Coffee Morning";
	std::string desc = "An event which takes place from 10am until 12pm in the hall.";
	event_generic* basic_event = new event_generic(name, desc); 

	std::cout << "basic_event name = " + basic_event->getName() << std::endl;

	if (basic_event->getName() != "Coffee Morning" || basic_event->getDesc() != "An event which takes place from 10am until 12pm in the hall.") {
		std::cout << "if_event_generic_complete_then_pass FAILED" << std::endl;
	}
	else {
		std::cout << "if_event_generic_complete_then_pass PASSED" << std::endl;
	}
	delete basic_event;
}

int main() {
	if_event_generic_complete_then_pass();
	return 0;
}