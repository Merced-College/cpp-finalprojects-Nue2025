/**
 * main.cpp
 * Nue Lopez
 * CPSC-25
 * Final Project: National Park Trivia and Search Engine Game!
 * Date: 5/13/2025
 * Short Description: A C++ program with a terminal-based search engine and trivia game.
 */

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include "Database.h"  
#include "ParkSearch.h"  
#include "DataHandler.h" 
using namespace std;

class Center {
public:
    // Method to handle park search for a park by its name and provide information about it.
    //userInput is the input stream, where the user will input their data.
    // parkList1 is a vector memory address of Database objects, which is the list of parks.
    // park1 is a ParkSearch memory address, which is the class that handles the search.
    static void parkSearch(istream& userInput, vector<Database>& parkList1, ParkSearch& park1) {
        cout << "Entering park!" << endl;

        string stateResponse1;
        cout << "What park do you want to search for? Do NOT include \"National Park\" in your search. ";
        getline(userInput, stateResponse1); 
        cout << "\nLooking for " << stateResponse1 << "..." << endl;

        //foundPark is a pointer to the Database object that is returned from the searchByParkName method.
        Database* foundPark = park1.searchByParkName(parkList1, stateResponse1);
        if (foundPark == nullptr) {
            cout << "Park not found" << endl;
        } else {
            cout << "Park found!" << endl;

            bool action1 = false;
            string respondForInfo;
            while (!action1) {
                //foundPark is a pointer to the Database object that is returned from the searchByParkName method.
                cout << "Do you want any information for " << foundPark->getParkName() << " National Park? Type \"No\" to exit: ";
                getline(userInput, respondForInfo);
                if (respondForInfo == "yes" || respondForInfo == "Yes" || respondForInfo == "yeah" || respondForInfo == "Yeah") {
                    cout << "Do you want to know what state it's in, coordinates, the date established, the area in miles/km, visitors per year, the climate, or description? ";
                    string respondForData;
                    getline(userInput, respondForData);

                    if (respondForData == "state" || respondForData == "location") {
                        cout << "State: " << foundPark->getStateName() << endl;
                    } else if (respondForData == "coordinate" || respondForData == "direction") {
                        cout << "Coordinate (in Latitude and Longitude): " << foundPark->getCoordinateLocation() << endl;
                        cout << "Do you know what Latitude and Longitude mean? Yes/No: ";
                        string respondForDirectionInfo;
                        getline(userInput, respondForDirectionInfo);
                        if (respondForDirectionInfo != "yes" && respondForDirectionInfo != "ya" && respondForDirectionInfo != "ye" && respondForDirectionInfo != "yeah") {
                            cout << "1. Degrees and minutes with cardinal directions (e.g., N, S, E, W)." << endl;
                            cout << "2. Decimal degrees with cardinal directions." << endl;
                            cout << "3. Pure decimal degrees to precisely locate the park." << endl;
                        }
                    } else if (respondForData == "date" || respondForData == "creat" || respondForData == "establish") {
                        cout << "Date Established: " << foundPark->getDateEstablished() << endl;
                    } else if (respondForData == "area" || respondForData == "size") {
                        cout << "Area: " << foundPark->getArea2023() << endl;
                    } else if (respondForData == "visitor" || respondForData == "count") {
                        cout << "Visitor count is " << foundPark->getRecreationVisitors() << endl;
                    } else if (respondForData == "climate" || respondForData == "weather" || respondForData == "temp") {
                        cout << "Climate: " << foundPark->getClimate() << endl;
                    } else if (respondForData == "description") {
                        cout << "Description: " << foundPark->getDescription() << endl;
                    } else {
                        cout << "Invalid response for " << foundPark->getParkName() << "'s search. Try again." << endl;
                    }
                } else if (respondForInfo == "no" || respondForInfo == "nah") {
                    action1 = true;
                } else {
                    cout << "Invalid Response. Try again..." << endl;
                }
            }
        }
    }

    // Method to handle state search for parks within a specific state.
    static void searchState(istream& userInput, vector<Database>& parkList1) {
        string state1;
        cout << "What state are you looking for? ";
        getline(userInput, state1);

        ParkSearch park2;
        park2.searchByStateName(parkList1, state1);

        bool stateSearchDone = false;
        while (!stateSearchDone) {
            string userInput1;
            cout << "Do you want to do a park search within this state? ";
            getline(userInput, userInput1);
            if (userInput1 == "yes") {
                cout << "You will now search for a park within " << state1 << endl;
                parkSearch(userInput, parkList1, park2);
                stateSearchDone = true;
            } else if (userInput1 == "no") {
                cout << "Returning to the main menu." << endl;
                stateSearchDone = true;
            } else {
                cout << "Invalid option. Try again." << endl;
            }
        }
    }

