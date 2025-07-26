#include <iostream>
#include <vector>
#include <string>
#include "email_template.h"



event_generic::event_generic() {};

/*
* Constructor for creation of generic events
* @param name and description of event
* @return generic event
*/
event_generic::event_generic(std::string name, std::string desc) {
	//this->setPriority(priority);
	this->setName(name);
	this->setDesc(desc);
}


/*
* Setter for name variable
* @param string pointer for name of event
* @return N\A
*/
void event_generic::setName(std::string name) {
	this->name = name;
}

/*
* Setter for description Variable
* @param string pointer for description of event
* @return N\A
*/
void event_generic::setDesc(std::string desc) {
	this->desc = desc;
}


/*
* Getter for Name variable
* @param N\A
* @return Name of event
*/
std::string event_generic::getName() {
	return (this->name);
}


/*
* Getter for Desc variable
* @param N\A
* @return Description of event
*/
std::string event_generic::getDesc() {
	return (this->desc);
}

/*
* Destructor for event
* @param N\A
* @return message signifying deletion of object
*/
event_generic::~event_generic() {
	//delete this->priority;
	//std::cout << "Generic event deleted" << std::endl;
}


/*
* Constructor for special events
* @param std::string* name, std::string* desc, std::string* collaborators
* @return special event object
*/
event_special::event_special(std::string name, std::string desc, std::string collaborators) {
	this->setName(name);
	this->setDesc(desc);
	this->setCollaborators(collaborators);
}

/*
* Setter method for collaborators string
* @param String to replace data for.
* @return N\A
*/
void event_special::setCollaborators(std::string collaborators) {
	this->collaborators = collaborators;
}


/*
* Getter method for getting details of collaborators.
* @param N\A
* @return collaborators string
*/
std::string event_special::getCollaborators() {
	return (this->collaborators);
}

event_special::~event_special() {
	//std::cout << "Deleted special event details" << std::endl;
}

/*
* Constructor for email reader
* @param N\A
* @return email_reader class
*/
email_reader::email_reader() {}

/*
* Format method for generic event
* @param event_generic pointer
* @return Formatted version of both name and description of event.
*/
void email_reader::format(event_generic* event) {
	std::string result = "";
	result += "<h3>" + (event->getName()) + "</h3>\n\n";
	result += "<p>" + (event->getDesc()) + "</p>\n";
	this->result.push_back(result);
}


/*
* Format method for generic event
* @param event_special pointer
* @return N\A
*/
void email_reader::format(event_special* event) {
	std::string result = "";
	result += "<h3>" + (event->getName()) + "</h3>\n\n";
	result += "<h4>In collaboration with " + (event->getCollaborators()) + "</h4>\n";
	result += "<p>" + (event->getDesc()) + "</p>\n";
	this->result.push_back(result);
	
}


/*
* Getter method for formatted text
* @param N\A
* @return Formatted data from previous emails
*/
std::vector<std::string> email_reader::getResult() {
	return this->result;
}

/*
* Method for updating a specific part of result for generic event
* @param unsigned int index
* @return Modified 

void email_reader::modify_result(unsigned int index) {
	if (this->result.size() < index){
		std::cout << "Invalid input: out of range";
		return;
	}
	std::string res = "";
	char choice = ' ';
	std::cout << "What do you wish to modify for index " + index << " ?\n1:name\n2:desc\n3:neither\n" << std::endl;
	std::cin >> choice;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	//if the choice is one or two
	if (choice == '1' || choice == '2') {
		std::string splitter = "</h3>";

		std::cout << "Please input your replacement for your choice:";
		std::getline(std::cin, res);

		//we either insert the replacement before or after the header ending.
		std::string temp = choice == '1' ? "<h3>" + res +
			this->result[index].substr(this->result[index].find(splitter)) : "</h3>" +
			this->result[index].substr(0, this->result[index].find(splitter)) + "<p>" + res + "</p>";
		
		this->result[index] = temp;
	}
}*/


/*
* Method for updating a specific part of result for special event
* @param unsigned int index
* @return Modified
*/
void email_reader::modify_result(unsigned int index) {
	if (this->result.size()-1 < index) {
		std::cout << "Invalid input: out of range";
		return;
	}
	std::string res = "";
	char choice = ' ';
	std::cout << "What do you wish to modify for index " + index << " ?\n1:name\n2:desc\n3:collaborators\n4:None of the above\n" << std::endl;
	std::cin >> choice;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	//if the choice is one, two or three
	if (choice == '1' || choice == '2' || choice == '3') {

		//should a user try to modify collaborators when not present, it is then ignored.
		if (choice == '3') { 
			int present = this->result[index].find("<h4>");
			if (present == -1) {
				std::cout << "No collaborators! Try again." << std::endl;
				return;
			}
		}


		std::cout << "Please input your replacement for your choice:";
		std::getline(std::cin, res);

		//we either insert the replacement in the name, the description or the collaborators section. 
		std::string temp = choice == '1' ? "<h3>" + res +
			this->result[index].substr(this->result[index].find("</h3>")) : choice == '2' ? "</h3>" +
			this->result[index].substr(0, this->result[index].find("</h3>")) + "<p>" + res + "</p>" :
		  this->result[index].substr(0, this->result[index].find("<h4>")) + "<h4>In collaboration with " + res + this->result[index].substr(this->result[index].find("</h4>"));

		this->result[index] = temp;
	}
}



/*
* Destructor for email reader object.
* @param N\A
* @return N\A
*/
email_reader::~email_reader() {
	//std::cout << "email_reader deleted" << std::endl;
}