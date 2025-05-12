#ifndef PARKSEARCH_H
#define PARKSEARCH_H

#include "Database.h"
#include <vector>
#include <string>
#include <list>
#include <iostream>

class ParkSearch {
public:
    // Binary search by park name
    static Database* searchByParkName(const std::vector<Database>& inputParkData, const std::string& keyParkName);

    // Search by state name, returns a LinkedList (using std::list in C++)
    static std::list<Database> searchByStateName(const std::vector<Database>& inputParkData, const std::string& keyState);

    // Merge Sort parks by state name
    static std::vector<Database> mergeSortByState(std::vector<Database>& parkArrayList);

private:
    // Helper function for merging two sorted lists
    static std::vector<Database> merge(const std::vector<Database>& left, const std::vector<Database>& right);
};

#endif // PARKSEARCH_H
