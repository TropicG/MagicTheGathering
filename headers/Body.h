#ifndef BODY
#define BODY
#include <string>
#include <iostream>

const int IdLimit = 32768;

class Body {
protected:
	std::string name;
	unsigned id;

public:
	Body();
	Body(const char* name);
	Body(const Body& other);
	Body& operator=(const Body& other);

	bool operator==(const std::string& name) const;
	bool operator==(const unsigned& id) const;

	std::string getName() const;
	unsigned getId() const;
	void generateId();

	void setName(const char* name);
	void setId(const unsigned& id);

	virtual void print() const;
	virtual void read() = 0;

	friend std::ostream& operator<<(std::ostream& os, const Body& body);
};
#endif