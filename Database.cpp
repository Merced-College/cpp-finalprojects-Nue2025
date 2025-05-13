// Database.cpp
#include "Database.h"
#include <string>
#include <sstream>
using namespace std;

//Default constructor with default values and encapsulates the data.
Database::Database() {
    parkName = "Unknown";
    stateName = "Unknown";
    coordinateLocation = "Unknown";
    dateEstablished = "Unknown";
    area2023 = "Unknown";
    recreationVisitors = -1;
    climate = "Unknown";
    description = "Unknown";
}

//This is the constructor that takes in all the parameters and initializes the member variables.
Database::Database(string parkNameInput, string stateNameInput, string coordinateLocationInput,
                   string dateEstablishedInput, string area2023Input, int recreationVisitorsInput,
                   string climateInput, string descriptionInput) {
    parkName = parkNameInput;
    stateName = stateNameInput;
    coordinateLocation = coordinateLocationInput;
    dateEstablished = dateEstablishedInput;
    area2023 = area2023Input;
    recreationVisitors = recreationVisitorsInput;
    climate = climateInput;
    description = descriptionInput;
}

//Setters
void Database::setParkName(string parkNameInput) { parkName = parkNameInput; }
void Database::setStateName(string stateNameInput) { stateName = stateNameInput; }
void Database::setCoordinateLocation(string coordinateLocationInput) { coordinateLocation = coordinateLocationInput; }
void Database::setDateEstablished(string dateEstablishedInput) { dateEstablished = dateEstablishedInput; }
void Database::setArea2023(string area2023Input) { area2023 = area2023Input; }
void Database::setRecreationVisitors(int recreationVisitorsInput) { recreationVisitors = recreationVisitorsInput; }
void Database::setClimate(string climateInput) { climate = climateInput; }
void Database::setDescription(string descriptionInput) { description = descriptionInput; }

//Getters
string Database::getParkName() const { return parkName; }
string Database::getStateName() const { return stateName; }
string Database::getCoordinateLocation() const { return coordinateLocation; }
string Database::getDateEstablished() const { return dateEstablished; }
string Database::getArea2023() const { return area2023; }
int Database::getRecreationVisitors() const { return recreationVisitors; }
string Database::getClimate() const { return climate; }
string Database::getDescription() const { return description; }

//This toString method returns a string representation of the object, as written in the header file.
// It concatenates the member variables into a formatted string, so it's not gibberish (address).
// This method is useful for debugging and displaying the object's data in a readable format.
string Database::toString() const {
    return "Park name: " + parkName + ", State: " + stateName + ", Location: " + coordinateLocation +
           ", Established: " + dateEstablished + ", Area: " + area2023 + ", Visitors: " +
           to_string(recreationVisitors) + ", Climate: " + climate +
           "\nDescription of " + parkName + ": " + description + "\n";
}

/*
 * Parses data from a file line. This method reads a line from a file and populates 
 * the Database object with the data. It uses a string stream to separate the data by tabs 
 * and assigns the values to the corresponding member variables. It also handles the conversion 
 * of the number of visitors from a string to an integer. The method returns true if the parsing 
 * is successful, and false otherwise.
*/
bool Database::parseFromLine(std::istringstream& stream) {
    std::string visitorsStr;
    if (std::getline(stream, parkName, '\t') &&
        std::getline(stream, stateName, '\t') &&
        std::getline(stream, coordinateLocation, '\t') &&
        std::getline(stream, dateEstablished, '\t') &&
        std::getline(stream, area2023, '\t') &&
        std::getline(stream, visitorsStr, '\t') &&
        std::getline(stream, climate, '\t') &&
        std::getline(stream, description, '\t')) {
        try {   //Will attempt to convert a string visitorsStr into an 
            recreationVisitors = std::stoi(visitorsStr);    //integer called 
        } catch (...) { //recreationVisitors using stoi (string to int 
            recreationVisitors = -1; // conversion). If it fails, 
        } //it'll catch the exception and assign it with -1.
        return true; //Returns true if parsing is successful.
    }
    return false; // Returns false if parsing fails, meaning that the line is not valid.
}