#include "ParkSearch.h"
#include <algorithm>
#include <thread>
#include <chrono>
using namespace std;

/*
 * Uses a data structure of vector and linked list to search for parks by name and state.
 * Algorithm 1 searches for a national park by its name using the binary search algorithm.
 */
Database* ParkSearch::searchByParkName(const vector<Database>& inputParkData, const string& keyParkName) {
    int left = 0;
    int right = inputParkData.size() - 1;

    while (left <= right) {
        int middle = (right + left) / 2;
        //Creates an address of the park name and stores the inputParkData vector.
        const string& middleName = inputParkData[middle].getParkName(); 
        int comparison = middleName.compare(keyParkName); 

        if (comparison < 0) {
            left = middle + 1;
        } else if (comparison > 0) {
            right = middle - 1;
        } else {
            return const_cast<Database*>(&inputParkData[middle]); // Return pointer to the found park
        }
    }
    return nullptr; // Park not found
}

/*
 * Searches for national parks by state name and returns a linked list (std::list) of parks that match the given state. It will print the names 
 * of the parks and return the results of the search. This method also uses a list data structure to store the results. This will searc parks 
 * in a specific state.
 */
list<Database> ParkSearch::searchByStateName(const vector<Database>& inputParkData, const string& keyState) {
    list<Database> result; //Creates a list to store the results.

    for (const Database& park : inputParkData) { //Iterates through the vector of Database objects using a loop.
        // If the park's state name contains the keyState, it adds the park to the result list.
        if (park.getStateName().find(keyState) != string::npos) {
            result.push_back(park); // Adds each park name in its state to a list,
            //a data structure to return the results.
            cout << "- " << park.getParkName() << endl;
        }
    }

    if (result.empty()) {
        cout << "No park is found in " << keyState << endl;
    }

    return result; // Return a list called result.
}

/*
 * Algorithm 2 sorts a list of national parks by state name using the merge sort algorithm.
 * The algorithm is recursive and divides the input list into smaller sublists for sorting.
 */
vector<Database> ParkSearch::mergeSortByState(vector<Database>& parkArrayList) {
    if (parkArrayList.size() <= 1) {
        return parkArrayList;
    }

    int mid = parkArrayList.size() / 2;
    vector<Database> left(parkArrayList.begin(), parkArrayList.begin() + mid);
    vector<Database> right(parkArrayList.begin() + mid, parkArrayList.end());

    left = mergeSortByState(left);
    right = mergeSortByState(right);

    return merge(left, right);
}

/*
 * Merges two sorted vectors of parks by state name into a single sorted vector.
 * This method is part of the merge sort algorithm and combines two halves of a list.
 * left is a vector of Database objects representing the left sorted sublist.
 * right is a vector of Database objects representing the right sorted sublist.
 * The program returns a vector of Database objects containing all elements from both sublists, sorted by state name.
 */
vector<Database> ParkSearch::merge(const vector<Database>& left, const vector<Database>& right) {
    vector<Database> merged;
    int i = 0, j = 0;

    while (i < left.size() && j < right.size()) {
        const string& leftState = left[i].getStateName();
        const string& rightState = right[j].getStateName();

        if (leftState.compare(rightState) <= 0) {
            merged.push_back(left[i]);
            i++;
        } else {
            merged.push_back(right[j]);
            j++;
        }
    }

    while (i < left.size()) {
        merged.push_back(left[i]);
        i++;
    }

    while (j < right.size()) {
        merged.push_back(right[j]);
        j++;
    }

    return merged;
}