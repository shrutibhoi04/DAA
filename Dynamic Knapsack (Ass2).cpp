#include <iostream>
#include <vector>

using namespace std;

// Function to return the maximum of two values
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the 0/1 Knapsack problem using dynamic programming
int knapsack(int weights[], int profits[], int n, int capacity) {
    // Create a 2D array to store the maximum profit values
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Build the dp table in a bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            // If the current item's weight is less than or equal to the current capacity
            if (weights[i - 1] <= w) {
                // Maximize between including the item or excluding it
                dp[i][w] = max(profits[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                // Exclude the item
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Display the dp table (optional for debugging or understanding the process)
    cout << "\nKnapsack Table:\n";
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            cout << dp[i][w] << " ";
        }
        cout << endl;
    }

    // The last cell contains the maximum profit for the given capacity
    return dp[n][capacity];
}

int main() {
    int n, capacity;
    
    // Input the number of items and knapsack capacity
    cout << "Enter the number of items: ";
    cin >> n;
    
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    // Input the weights and profits of each item
    int weights[n], profits[n];
    
    cout << "\nEnter the weights of the items:\n";
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    cout << "\nEnter the profits of the items:\n";
    for (int i = 0; i < n; i++) {
        cin >> profits[i];
    }

    // Calculate the maximum profit using the knapsack function
    int maxProfit = knapsack(weights, profits, n, capacity);

    // Output the result
    cout << "\nMaximum profit is: " << maxProfit << endl;

    return 0;
}
