#include "DataHandler.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
// #ifndef DATAHANDLER_H
// #define DATAHANDLER_H

using namespace std;

vector<Database> loadDataFromFile(const string& filename) {
    vector<Database> parkList;
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Error with loading file: " << filename << endl;
        return parkList;
    }

    string line;
    getline(file, line); // Skip header line

    while (getline(file, line)) {
        stringstream ss(line);
        string parkName, stateName, coordinates, dateEstablished, area, visitorsStr, climate, description;

        // Read tab-separated values
        getline(ss, parkName, '\t');
        getline(ss, stateName, '\t');
        getline(ss, coordinates, '\t');
        getline(ss, dateEstablished, '\t');
        getline(ss, area, '\t');
        getline(ss, visitorsStr, '\t');
        getline(ss, climate, '\t');
        getline(ss, description, '\t');

        if (parkName.empty() || stateName.empty() || coordinates.empty()) continue;

        // Parse visitors as int, remove non-digits
        string digitsOnly;
        for (char c : visitorsStr) {
            if (isdigit(c)) digitsOnly += c;
        }

        int visitors = 0;
        try {
            visitors = stoi(digitsOnly);
        } catch (...) {
            visitors = 0;
        }

        Database park(parkName, stateName, coordinates, dateEstablished, area, visitors, climate, description);
        parkList.push_back(park);
    }

    file.close();
    return parkList;
}
    // #endif // DATAHANDLER_H
