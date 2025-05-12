// DataHandler.h
#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <vector>
#include <string>
#include "Database.h"

//NOT using namespace std; to avoid polluting the global namespace, suggested by AI.
std::vector<Database> loadDataFromFile(const std::string& tsvFileName);

#endif // DATAHANDLER_H
