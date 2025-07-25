#include <iostream>

class email_reader;

class event_generic{
public:
	event_generic();
	event_generic(std::string name, std::string desc);
	void setName(std::string name);
	void setDesc(std::string desc);
	std::string getName();
	std::string getDesc();
	~event_generic();
protected:
	std::string name;
	std::string desc;
};


class event_special : public event_generic {
public:
	event_special(std::string name, std::string desc, std::string collaborators);
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
	std::string getResult();
	~email_reader();
protected:
	std::string result;
};