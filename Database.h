// Database.h
#ifndef DATABASE_H
#define DATABASE_H

#include <string>
using namespace std;

class Database {
private:
    //Private variables
    string parkName, stateName, coordinateLocation, dateEstablished, area2023;
    int recreationVisitors;
    string climate, description;

public:
    //Constructor
    Database(); //End Database() constructor

//NOT SURE what this does yet
    Database(string parkNameInput, string stateNameInput, string coordinateLocationInput, string dateEstablishedInput,
             string area2023Input, int recreationVisitorsInput, string climateInput, string descriptionInput);

    //Setter section for the data.
    void setParkName(string parkNameInput);
    void setStateName(string stateNameInput);
    void setCoordinateLocation(string coordinateLocationInput);
    void setDateEstablished(string dateEstablishedInput);
    void setArea2023(string area2023Input);
    void setRecreationVisitors(int recreationVisitorsInput);
    void setClimate(string climateInput);
    void setDescription(string descriptionInput);

    //Getter section for the data.
    string getParkName() const;
    string getStateName() const;
    string getCoordinateLocation() const;
    string getDateEstablished() const;
    string getArea2023() const;
    int getRecreationVisitors() const;
    string getClimate() const;
    string getDescription() const;

    string toString() const;

//USED AI in this section to explain how @Override works and why my information came out as addresses (GIBBERISH@NUMBERS).
    friend ostream& operator<<(ostream& os, const Database& db);
};

#endif