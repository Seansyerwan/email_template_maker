#include <iostream>
#include <vector>

class email_reader;

class event_generic{
public:
	event_generic();
	event_generic(std::string name, std::string desc, std::string time, std::string location);
	void setName(std::string name);
	void setDesc(std::string desc);
	void setTime(std::string time);
	void setLocation(std::string location);
	std::string getName();
	std::string getDesc();
	std::string getTime();
	std::string getLocation();
	~event_generic();
protected:
	std::string name;
	std::string desc;
	std::string time;
	std::string location;
};


class event_special : public event_generic {
public:
	event_special(std::string name, std::string desc, std::string time, std::string location, std::string collaborators);
	void setCollaborators(std::string collaborators);
	std::string getCollaborators();
	~event_special();
protected: 
	std::string collaborators;
};

class email_reader {
public:
	email_reader();
	void format(event_generic* event);
	void format(event_special* event);
	std::vector<std::string> getResult();
	void modify_result();
	void result_creator_generic();
	void result_creator_special();
	int find_event();
	void delete_event();
	void save_email();
	void retrieve_email();
	~email_reader();
protected:
	std::vector<std::string> result;
};