    // Method to handle trivia game
        static int triviaGame(istream& userInput, vector<Database>& parkList1, ParkSearch& park1) {
        string triviaResponse;
        Database database2;
        int numPoints = 0;
    
        cout << "Game 1!" << endl;
    
        cout << "What *STATE* does the following climate belong to? ";
        Database* tempDatabase = park1.searchByParkName(parkList1, "Yosemite");
        if (tempDatabase != nullptr) {
            database2 = *tempDatabase;
            cout << database2.getClimate() << endl;
            getline(userInput, triviaResponse);
            // npos indicates "not found" when searching for substrings in a string.
            if (database2.getStateName().find(triviaResponse) != string::npos || triviaResponse.find(database2.getStateName()) != string::npos) {
                cout << "Yes! You got it right! The state belongs to " << database2.getStateName() << endl;
                numPoints++;
            } else {
                cout << "You got it wrong." << endl;
                cout << " The correct state is " << database2.getStateName() << endl;
            }
        } else {
            cout << "Park not found!" << endl;
        }
    
        cout << "Game 2!" << endl;
        tempDatabase = park1.searchByParkName(parkList1, "Olympic"); //Reuses the old tempDatabase and does a binary search.
        if (tempDatabase != nullptr) { //If the park is found, we will return a pointer to the Database object corresponding to the park with the given name.
            database2 = *tempDatabase; //A pointer to the Database object.
            cout << database2.getDescription() << endl;
            cout << "What *STATE* does this description belong to? ";
            getline(userInput, triviaResponse);
            if (database2.getStateName().find(triviaResponse) != string::npos || triviaResponse.find(database2.getStateName()) != string::npos) {
                cout << "Yes! You got it right! The state belongs to " << database2.getStateName() << endl;
                numPoints++;
            } else {
                cout << "You got it wrong." << endl;
                cout << " The correct state is " << database2.getStateName() << endl;
            }
        } else {
            cout << "Park not found!" << endl;
        }
    
        cout << "Game 3!" << endl;
        tempDatabase = park1.searchByParkName(parkList1, "Voyageurs");
        if (tempDatabase != nullptr) {
            database2 = *tempDatabase;
            cout << "The name of the park is " << database2.getParkName() << " National Park. It is located in the state of " << database2.getStateName() << endl;
            cout << "Description: " << database2.getDescription() << endl;
            cout << "When was " << database2.getStateName() << " National Park established? Enter response as Month ##, Year (January 01, 2000): ";
            getline(userInput, triviaResponse);
            if (database2.getDateEstablished().find(triviaResponse) != string::npos || triviaResponse.find(database2.getDateEstablished()) != string::npos) {
                cout << "Yes! You got it right! It was established " << database2.getDateEstablished() << endl;
                numPoints++;
            } else {
                cout << "You got it wrong." << endl;
                cout << " The correct date is " << database2.getDateEstablished() << endl;
            }
        } else {
            cout << "Park not found!" << endl;
        }
    
        return numPoints;
    }

    // Main method to run the program
    static void main() {
        vector<Database> parkList1 = DataHandler::loadDataFromFile("nationalParkList04232025.tsv");
        ParkSearch park1;

        cout << "Welcome to the National Park Search and Trivia Game!" << endl;

        bool inCenter = true;
        while (inCenter) {
            bool validActionSelected = false;

            while (!validActionSelected) {
                cout << "--------------------------------------------------------------------" << endl;
                cout << "Do you want to search for a Park name, State name, or Play the Trivia Game? ";
                string nextAction;
                getline(cin, nextAction);
                for (auto& c : nextAction) c = tolower(c); // Convert each character in the string to lowercase.
                
                if (nextAction.find("park") != string::npos) {
                    validActionSelected = true;
                    cout << "Welcome to the park search! ";
                    parkSearch(cin, parkList1, park1);
                } else if (nextAction.find("state") != string::npos) {
                    validActionSelected = true;
                    cout << "State search:" << endl;
                    searchState(cin, parkList1);
                } else if (nextAction.find("play") != string::npos || nextAction.find("game") != string::npos || nextAction.find("trivia") != string::npos) {
                    validActionSelected = true;
                    int numPoints = triviaGame(cin, parkList1, park1);
                    cout << "You scored " << numPoints << " points!" << endl;
                } else if(nextAction.find("exit") != string::npos || nextAction.find("quit") != string::npos || nextAction.find("leave") != string::npos) {
                    cout << "Exiting the program. Goodbye!" << endl;
                    inCenter = false;
                    validActionSelected = true;
                } else {
                    cout << "Invalid response. Please try again." << endl;
                }
            }
        }
    }
};

int main() {
    Center::main();
    return 0;
}
