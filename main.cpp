/* main.cpp
 * Nue Lopez
 * CPSC-25
 * Final Project: National Park Trivia and Search Engine Game!
 * Date: 5/8/2025
 * Short Description: A C++ program with a terminal-based search engine
 * and trivia game.
 * As of 5/12/2025, I have built a simple TUI (Text User Interface) to 
 * accommodate the user with searching a particular National Park, 
 * looking for a state, and implementing an interactive game. 
 * I need to create more classes and write code to help the user access
 * more data about the park. Visitor count, climate, location (in Latitude
 * and longitude), and other facts about the national park.
 */

// main.cpp - C++ version of Center.java
// Author: Nue Lopez
// Final Project: National Park Search Engine and Trivia Game!

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <thread>
#include <chrono>
#include <cctype>
#include "Database.h"
#include "ParkSearch.h"
#include "DataHandler.h"

using namespace std;

void pauseTime(int seconds) {
    this_thread::sleep_for(chrono::seconds(seconds));
}

int main() {
    vector<Database> parkList1 = loadDataFromFile("nationalParkList04232025.tsv");

    string spaceTab = "    ";
    string spaceDash = "--------------------------------------------------------------------";
    const int SECONDS = 1;

    cout << "Welcome to the National Park Search and Trivia Game*!" << endl;
    cout << spaceTab << "*trivia game coming soon." << endl;
    pauseTime(SECONDS);

    bool inCenter = true;
    string nextAction;

    while (inCenter) {
        bool validActionSelected = false;
        while (!validActionSelected) {
            cout << spaceDash << endl;
            cout << "Do you want to look for a park name, state name, or something else? ";
            getline(cin, nextAction);
            transform(nextAction.begin(), nextAction.end(), nextAction.begin(), ::tolower);

            if (nextAction.find("park") != string::npos) {
                validActionSelected = true;
                cout << "Entering park!\n" << endl;
                pauseTime(SECONDS);

                cout << "Welcome to the park search! "
                     << "What park do you want to search for? Note, it must be the name of the park"
                     << ". Do NOT include \"National Park\" in your search." << endl;

                string stateResponse1;
                getline(cin, stateResponse1);
                cout << "Looking for " << stateResponse1 << "..." << endl;
                pauseTime(SECONDS * 2);

                Database* result = ParkSearch::searchByParkName(parkList1, stateResponse1); // Use class name
                if (!result) {
                    cout << "Park not found" << endl;
                } else {
                    cout << "Park found!" << endl;
                    bool action1 = false;
                    string response1;
                    while (!action1) {
                        Database* database1 = ParkSearch::searchByParkName(parkList1, stateResponse1); // Use class name
                        cout << "Do you want any information for " << database1->getParkName() << " National Park? Type \"No\" to exit" << endl;
                        getline(cin, response1);
                        transform(response1.begin(), response1.end(), response1.begin(), ::tolower);

                        if (response1.find("yes") != string::npos || response1.find("yeah") != string::npos || response1.find("ye") != string::npos) {
                            cout << "Do you want to know what state it's in, coordinates, the date established"
                                 << ", the area in miles/km, visitors per year, the climate, or description?" << endl;
                            string response2;
                            getline(cin, response2);
                            transform(response2.begin(), response2.end(), response2.begin(), ::tolower);

                            if (response2.find("state") != string::npos || response2.find("location") != string::npos) {
                                cout << "State: " << database1->getStateName() << endl;
                            } else if (response2.find("coordinate") != string::npos) {
                                cout << "Coordinate (in Latitude and Longitude): " << database1->getCoordinateLocation() << endl;
                                cout << spaceTab << "Do you know what Latitude and Longitude mean? Yes/No" << endl;
                                string response3;
                                getline(cin, response3);
                                transform(response3.begin(), response3.end(), response3.begin(), ::tolower);
                                if (response3.find("yes") == string::npos && response3.find("ya") == string::npos &&
                                    response3.find("ye") == string::npos && response3.find("yeah") == string::npos) {
                                    cout << "The first part of those coordinates mean the degrees and minutes with cardinal direction. ";
                                    cout << "The second section are the decimal degrees with cardinal direction. ";
                                    cout << "The last bit are the decimal degrees, which help you determine the latitude and longitude." << endl;
                                }
                            } else if (response2.find("date") != string::npos) {
                                cout << "Date Established: " << database1->getDateEstablished() << endl;
                            } else if (response2.find("area") != string::npos) {
                                cout << "Area: " << database1->getArea2023() << endl;
                            } else if (response2.find("visitor") != string::npos || response2.find("count") != string::npos) {
                                cout << "Visitor count for the year " << database1->getRecreationVisitors() << endl;
                            } else if (response2.find("climate") != string::npos || response2.find("weather") != string::npos || response2.find("temperature") != string::npos) {
                                cout << "Climate: " << database1->getClimate() << endl;
                            } else if (response2.find("description") != string::npos) {
                                cout << "Description: " << database1->getDescription() << endl;
                            } else {
                                cout << "Invalid response for " << database1->getParkName() << "'s search. Try again." << endl;
                            }
                        } else if (response1.find("no") != string::npos || response1.find("nah") != string::npos) {
                            action1 = true;
                        } else {
                            cout << "Invalid Response. Try again..." << endl;
                        }
                    }
                }
            } else if (nextAction.find("state") != string::npos) {
                validActionSelected = true;
                cout << "State search:\nWhat state are you looking for?" << endl;
                string state1;
                getline(cin, state1);
                ParkSearch::searchByStateName(parkList1, state1); // Use class name
            } else if (nextAction.find("play") != string::npos || nextAction.find("game") != string::npos || nextAction.find("trivia") != string::npos || nextAction.find("something else") != string::npos) {
                validActionSelected = true;
                cout << "Trivia game coming soon!\nWelcome to the Trivia Game**! **in development." << endl;
                Database* database2 = ParkSearch::searchByParkName(parkList1, "Yosemite"); // Use class name
                if (database2) {
                    cout << database2->getClimate() << endl;
                    cout << "What *STATE* does this description belong to? " << endl;
                    string triviaResponse;
                    getline(cin, triviaResponse);
                    if (database2->getStateName().find(triviaResponse) != string::npos || triviaResponse.find(database2->getStateName()) != string::npos || database2->getStateName().find(triviaResponse) != string::npos) {
                        cout << "Yes! You got it right! The state belongs to " << database2->getStateName() << endl;
                    } else {
                        cout << "You got it wrong! The correct state is " << database2->getStateName() << endl;
                    }
                }
            } else if (nextAction.find("exit") != string::npos || nextAction.find("nothing") != string::npos) {
                validActionSelected = true;
                cout << "Exit Selected..." << endl;
                pauseTime(SECONDS);
            } else {
                inCenter = true;
                cout << "Unavailable option..." << endl;
            }
        }

        bool qToLeave = true;
        string leaveCenter;
        while (qToLeave) {
            cout << "Do you want to leave the center? Yes or no? ";
            getline(cin, leaveCenter);
            transform(leaveCenter.begin(), leaveCenter.end(), leaveCenter.begin(), ::tolower);
            if (leaveCenter == "yes") {
                inCenter = false;
                qToLeave = false;
            } else if (leaveCenter == "no") {
                cout << "Staying in center" << endl;
                qToLeave = false;
            } else {
                cout << "Invalid option... Try again" << endl;
            }
        }
    }
    cout << "\nGoodbye! ";
    pauseTime(SECONDS);
    cout << "You left the center." << endl;
    return 0;
}