#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "email_template.h"


/*
* Constructor method for event_generic
* @param N\A
* @return generic event
*/
event_generic::event_generic() {};

/*
* Constructor for creation of generic events
* @param name and description of event
* @return generic event
*/
event_generic::event_generic(std::string name, std::string desc, std::string time, std::string location) {
	//this->setPriority(priority);
	this->setName(name);
	this->setDesc(desc);
	this->setTime(time);
	this->setLocation(location);
}


/*
* Setter for name variable
* @param string pointer for name of event
* @return Updated name of event
*/
void event_generic::setName(std::string name) {
	this->name = name;
}

/*
* Setter for description Variable
* @param string pointer for description of event
* @return Updated description of event
*/
void event_generic::setDesc(std::string desc) {
	this->desc = desc;
}


/*
* Setter for Time Variable
* @param string referring to time of event
* @return Updated time variable of event
*/
void event_generic::setTime(std::string time) {
	this->time = time;
}


/*
* Setter for Location Variable
* @param string referring to location of event
* @return Updated location variable of event
*/
void event_generic::setLocation(std::string location) {
	this->location = "Taking place in " + location;
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
* Getter for Time variable
* @param N\A
* @return Time of event
*/
std::string event_generic::getTime() {
	return (this->time);
}

/*
* Getter for Location variable
* @param N\A
* @return Location of event
*/
std::string event_generic::getLocation() {
	return (this->location);
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
event_special::event_special(std::string name, std::string desc, std::string time, std::string location, std::string collaborators) {
	this->setName(name);
	this->setDesc(desc);
	this->setTime(time);
	this->setLocation(location);
	this->setCollaborators(collaborators);
}

/*
* Setter method for collaborators string
* @param String to replace data for.
* @return updated collaborators for event
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
	result += "<p>" + (event->getDesc()) + "</p> <p>This event is taking place at <mark>" + (event->getTime()) + "</mark><b>" + (event->getLocation()) + "</b></p>\n\n";
	result += "<hr>";
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
	result += "<p>" + (event->getDesc()) + "</p> <p>This event is taking place at <mark>" + (event->getTime()) + "</mark><b>" + (event->getLocation()) + "</b></p>\n\n";
	result += "<hr>";
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



/*Function for creating results for a generic event
* @param email_reader* email_maker
* @result N\A
*/
void email_reader::result_creator_generic() {
	std::string name = "";
	std::string desc = "";
	std::string time = "";
	std::string location = "";

	std::cout << "\nPlease input the name of the event here: ";
	std::getline(std::cin, name);
	std::cout << "\nPlease input the description of the event here: ";
	std::getline(std::cin, desc);

	std::cout << "\What day is this event taking place next week?: ";
	std::getline(std::cin, time);

	std::cout << "\Where is this event taking place?: ";
	std::getline(std::cin, location);
	//create a new event, then format	
	event_generic* event = new event_generic(name, desc, time, location);
	this->format(event);
}

/*
* Function for creating results for special event
* @param email_reader* email_maker
* @result N\A
*/
void email_reader::result_creator_special() {
	std::string name = "";
	std::string desc = "";
	std::string time = "";
	std::string location = "";
	std::string collaborators = "";

	std::cout << "\nPlease input the name of the event here: ";
	std::getline(std::cin, name);
	std::cout << "\nPlease input the description of the event here: ";
	std::getline(std::cin, desc);
	std::cout << "\nPlease input the collaborators of the event here: ";
	std::getline(std::cin, collaborators);

	std::cout << "\What day is this event taking place next week?: ";
	std::getline(std::cin, time);

	std::cout << "\Where is this event taking place?: ";
	std::getline(std::cin, location);

	std::cin.clear();

	//create a new event, then format
	event_special* event = new event_special(name, desc, time, location, collaborators);
	this->format(event);
}

/*
* Method for updating a specific part of result for special event
* @param N\A
* @return Modified version of results
*/
void email_reader::modify_result() {
	unsigned int overall_index = 0; //placeholder value

	std::cout << "What event would you like to modify?" << std::endl;

	//loop through the results
	unsigned int currentPage = 0;
		while (true) {
			std::cout << "Which page do you wish to choose" << std::endl;
			for (int i = 0; i < (this->result.size() / 10)+1; i++) {
				std::cout << "Page " + std::to_string(i+1) << std::endl;
			}

			
			unsigned int index = 0;//choice for the page
			std::cin >> index; 

			index -= 1;
			if (index <= (this->result.size() - 1)) {
				currentPage = index;

				std::cout << "Page " + std::to_string(currentPage + 1) + " selected." << std::endl;
				for (int i = currentPage*10; i < currentPage+10 && i < this->result.size(); i++) {
					std::cout << std::to_string((i % 10)+1) + this->result[i].substr(this->result[i].find("<h3>"), this->result[i].find("</h3>")) << std::endl;
				}
				std::cout << "Which event do you wish to edit?" << std::endl;
				std::cin >> index;

				std::cout << index << std::endl;

				index -= 1; //decrement to keep it within range
				if (index < 10 && index < this->result.size()) {
					overall_index = index; //swap value
					
					break;
				}

			}
			std::cout << "Invalid input chosen, please try again" << std::endl;
		}

	
	//print choice out for the user
	std::cout << "You have selected " << overall_index << std::endl;
	std::cout << this->result[overall_index] <<std::endl;

	char choice = ' ';
	//user knows what they chose, so if it was a mistake, they can choose 4.
	std::cout << "What do you wish to modify for index " + overall_index << " ?\n1:name\n2:desc\n3:time\n4:location\n5:collaborators\nOther inputs:None of the above\n" << std::endl;
	std::cin >> choice; 
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	//if the choice is one, two or three
	if (choice == '1' || choice == '2' || choice == '3' || choice == '4' || choice == '5') {

		//should a user try to modify collaborators when not present, it is then ignored.
		if (choice == '5') { 
			int present = this->result[overall_index].find("<h4>");
			if (present == -1) {
				std::cout << "No collaborators! Try again." << std::endl;
				return;
			}
		}

		std::string res = "";
		std::cout << "Please input your replacement for your choice:";
		std::getline(std::cin, res);
		
		std::string temp = "";
		

		//	result += "<p>" + (event->getDesc()) + "</p> <p>This event is taking place at <mark>" + (event->getTime()) + "</mark><b>" + (event->getLocation()) + "</b></p>\n\n";

		//if else statement for what the user chose. 1 == name, 2 == desc, 3 == time, 4 == desc, 5 == collaborators.
		if (choice == '1') {
			temp = "<h3>" + res + this->result[overall_index].substr(this->result[overall_index].find("</h3>"));
		}
		else if (choice == '2') {
			temp = "</h3>" + this->result[overall_index].substr(0, this->result[overall_index].find("</h3>")) + "<p>" + res + "</p>";
		}
		else if (choice == '3') {
			temp = this->result[overall_index].substr(0, this->result[overall_index].find("<mark>")) + +"<mark>" + res + "" + this->result[overall_index].substr(this->result[overall_index].find("</mark>"));
		}
		else if (choice == '4') {
			temp = this->result[overall_index].substr(0, this->result[overall_index].find("<b>")) + res + this->result[overall_index].substr(this->result[overall_index].find("</b>"));
		} 
		else if (choice == '5') {
			temp = this->result[overall_index].substr(0, this->result[overall_index].find("<h4>")) + "<h4>In collaboration with " + res + this->result[overall_index].substr(this->result[overall_index].find("</h4>"));
		}

		this->result[overall_index] = temp;
	}
	else std::cout << "No valid input chosen, result remaining unmodified." << std::endl;
}


/*
* Method for the purpose of deleting an event
* @param N\A
* @return email with a part of the email removed.
*/
void email_reader::delete_event() {
	unsigned int overall_index = 0; //placeholder value

	std::cout << "What event would you like to modify?" << std::endl;

	//loop through the results
	unsigned int currentPage = 0;
	while (true) {
		std::cout << "Which page do you wish to choose" << std::endl;
		for (int i = 0; i < (this->result.size() / 10) + 1; i++) {
			std::cout << "Page " + std::to_string(i + 1) << std::endl;
		}


		unsigned int index = 0;//choice for the page
		std::cin >> index;

		index -= 1;
		if (index <= (this->result.size() - 1)) {
			currentPage = index;

			std::cout << "Page " + std::to_string(currentPage + 1) + " selected." << std::endl;
			for (int i = currentPage * 10; i < currentPage + 10 && i < this->result.size(); i++) {
				std::cout << std::to_string((i % 10) + 1) + this->result[i].substr(this->result[i].find("<h3>"), this->result[i].find("</h3>")) << std::endl;
			}
			std::cout << "Which event do you wish to edit?" << std::endl;
			std::cin >> index;

			std::cout << index << std::endl;

			index -= 1; //decrement to keep it within range
			if (index < 10 && index < this->result.size()) {
				overall_index = index; //swap value

				break;
			}

		}
		std::cout << "Invalid input chosen, please try again" << std::endl;
	}


	//print choice out for the user
	std::cout << "You have selected " << overall_index << std::endl;
	std::cout << this->result[overall_index] << std::endl;

	char choice = ' ';
	//user knows what they chose, so if it was a mistake, they can choose 4.
	std::cout << "Are you sure to delete event " + overall_index << " ?\nY/N:";
	std::cin >> choice;

	if (choice == 'Y' || choice == 'y') {
		this->result.erase(this->result.begin() + overall_index, this->result.begin() + overall_index + 1);
	}

	std::cout << "Event " + std::to_string(overall_index) + " deleted." << std::endl;

}

/*
* Method for saving event to external file
* @param email_reader object with data inserted
* @return N\A
*/
void email_reader::save_email() {
	if (this->result.size() == 0) {
		std::cout << "Nothing to save. Please try again later." << std::endl;
		return;
	}

	std::ofstream email_data("event_data.txt");

	//for each event in the result vector, write to the file
	for (std::string line : this->result) {
		email_data << line;
	}

	//close when done
	email_data.close();
	
}

/*
* Method for retrieving event data from external file
* @param email_reader object with data inserted
* @return N\A
*/
void email_reader::retrieve_email() {
	std::string output_data;
	std::ifstream iFile("event_data.txt");

	//for each line in the file, open.
	while (std::getline(iFile, output_data)) {
		this->result.push_back(output_data);
		std::cout << output_data;
	}
	
	iFile.close();
}

/*
* Destructor for email reader object.
* @param N\A
* @return N\A
*/
email_reader::~email_reader() {
	//std::cout << "email_reader deleted" << std::endl;
}