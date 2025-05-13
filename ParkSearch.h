#ifndef PARKSEARCH_H
#define PARKSEARCH_H

#include "Database.h"
#include <vector>
#include <string>
#include <list> //Uses a data structure of list to store the results, and will be used in the class file.
#include <iostream>

class ParkSearch {
public:
    // Algorithm 1: Binary search by park name will be implemented in the cpp class.
    static Database* searchByParkName(const std::vector<Database>& inputParkData, const std::string& keyParkName);

    // Search by state name, returns a LinkedList using std::list. I used AI to help me understand this library.
    static std::list<Database> searchByStateName(const std::vector<Database>& inputParkData, const std::string& keyState);

    // Algorithm 2: Merge Sort parks by state name
    static std::vector<Database> mergeSortByState(std::vector<Database>& parkArrayList);

private:
    // Helper function for merging two sorted lists
    static std::vector<Database> merge(const std::vector<Database>& left, const std::vector<Database>& right);
};

#endif // PARKSEARCH_H
