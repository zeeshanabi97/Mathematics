#include<iostream>
using namespace std;

// Function to print an array
void printArray(int p[], int n) {
    // Iterate through the array and print each element
    for (int i = 0; i < n; i++) {
        cout << p[i] << "  ";
    }
    cout << endl; // Move to the next line after printing the array
}

// Function to find partitions of a number
void findPartitions(int n) {
    int p[n], x = 0, num = 0; // Initializing variables

    p[x] = n; // Initializing the first element of the partition array

    while (true) {
        printArray(p, x + 1); // Print the current partition
        num = num + 1; // Count the number of partitions

        int remainingValues = 0;
        // Find the next partition
        while (x >= 0 && p[x] == 1) {
            remainingValues = remainingValues + 1; // Count the 1s in the partition
            x = x - 1; // Move to the previous element
        }

        if (x < 0) {
            // If no more partitions can be found, print the total count of partitions and exit the function
            cout << "\n\nThe number of partitions of " << n << " are " << num;
            return; // Exit the function
        }

        // Adjust the current partition
        p[x] = p[x] - 1; // Decrease the current value by 1

        remainingValues = remainingValues + 1; // Include the 1s in the remaining values

        // Adjust the partition array based on remaining values
        while (remainingValues > p[x]) {
            p[x + 1] = p[x]; // Set the next element to the current element value
            remainingValues = remainingValues - p[x]; // Adjust the remaining values
            x = x + 1; // Move to the next element
        }
        p[x + 1] = remainingValues; // Set the next element to the remaining values

        x = x + 1; // Move to the next element for further partitioning
    }
}

// The main function for user input and program execution
int main() {
    int x;
    // Prompt the user for input
    cout << "Enter the number whose partitions you want to find : ";
    // Accept the input
    cin >> x;
    // Clear the console screen
    system("CLS");
    // Display the message for the entered number
    cout << "All Partitions of " << x << "\n\n";
    // Call the function to find partitions of the entered number
    findPartitions(x);
    return 0; // Return 0 to indicate successful execution
}
