#include "ParkSearch.h"
#include <algorithm>

using namespace std;

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

list<Database> ParkSearch::searchByStateName(const vector<Database>& inputParkData, const string& keyState) {
    list<Database> result;

    for (const Database& park : inputParkData) {
        if (park.getStateName().find(keyState) != string::npos) {
            result.push_back(park);
            cout << "- " << park.getParkName() << endl;
        }
    }

    if (result.empty()) {
        cout << "No park is found in " << keyState << endl;
    }

    return result;
}

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
