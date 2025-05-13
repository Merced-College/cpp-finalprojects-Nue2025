// DataHandler.h
#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <vector>
#include <string> //Handles strings.
#include "Database.h" // Ensure that this includes the Database class.


class DataHandler {
public:
    // loadDataFromFile constructs the tsv file name and reads it to the user..
    static std::vector<Database> loadDataFromFile(const std::string& tsvFileName);
};

#endif // DATAHANDLER_H
