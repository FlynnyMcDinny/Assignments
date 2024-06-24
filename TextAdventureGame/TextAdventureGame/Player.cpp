#include "Player.h"
#include <iostream>
#include <cmath>
#include <list>
#include <vector>

using namespace std;

Player::Player()
{
    BinarySearch(spells,"Thunderwave");
}

bool Player::BinarySearch(const vector<string>& arr, const string& target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid].compare(target) == 0) {
            cout << "Found the spell at: " << mid << endl;
            return true;
        }
        else if (arr[mid].compare(target) < 0) {
            left = mid + 1; 
        }
        else {
            right = mid - 1; 
        }
    }

    return false; 
}

