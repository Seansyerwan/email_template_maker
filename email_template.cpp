#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include "email_template.h"
#include <regex>


const std::string days[] = {
		"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
};

std::string day_of_week(std::string date, bool is_recurring) {

	//we will use smatch to match the data here
	std::smatch date_match;
	std::regex_search(date, date_match, std::regex(R"((\d{1,2})\/(\d{1,2})\/(\d{4}))"));

	unsigned int dd = std::stoul(date_match[1]), mm = std::stoul(date_match[2]);
	int yy = std::stoul(date_match[3]);
	//goal of this is to get the next iteration of a date.	
	std::chrono::year_month_day ymd{std::chrono::year{yy}, std::chrono::month{mm}, std::chrono::day{dd}};

	//get the date for next week by adding 7 days to the date above. if it is a recurring event, then we just add 7 days on. 
	std::chrono::sys_days next_iteration = is_recurring ? std::chrono::sys_days{ymd} + std::chrono::days{7} : std::chrono::sys_days{ymd};

	//the specific date....
	std::chrono::year_month_day next_date{ next_iteration };
	//get the specific day (from 0-6)
	std::chrono::weekday wd{next_iteration};

	return days[wd.c_encoding()] + " " + std::to_string(unsigned(next_date.day())) + "/" + std::to_string(unsigned(next_date.month())) + "/" + std::to_string(int(next_date.year()));
	
}

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
event_generic::event_generic(std::string name, std::string desc, std::string date, std::string duration, std::string location) {
	this->setName(name);
	this->setDesc(desc);
	this->setDate(date);
	this->setDuration(duration);
	this->setLocation(location);
}


/*
* Setter for name variable
* @param string for name of event
* @return Updated name of event
*/
void event_generic::setName(std::string name) {
	this->name = name;
}

/*
* Setter for description Variable
* @param string for description of event
* @return Updated description of event
*/
void event_generic::setDesc(std::string desc) {
	this->desc = desc;
}


/*
* Setter for Date Variable
* @param string referring to date of event
* @return Updated date variable of event
*/
void event_generic::setDate(std::string date) {
	this->date = day_of_week(date, false);
}

/*
* Setter for Duration Variable
* @param string refferring to duration of event
* @return updated duration variable of event
*/
void event_generic::setDuration(std::string duration) {
	this->duration = duration;
}

