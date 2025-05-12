// Database.cpp
#include "Database.h"
#include <string>
using namespace std;

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

// Setters
void Database::setParkName(string parkNameInput) { parkName = parkNameInput; }
void Database::setStateName(string stateNameInput) { stateName = stateNameInput; }
void Database::setCoordinateLocation(string coordinateLocationInput) { coordinateLocation = coordinateLocationInput; }
void Database::setDateEstablished(string dateEstablishedInput) { dateEstablished = dateEstablishedInput; }
void Database::setArea2023(string area2023Input) { area2023 = area2023Input; }
void Database::setRecreationVisitors(int recreationVisitorsInput) { recreationVisitors = recreationVisitorsInput; }
void Database::setClimate(string climateInput) { climate = climateInput; }
void Database::setDescription(string descriptionInput) { description = descriptionInput; }

// Getters
string Database::getParkName() const { return parkName; }
string Database::getStateName() const { return stateName; }
string Database::getCoordinateLocation() const { return coordinateLocation; }
string Database::getDateEstablished() const { return dateEstablished; }
string Database::getArea2023() const { return area2023; }
int Database::getRecreationVisitors() const { return recreationVisitors; }
string Database::getClimate() const { return climate; }
string Database::getDescription() const { return description; }

string Database::toString() const {
    return "Park name: " + parkName + ", State: " + stateName + ", Location: " + coordinateLocation +
           ", Established: " + dateEstablished + ", Area: " + area2023 + ", Visitors: " +
           to_string(recreationVisitors) + ", Climate: " + climate +
           "\nDescription of " + parkName + ": " + description + "\n";
}
