#include <iostream>
#include "email_template.h"


/*
* Constructor for creation of generic events
* @param name and description of event
* @return generic event
*/
event_generic::event_generic(std::string* name, std::string* desc) {
	//this->setPriority(priority);
	this->setName(name);
	this->setDesc(desc);
}


/*
* Setter for name variable
* @param string pointer for name of event
* @return N\A
*/
void event_generic::setName(std::string* name) {
	this->name = name;
}

/*
* Setter for description Variable
* @param string pointer for description of event
* @return N\A
*/
void event_generic::setDesc(std::string* desc) {
	this->desc = desc;
}


/*
* Getter for Name variable
* @param N\A
* @return Name of event
*/
std::string event_generic::getName() {
	return *(this->name);
}


/*
* Getter for Desc variable
* @param N\A
* @return Description of event
*/
std::string event_generic::getDesc() {
	return *(this->desc);
}

/*
* Destructor for event
* @param N\A
* @return message signifying deletion of object
*/
event_generic::~event_generic() {
	//delete this->priority;
	delete this->name;
	delete this->desc;
	std::cout << "Generic event deleted" << std::endl;
}


/*
* Constructor for special events
* @param std::string* name, std::string* desc, std::string* collaborators
* @return special event object
*/
event_special::event_special(std::string* name, std::string* desc, std::string* collaborators) {
	this->setName(name);
	this->setDesc(desc);
	this->setCollaborators(collaborators);
}

void event_special::setCollaborators(std::string* collaborators) {
	this->collaborators = collaborators;
}

std::string event_special::getCollaborators() {
	return *(this->collaborators);
}

event_special::~event_special() {
	delete this->collaborators;
	std::cout << "Deleted special event details" << std::endl;
}

/*
* Constructor for email reader
* @param N\A
* @return email_reader class
*/
email_reader::email_reader() {
	this->result = new std::string();
}


void email_reader::format(event_generic* event) {
	*(this->result) += "<h3>" + (event->getName()) + "</h3>";
	*(this->result) += "<p>" + (event->getDesc()) + "</p>";
}

void email_reader::format(event_special* event) {
	*(this->result) += "<h3>" + (event->getName()) + "</h3>";
	*(this->result) += "<p>" + (event->getDesc()) + "</p>";
}

email_reader::~email_reader() {
	delete this->result;
	std::cout << "email_reader deleted" << std::endl;
}