/*
* Setter for Location Variable
* @param string referring to location of event
* @return Updated location variable of event
*/
void event_generic::setLocation(std::string location) {
	this->location = location;
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
* Getter for Date variable
* @param N\A
* @return Date of event
*/
std::string event_generic::getDate() {
	return (this->date);
}

/*
* Getter for duration variable
* @param N\A
* @return Duration of event
*/
std::string event_generic::getDuration() {
	return (this->duration);
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
event_special::event_special(std::string name, std::string desc, std::string date, std::string location, std::string collaborators) {
	this->setName(name);
	this->setDesc(desc);
	this->setDate(date);
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
	result += "<p>" + (event->getDesc()) + "</p> <p>This event is taking place from <strong>" + (event->getDuration()) + "</strong> at <mark>" + (event->getDate()) + "</mark> <b>Located in " + (event->getLocation()) + "</b></p>\n\n";
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
	result += "<p>" + (event->getDesc()) + "</p> <p>This event is taking place from <strong>" + (event->getDuration()) + "</strong> at <mark>" + (event->getDate()) + "</mark> <b>Located in " + (event->getLocation()) + "</b></p>\n\n";
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

/*
* Function to help with creating results for events
* @param string& name, string& desc, string& date, string& location
* @return data filled from above
*/
void result_creator_helper(std::string& name, std::string& desc, std::string& date, std::string& duration, std::string& location) {
	std::cout << "\nPlease input the name of the event here: ";
	std::getline(std::cin, name);
	std::cout << "\nPlease input the description of the event here: ";
	std::getline(std::cin, desc);

	std::cout << "\nWhat day is this event taking place next? (Please add in DD/MM/YYYY): ";
	std::getline(std::cin, date);

	std::cout << "\nFrom what time until when is the event taking place? (E.G 9:00am-11:00am): ";
	std::getline(std::cin, duration);

	std::cout << "\nWhere is this event taking place?: ";
	std::getline(std::cin, location);
}

/*Function for creating results for a generic event
* @param email_reader* email_maker
* @result N\A
*/
void email_reader::result_creator_generic() {
	std::string name = "";
	std::string desc = "";
	std::string date = "";
	std::string duration = "";
	std::string location = "";
	
	
	//create a new event, then format	
	result_creator_helper(name, desc, date, duration,  location);
	event_generic* event = new event_generic(name, desc, date, duration, location);
	this->format(event);
	std::cin.clear();
}

/*
* Function for creating results for special event
* @param email_reader* email_maker
* @result N\A
*/
void email_reader::result_creator_special() {
	std::string name = "";
	std::string desc = "";
	std::string date = "";
	std::string duration = "";
	std::string location = "";
	std::string collaborators = "";

	result_creator_helper(name, desc, date, duration, location);

	std::cout << "\nPlease input the collaborators of the event here: ";
	std::getline(std::cin, collaborators);

	
	std::cin.clear();

	//create a new event, then format
	event_special* event = new event_special(name, desc, date, location, collaborators);
	this->format(event);
}

/*
* Finds index of event
* @param N\A
* @return index of input
*/
int email_reader::find_event() {
	unsigned int overall_index = 0; //placeholder value

	//loop through the results
	unsigned int currentPage = 0;
	while (true) {
		std::cout << "Which page do you wish to choose" << std::endl;
		for (int i = 0; i < (this->result.size() + 9)/10; i++) {
			std::cout << "Page " + std::to_string(i + 1) << std::endl;
		}


		unsigned int index = 0;//choice for the page
		std::cin >> index;

		index -= 1;

		//if the index is within the range, we accept and continue on
		if (index <= (this->result.size() - 1)) {
			currentPage = index; //save the current page for now

			std::cout << "Page " + std::to_string(currentPage + 1) + " selected." << std::endl;

		
			for (int i = currentPage * 10; i < (currentPage*10)+10 && i < this->result.size(); i++) {
				size_t start = this->result[i].find("<h3>");
				size_t end = this->result[i].find("</h3>", start);

				std::cout << std::to_string((i % 10) + 1) + " " + this->result[i].substr(start + 4, end - (start + 4)) << std::endl;
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

	return overall_index;
}

/*
* Method for updating a specific part of result for special event
* @param N\A
* @return Modified version of results
*/
void email_reader::modify_result() {
	unsigned int overall_index = 0; //placeholder value

	std::cout << "What event would you like to modify?" << std::endl;
	
	overall_index = this->find_event();

	
	//print choice out for the user
	std::cout << "You have selected " << overall_index << std::endl;
	std::cout << this->result[overall_index] <<std::endl;

	char choice = ' ';
	//user knows what they chose, so if it was a mistake, they can choose 4.
	std::cout << "What do you wish to modify for index " + overall_index << " ?\n1:name\n2:desc\n3:date\n4:duration\n5:location\n6:collaborators\nOther inputs:None of the above\n" << std::endl;
	std::cin >> choice; 
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	//if the choice is one, two or three
	if (choice == '1' || choice == '2' || choice == '3' || choice == '4' || choice == '5' || choice == '6') {

		//should a user try to modify collaborators when not present, it is then ignored.
		if (choice == '6') { 
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
		

		//if else statement for what the user chose. 1 == name, 2 == desc, 3 == date, 4 == duration, 5 == location, 6 == collaborators.
		if (choice == '1') {
			temp = "<h3>" + res + this->result[overall_index].substr(this->result[overall_index].find("</h3>"));
		}
		else if (choice == '2') {
			temp = "</h3>" + this->result[overall_index].substr(0, this->result[overall_index].find("</h3>")) + "<p>" + res + "</p>";
		}
		else if (choice == '3') {
			temp = this->result[overall_index].substr(0, this->result[overall_index].find("<mark>")) + +"<mark>" + day_of_week(res,false) + "" + this->result[overall_index].substr(this->result[overall_index].find("</mark>"));
		}
		else if (choice == '4') {
			temp = this->result[overall_index].substr(0, this->result[overall_index].find("<strong>")) +"<strong>" + res + "" + this->result[overall_index].substr(this->result[overall_index].find("</strong>"));
		}
		else if (choice == '5') {
			temp = this->result[overall_index].substr(0, this->result[overall_index].find("<b>")) + res + this->result[overall_index].substr(this->result[overall_index].find("</b>"));
		} 
		else if (choice == '6') {
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

	overall_index = this->find_event();
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
	this->result.clear();
	std::ifstream iFile("event_data.txt");
	//reading all characters from the file
	std::string file_contents((std::istreambuf_iterator<char>(iFile)),
		std::istreambuf_iterator<char>());

	size_t start = 0;
	while (true) {
		size_t end = file_contents.find("<hr>", start);
		if (end == std::string::npos) break;

		std::string event_block = file_contents.substr(start, end - start + 4);

		//updating date of the events
		std::string updated;
		size_t pos = 0;
		while (true) {
			size_t mstart = event_block.find("<mark>", pos);
			if (mstart == std::string::npos) break;

			updated += event_block.substr(pos, mstart - pos);

			size_t mend = event_block.find("</mark>", mstart);
			if (mend == std::string::npos) {
				updated += event_block.substr(mstart);
				pos = event_block.size();
				break;
			}

			std::string mark_content = event_block.substr(mstart + 6, mend - (mstart + 6));
			size_t space_pos = mark_content.find(' ');
			std::string date_str = (space_pos != std::string::npos) ? mark_content.substr(space_pos + 1) : mark_content;

			updated += "<mark>" + day_of_week(date_str, true) + "</mark>";
			pos = mend + 7;
		}
		if (pos < event_block.size()) updated += event_block.substr(pos);

		this->result.push_back(updated);
		start = end + 4;
	}

	if (start < file_contents.size()) {
		std::string last_block = file_contents.substr(start);

		// run the same <mark> update on the last block
		std::string updated;
		size_t pos = 0;
		while (true) {
			size_t mstart = last_block.find("<mark>", pos);
			if (mstart == std::string::npos) break;

			updated += last_block.substr(pos, mstart - pos);

			size_t mend = last_block.find("</mark>", mstart);
			if (mend == std::string::npos) {
				updated += last_block.substr(mstart);
				pos = last_block.size();
				break;
			}

			std::string mark_content = last_block.substr(mstart + 6, mend - (mstart + 6));
			size_t space_pos = mark_content.find(' ');
			std::string date_str = (space_pos != std::string::npos) ? mark_content.substr(space_pos + 1) : mark_content;

			updated += "<mark>" + day_of_week(date_str, true) + "</mark>";
			pos = mend + 7;
		}
		if (pos < last_block.size()) updated += last_block.substr(pos);

		this->result.push_back(updated);
	}

}

/*
* Method for shifting event up the list to the top.
* @param email_reader with at least 2 events
* @return updated results
*/
void email_reader::shift_event() {
	//prevent shifting if nothing there to shift.
	if (this->result.size() < 2) {
		std::cout << "Not enough events to shift priority." << std::endl;
		return;
	}

	//user chooses the event to prioritise
	int res = this->find_event();
	std::string priority_event = this->result[res];
	
	//the specific string is removed (to prevent duplication)
	this->result.erase(this->result.begin() + res);
	std::vector<std::string> temp = this->result;

	//clearing the result and pushing back the priority event to the top
	this->result.clear();
	this->result.push_back(priority_event);

	//shift the event to the top by pushing the rest below. 
	for (std::string events : temp) {
		this->result.push_back(events);
	}

	std::cout << "Event moved to front." << std::endl;
}


/*
* Destructor for email reader object.
* @param N\A
* @return N\A
*/
email_reader::~email_reader() {
	//std::cout << "email_reader deleted" << std::endl;
}