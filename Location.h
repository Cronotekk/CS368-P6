#ifndef LOCATION
#define LOCATION

#include <iostream>
#include <string>
#include "Position.h"

class Location {
protected:
    std::string name, address, hours;
    int reservations;
    float x, y;
    Position position;
public:
    Location(std::string init_name = "Kohl Center, Gate C", std::string  init_addr = "601 W Dayton St",
             std::string init_hrs  = "9:00am-5:00pm",   float init_x = 5,	float init_y = 5,    
	     bool init_reservations = true) :
             name(init_name), address(init_addr), hours(init_hrs), position(x, y), reservations(init_reservations) {};

    // one-liner to get a member variable, write inline in .h
    virtual bool IsReservable() const { return reservations > 0; }

    // one-liner to get a member variable, write inline in .h
    std::string to_string() const { return name; }

    virtual bool Reserve() = 0;

    virtual void Cancel() = 0;

    // Somewhat more complicated function, implement in .cpp
    virtual void Print() const = 0;

    virtual void Read(std::istream& s) = 0;

    virtual void Write(std::ostream& s) const = 0;

    virtual Location* Clone() = 0; // Helper function, allows us to "clone" a copy to use in the User's LocationList.

    float operator-(const Position that) {float d = position - that; return d;}
};
#endif
