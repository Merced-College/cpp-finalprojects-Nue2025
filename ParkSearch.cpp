#include "ParkSearch.h"
#include <algorithm>
#include <thread>
#include <chrono>
using namespace std;

/**
 * Algorithm 1 searches for a national park by its name using the binary search algorithm.
 * @param inputParkData A vector of Database objects containing all the park data.
 * @param keyParkName A string representing the name of the park to search for.
 * @return A pointer to the Database object corresponding to the park with the given name, or nullptr if not found.
 */
Database* ParkSearch::searchByParkName(const vector<Database>& inputParkData, const string& keyParkName) {
    int left = 0;
    int right = inputParkData.size() - 1;

    while (left <= right) {
        int middle = (right + left) / 2;
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

/**
 * Searches for national parks by state name and returns a linked list (std::list) of parks that match the given state.
 * It will print the names of the parks and return the results of the search.
 * @param inputParkData A vector of Database objects containing all the park data.
 * @param keyState A string representing the state to search for.
 * @return A list of Database objects representing the parks located in the specified state.
 */
list<Database> ParkSearch::searchByStateName(const vector<Database>& inputParkData, const string& keyState) {
    list<Database> result;

    for (const Database& park : inputParkData) {
        // We're putting the following if statement's comparisons to lower-case so we don't have any accidental mistakes.
        if (park.getStateName().find(keyState) != string::npos) {
            result.push_back(park); // Adds each park name in its state to a linked list.
            cout << "- " << park.getParkName() << endl;
        }
    }

    if (result.empty()) {
        cout << "No park is found in " << keyState << endl;
    }

    return result; // Return a linked list called result.
}

/**
 * Algorithm 2 sorts a list of national parks by state name using the merge sort algorithm.
 * This method is recursive and divides the input list into smaller sublists for sorting.
 * @param parkArrayList A vector of Database objects containing the parks to be sorted.
 * @return A vector of Database objects sorted by state name.
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

/**
 * Merges two sorted vectors of parks by state name into a single sorted vector.
 * This method is part of the merge sort algorithm and combines two halves of a list.
 * @param left A vector of Database objects representing the left sorted sublist.
 * @param right A vector of Database objects representing the right sorted sublist.
 * @return A vector of Database objects containing all elements from both sublists, sorted by state name.
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