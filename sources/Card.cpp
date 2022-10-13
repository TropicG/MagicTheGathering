#include "Card.h"

bool Card::valid(const std::string& color) const
{
    return color == "Red" || color == "White" || color == "Black" || color == "Blue" || color == "Green";
}

Card::Card() : Body()
{
}

Card::Card(const char* name, const char* color) :
    Body(name)
{
    this->setColor(color);
}

Card::Card(const Card& other) :
    Body(other)
{
    this->setColor(other.getColor().c_str());
}

Card& Card::operator=(const Card& other)
{
    if (this != &other) {

        Body::operator=(other);
        this->setColor(other.getColor().c_str());
    }

    return *this;
}

std::string Card::getColor() const
{
    return this->color;
}

void Card::setColor(const char* color)
{
    this->color = color;
}

void Card::print() const
{
    Body::print();
    std::cout << ", Color: " << this->color << std::endl;
}

void Card::read()
{
    char name[cardNameMax];
    std::cout << "Enter the name of the card: ";
    if (std::cin.peek() == '\n') std::cin.ignore();
    std::cin.getline(name, cardNameMax, '\n');
    bool failed = std::cin.fail();
    if (failed) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    this->setName(name);

    std::string color;
    std::cout << "Enter the color: ";
    std::cin >> color;

    while (!this->valid(color)) {
        std::cout << "Wrong color, try again: ";
        color.clear();
        std::cin >> color;
    }

    this->setColor(color.c_str());
    this->generateId();
}

std::ostream& operator<<(std::ostream& os, const Card& card)
{
    os << card.name << "|" << card.id << " " << card.color << std::endl;

    return os;
}

std::istream& operator>>(std::istream& is, Card& card)
{
    char name[cardNameMax];
    if (is.peek() == '\n') is.ignore();
    is.getline(name, cardNameMax, '|');
    card.setName(name);

    is >> card.id >> card.color;
    
    return is;
}
