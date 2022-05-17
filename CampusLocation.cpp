#include <iostream>
#include "CampusLocation.h"

using namespace std;

bool CampusLocation::Reserve() {
    return false;
}

void CampusLocation::Print() const {
    cout << "*** On-Campus ***" << endl
         << "Location:     " << name    << endl
         << "Address:      " << address << endl
         << "Hours:        " << hours   << endl
         << "Reservations: None" << endl;
         //<< "Press enter to return to menu." << endl;
}

void CampusLocation::Read(std::istream& s) {
    float x;
    float y;
    std::string s_x;
    std::string s_y;
    getline(s, name, ',');
    //cout << "CampusName: " << name << endl;
    while (s.peek() == ' ') { s.get(); } // not strictly necessary, but if there's space between ',' and next item, ignore it.
    getline(s, address, ',');
    //cout << "CampusAdress: " << address << endl;
    while (s.peek() == ' ') { s.get(); }
    getline(s, hours, ',');
    //cout << "CampusHours: " << hours << endl;
    while (s.peek() == ' ') { s.get(); }
    getline(s, s_x, ',');
    //cout << "CampusX: " << s_x << endl;
    while (s.peek() == ' ') { s.get(); }
    getline(s, s_y);
    //cout << "CampusY: " << s_y << endl;
    x = stof(s_x);
    y = stof(s_y);
    Position pos(x, y);
    position = pos;
}

void CampusLocation::Write(std::ostream& s) const {
    s << "campuslocation" << endl;
    s << name << "," << address << "," << hours << "," << position.GetX() << "," << position.GetY() << endl;
}

Location* CampusLocation::Clone() { return new CampusLocation(name, address, hours); }
