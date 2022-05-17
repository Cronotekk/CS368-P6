#include <iostream>
#include "CityLocation.h"

using namespace std;

bool CityLocation::Reserve() {
    if (reservations > 0) {
        reservations--;
        return true;
    }
    return false;
}

void CityLocation::Print() const {
    cout << "*** Off-Campus ***" << endl
         << "Location:     " << name    << endl
         << "Address:      " << address << endl
         << "Hours:        " << hours   << endl
         << "Reservations: " << reservations << endl;
         //<< "Press enter to return to menu." << endl;
}

void CityLocation::Read(std::istream& s) {
    float x;
    float y;
    std::string s_x;
    std::string s_y;
    getline(s, name, ',');
    while (s.peek() == ' ') { s.get(); } // not strictly necessary, but if there's space between ',' and next item, ignore it.
    getline(s, address, ',');
    while (s.peek() == ' ') { s.get(); }
    getline(s, hours, ',');
    while (s.peek() == ' ') { s.get(); }
    getline (s, s_x, ',');
    //cout << "CityX: " << s_x << endl;
    while (s.peek() == ' ') { s.get(); }
    getline (s, s_y, ',');
    //cout << "CityY: " << s_y << endl;
    s >> reservations;
    while (s.peek() == '\n') { s.get(); }
    x = stof(s_x);
    y = stof(s_y);
    Position pos(x, y);
    position = pos;
}

void CityLocation::Write(std::ostream& s) const {
    s << "citylocation" << endl;
    s << name << "," << address << "," << hours << "," << position.GetX() << "," << position.GetY() << "," << reservations;
}

Location* CityLocation::Clone() { return new CityLocation(name, address, hours, reservations); }
