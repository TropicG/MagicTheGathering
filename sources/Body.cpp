#include "Body.h"

void Body::generateId()
{
    this->id = (rand() % IdLimit) + 0;
}

Body::Body()
{
}

Body::Body(const char* name)
{
    this->setName(name);
    this->generateId();
}

Body::Body(const Body& other)
{
    this->setName(other.getName().c_str());
    this->setId(other.getId());
}

Body& Body::operator=(const Body& other)
{
    if (this != &other) {

        this->setName(other.getName().c_str());
        this->setId(other.getId());
    }

    return *this;
}

bool Body::operator==(const std::string& name) const
{
    return this->name == name;
}

bool Body::operator==(const unsigned& id) const
{
    return this->id == id;
}

std::string Body::getName() const
{
    return this->name;
}

unsigned Body::getId() const
{
    return this->id;
}

void Body::setName(const char* name)
{
    this->name = name;
}

void Body::setId(const unsigned& id)
{
    this->id = id;
}

void Body::print() const
{
    std::cout << "Name: " << this->name << ", Id: " << this->id;
}

std::ostream& operator<<(std::ostream& os, const Body& body)
{
    os << body.name << "|" << body.id << std::endl;

    return os;
}

