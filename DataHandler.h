// DataHandler.h
#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <string>
#include <vector>
#include "Database.h"
using namespace std;

class DataHandler {
public:
    static vector<Database> loadDataFromFile(const string& csvFileName); //We will have to return something along the lines of an ArrayList
};

#endif
