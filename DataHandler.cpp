#include "DataHandler.h" //Make's sure that we include the DataHandler header file.
#include <fstream> //This includes a library to both read from and write files.
#include <sstream> //It includes a library to read and write strings from a stream. A stream is a sequence of characters.
#include <iostream> // This includes a library to create input and output streams.
#include <vector>   // This includes a library to create a vector, which is a dynamic array.
#include <algorithm> // For std::remove_if, and removes elements from a container based on a condition.

/**
 * Loads national park data from a TSV file and stores each row as a Database object in a vector.
 * @param tsvFileName A string addressing the name or path of the TSV file to load park data from.
 * @return A vector of Database objects representing all the parks loaded from the file.
 */
std::vector<Database> DataHandler::loadDataFromFile(const std::string& tsvFileName) {
    std::vector<Database> parkList;
    try { //Uses a data structure of ifstream to read the file from the TSV File.
        std::ifstream file(tsvFileName); //This is where the ifsstream library is used to read the file.

        if (!file.is_open()) { //This checks if the file is open. If it is NOT, it will throw an error.
            throw std::ios_base::failure("Error: Could not open file " + tsvFileName);
        }

        std::string line;
        // This reads the first line because the header row is something we do not need.
        std::getline(file, line);

        while (std::getline(file, line)) {
            // Used AI to help me separate the tabs. It kept losing data specific to the tables, 
            // so it recommended using a TSV (tab-separated values) instead of a CSV (comma-separated values).
            std::istringstream stream(line); // This creates a string stream from the line read.
            std::vector<std::string> parts; // This is a vector of strings that will hold the parts of the line.
            std::string part; // This is a string that will hold each part of the line.

            //Algorithm 3
            // Looks for tabs. Keeps empty fields.
            while (std::getline(stream, part, '\t')) {
                parts.push_back(part);
            }

            // Skips the incomplete lines
            if (parts.size() < 8) continue;

            // Extract and trim fields
            std::string parkName = parts[0];
            std::string stateName = parts[1];
            std::string coordinates = parts[2];
            std::string dateEstablished = parts[3];
            std::string area = parts[4];
            int visitors = 0;
            try {
                // Used AI to help me understand how to separate the parts. It was difficult to figure out how to trim the data.
                std::string visitorsStr = parts[5];
                visitorsStr.erase(std::remove_if(visitorsStr.begin(), visitorsStr.end(), [](char c) { return !std::isdigit(c); }), visitorsStr.end());
                visitors = std::stoi(visitorsStr);
            } catch (...) {
                // If parsing fails, visitors stays as 0.
                visitors = 0;
            }
            std::string climate = parts[6];
            std::string description = parts[7];

            // Adds a park Database class to the line read.
            Database park(parkName, stateName, coordinates, dateEstablished, area, visitors, climate, description);
            parkList.push_back(park);
        }

        file.close(); // This closes the file after reading it.
    } catch (const std::exception& e) {
        //If the file does not exist, it will print out an error message.
        //std::cerr is used to print error messages to the standard error stream.
        std::cerr << "Error with loading file: " << e.what() << std::endl;
        return {}; //Returns an empty vector if the file does not exist.
    }
    return parkList;
}
