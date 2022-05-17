#ifndef LOCATION_LIST
#define LOCATION_LIST

#include <string>
#include <vector>
#include "Location.h"
#include "Position.h"

class LocationList {
private:
    std::vector<Location*> list;
public:
    LocationList();
    ~LocationList();
    int GetCount() const { return list.size(); }
    Location* GetLocation(int i) const { return list[i]; }
    void AddLocation(Location* new_loc);
    void FromFile(std::string fname);
    void ToFile(std::string fname);
    class Closer {
	    private:
	    Position pos;
	    public:
	    Closer (Position p = Position(5, 5)) : pos(p.GetX(), p.GetY()) {};
	    bool operator()(Location* a, Location* b) {
		    float dist_a = *a - pos;
		    float dist_b = *b - pos;
		    if (dist_a < dist_b) {
			    return true;
		    } else {
			    return false;
		    }
	    }
    };
    void Sort (Position p);
};

#endif
