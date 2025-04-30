/* main.cpp
 * Nue Lopez
 * CPSC-25
 * Final Project: National Park Trivia and Search Engine Game!
 * Date: 4/23/2025
 * Short Description: A Java program with a terminal-based search engine
 * and trivia game.
 * As of 4/29/2025, I have built a simple TUI (Text User Interface) to 
 * accomodate the user with searching a particular National Park, 
 * looking for a state, and implementing an interactive game. 
 * I need to create more classes and write code to help the user access
 * more data of the park. Visitor count, climate, location (in Latitude
 * and longitude), and other facts about the national park.
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Database.h"
#include "DataHandler.h"
using namespace std;

int main() {
	string tabSpace = "    "; //Not necessary. Ussed for testing purposes...
	//Loads the file from the eclipse folder
	vector<Database> parkList1 = DataHandler::loadDataFromFile("nationalParkList04232025.tsv"); 
//	Database database1 = new Database(); //Not in use so I commented out!

	bool inCenter = true;
	string nextAction;
	while(inCenter) {
		cout << "Do you want to look for a park name, state name, or something else? ";
		getline(cin, nextAction);
		if (nextAction.find("park") != string::npos) { //AI Explained how it will look for a string throughout the whole string.
            //If it is found, then it will be true and continue on.
			cout << "Entering park!" << endl;
			cout << endl;
			
			cout << "Welcome to the park search! ";
			cout << "What park do you want to search for? ";
			string stateResponse1;
			getline(cin, stateResponse1);
			cout << "Looking for " << stateResponse1 << "..." << endl;
			
			
		}else if (nextAction.find("state") != string::npos) {
			cout << "Entering state search soon..." << endl;
		}else {
			cout << "Unavailable option..." << endl;
		}
		
		bool qToLeave = true;
		string leaveCenter;
		while(qToLeave) {
			cout << "Do you want to leave the center? Yes or no? ";
			getline(cin, leaveCenter);
			for (char &c : leaveCenter) c = tolower(c); // lowercase
			
			if (leaveCenter == "yes") { 
				inCenter = false; 
				qToLeave = false;
			}else if (leaveCenter == "no") {
				cout << "Staying in center" << endl;
				qToLeave = false;
			}else {
				cout << "Invalid option... Try again" << endl;
			}
		}//End qToLeave while loop
		
	}//Left leaveCenter while loop
	cout << "\nYou left the center." << endl;

	return 0;
}//End of main.
