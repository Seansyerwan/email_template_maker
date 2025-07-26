#include <iostream>

#include "email_template.h"


void if_event_generic_complete_then_pass() {
	std::string name = "Coffee Morning";
	std::string desc = "An event which takes place from 10am until 12pm in the hall.";
	event_generic* basic_event = new event_generic(name, desc); 

	//compare the outputs of the getters compared to what was inserted.
	if (basic_event->getName() != "Coffee Morning" || basic_event->getDesc() != "An event which takes place from 10am until 12pm in the hall.") {
		std::cout << "if_event_generic_complete_then_pass FAILED" << std::endl;
	}
	else {
		std::cout << "if_event_generic_complete_then_pass PASSED" << std::endl;
	}
	delete basic_event;
}

/*
* Test to see status of event_special functionality
* @param N\A
* @result passes if output is to be expected.
*/
void if_event_special_complete_then_pass() {
	std::string name = "Games night";
	std::string desc = "An event which takes place from 6pm until 10pm in the boardroom.";
	std::string collaborators = "Games Society";
	event_special* basic_event = new event_special(name, desc, collaborators);

	//compare the outputs of the getters compared to what was inserted.
	if (basic_event->getName() != "Games night" || 
		basic_event->getDesc() != "An event which takes place from 6pm until 10pm in the boardroom."||
		basic_event->getCollaborators() != "Games Society") {
		std::cout << "if_event_special_complete_then_pass FAILED" << std::endl;
	}
	else {
		std::cout << "if_event_special_complete_then_pass PASSED" << std::endl;
	}
	delete basic_event;
}


void if_email_reader_correct_then_pass_event_generic() {
	std::string name = "Coffee Morning";
	std::string desc = "An event which takes place from 10am until 12pm in the hall.";
	event_generic* basic_event = new event_generic(name, desc);

	email_reader* email_reader_tool = new email_reader();

	email_reader_tool->format(basic_event);

	std::cout << email_reader_tool->getResult() << std::endl;

	if (email_reader_tool->getResult() != "<h3>" + name + "</h3>\n\n" + "<p>" + desc + "</p>\n") {
		std::cout << "if_email_reader_correct_then_pass_event_generic FAILED" << std::endl;
	}
	else {
		std::cout << "if_email_reader_correct_then_pass_event_generic PASSED" << std::endl;
	}
	delete email_reader_tool;
	delete basic_event;
}


void if_email_reader_correct_then_pass_event_special() {
	std::string name = "Games night";
	std::string desc = "An event which takes place from 6pm until 10pm in the boardroom.";
	std::string collaborators = "Games Society";
	event_special* basic_event = new event_special(name, desc, collaborators);

	email_reader* email_reader_tool = new email_reader();

	email_reader_tool->format(basic_event);

	std::cout << email_reader_tool->getResult() << std::endl;

	if (email_reader_tool->getResult() != "<h3>" + name + "</h3>\n\n" + "<h4> In collaboration with " + collaborators + "</h4>\n" + "<p>" + desc + "</p>\n") {
		std::cout << "if_email_reader_correct_then_pass_event_special FAILED" << std::endl;
	}
	else {
		std::cout << "if_email_reader_correct_then_pass_event_special PASSED" << std::endl;
	}
	delete email_reader_tool;
	delete basic_event;
}



int main() {
	if_event_generic_complete_then_pass();
	if_event_special_complete_then_pass();

	if_email_reader_correct_then_pass_event_generic();
	if_email_reader_correct_then_pass_event_special();
	return 0;
}