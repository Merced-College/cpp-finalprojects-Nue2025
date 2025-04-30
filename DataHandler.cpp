// DataHandler.cpp

#include "DataHandler.h"
#include <fstream>
#include <sstream>
#include <iostream>

// 	Github is acting weird... they want the FileInputStream on the same line as try... check the github link for more
// 	questions.
vector<Database> DataHandler::loadDataFromFile(const string& csvFileName) {
    vector<Database> parkList;

    try {
        ifstream file(csvFileName);
        string line;

        getline(file, line); //This reads the first line because the header row is something we do not need

        while (getline(file, line)) {
            // 	Used AI to help me separate the commas. It kept losing data specific to the tables, so it recommended
            // 	using a TSV (tab separated values) instead of a CSV (comma separated values).
            vector<string> parts;
            stringstream ss(line);
            string item;

            while (getline(ss, item, '\t')) { // \t looks for any tabs (approx 4 spaces or 1 tab)
                parts.push_back(item);
            }

            if (parts.size() < 8) continue; //Skips the incomplete lines

            string parkName = parts[0];
            string stateName = parts[1];
            string coordinates = parts[2];
            string dateEstablished = parts[3];
            string area = parts[4];

            int visitors = 0;
            try {
                // Remove non-digit characters
                string digitsOnly;
                for (char c : parts[5]) {
                    if (isdigit(c)) digitsOnly += c;
                }
                if (!digitsOnly.empty()) {
                    visitors = stoi(digitsOnly);
                }
            } catch (...) {
                // If parsing fails, visitors stays as 0
            }

            string climate = parts[6];
            string description = parts[7];

            Database park(parkName, stateName, coordinates, dateEstablished, area, visitors, climate, description);
            parkList.push_back(park);
        }

        file.close();

    } catch (const exception& e) {
        cout << "Error with loading file: " << e.what() << endl;
    }

    return parkList; //End try
}
