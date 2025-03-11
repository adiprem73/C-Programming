#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Helper function to calculate required hours at a given speed
long long hoursNeeded(const vector<int>& logFiles, int speed) {
    long long hours = 0;
    for (int size : logFiles) {
        hours += (size + speed - 1) / speed;  // Ceiling division
    }
    return hours;
}

// Function to find the minimum processing speed
int minProcessingSpeed(vector<int>& logFiles, int totalHours) {
    int left = 1, right = *max_element(logFiles.begin(), logFiles.end());
    int result = right;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (hoursNeeded(logFiles, mid) <= totalHours) {
            result = mid;
            right = mid - 1;  // Try to lower the speed
        } else {
            left = mid + 1;   // Increase the speed
        }
    }
    return result;
}

int main() {
    vector<int> logFiles = {120, 180, 240, 60};
    int totalHours = 6;
    
    cout << minProcessingSpeed(logFiles, totalHours) << endl;  // Output: 120
    
    return 0;
}
