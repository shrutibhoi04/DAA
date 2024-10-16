#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to perform Branch and Bound for TSP
void tsp(int city, int cost, int visitedCount, vector<vector<int>> &costMatrix, vector<bool> &visited, int &minCost, vector<int> &currentPath, vector<int> &bestPath, int numCities) {
    if (visitedCount == numCities && costMatrix[city][0] != 0) {
        // Add cost to return to the starting city and update minCost if necessary
        int totalCost = cost + costMatrix[city][0];
        if (totalCost < minCost) {
            minCost = totalCost;
            bestPath = currentPath; // Update the best path
            bestPath.push_back(0);  // Return to the starting city
        }
        return;
    }

    // Explore all possible next cities
    for (int nextCity = 0; nextCity < numCities; nextCity++) {
        if (!visited[nextCity] && costMatrix[city][nextCity] != 0) {
            visited[nextCity] = true;
            currentPath.push_back(nextCity);  // Add city to current path

            tsp(nextCity, cost + costMatrix[city][nextCity], visitedCount + 1, costMatrix, visited, minCost, currentPath, bestPath, numCities);

            currentPath.pop_back(); // Backtrack
            visited[nextCity] = false;
        }
    }
}

int main() {
    int numCities;
    cout << "Enter the number of cities: ";
    cin >> numCities;

    vector<vector<int>> costMatrix(numCities, vector<int>(numCities));
    cout << "Enter the cost matrix:\n";
    for (int i = 0; i < numCities; i++) {
        for (int j = 0; j < numCities; j++) {
            cin >> costMatrix[i][j];
        }
    }

    vector<bool> visited(numCities, false);  // Track visited cities
    visited[0] = true;  // Start at city 0
    int minCost = INT_MAX;  // Initialize minimum cost
    vector<int> currentPath = {0};  // Path starts at city 0
    vector<int> bestPath;  // Store the best path

    // Start the TSP algorithm
    tsp(0, 0, 1, costMatrix, visited, minCost, currentPath, bestPath, numCities);

    // Output the result
    cout << "Minimum cost: " << minCost << endl;
    cout << "Best path: ";
    for (int city : bestPath) {
        cout << city << " ";
    }
    cout << endl;

    return 0;
}
