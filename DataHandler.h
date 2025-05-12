// DataHandler.h
#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <vector>
#include <string>
#include "Database.h"

using namespace std;
//NOT using namespace std; to avoid polluting the global namespace, suggested by AI.
vector<Database> loadDataFromFile(const std::string& filename);

#endif // DATAHANDLER_H
