// Database.h
#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <sstream>
using namespace std;

class Database {
private:
    string parkName, stateName, coordinateLocation, dateEstablished, area2023;
    int recreationVisitors;
    string climate, description;

public:
    Database(); // Default constructor
    Database(string parkNameInput, string stateNameInput, string coordinateLocationInput,
             string dateEstablishedInput, string area2023Input, int recreationVisitorsInput,
             string climateInput, string descriptionInput);

    // Setters
    void setParkName(string parkNameInput);
    void setStateName(string stateNameInput);
    void setCoordinateLocation(string coordinateLocationInput);
    void setDateEstablished(string dateEstablishedInput);
    void setArea2023(string area2023Input);
    void setRecreationVisitors(int recreationVisitorsInput);
    void setClimate(string climateInput);
    void setDescription(string descriptionInput);

    // Getters
    string getParkName() const;
    string getStateName() const;
    string getCoordinateLocation() const;
    string getDateEstablished() const;
    string getArea2023() const;
    int getRecreationVisitors() const;
    string getClimate() const;
    string getDescription() const;

    string toString() const; // toString method to return a string representation of the object
    bool parseFromLine(std::istringstream& stream); // Parses data from a file line
};

#endif // DATABASE_H