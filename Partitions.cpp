   #include<iostream>
using namespace std;

// Function to print an array
void printArray(int p[], int n) {
    for (int i = 0; i < n; i++) {
        cout << p[i] << "  ";
    }
    cout << endl;
}

// Function to find partitions of a number
void findPartitions(int n) {
    int p[n], x = 0, num = 0; // Initializing variables

    p[x] = n; // Initializing the first element

    while (true) {
        int e = 1; // Counter for partition numbers
        cout << e << ".   ";
        printArray(p, x + 1); // Print the partition
        num = num + 1; // Count the number of partitions

        int remainingValues = 0;
        // Find the next partition
        while (x >= 0 && p[x] == 1) {
            remainingValues = remainingValues + 1;
            x = x - 1;
        }

        if (x < 0) {
            cout << "\n\nThe number of partitions of " << n << " are " << num;
            return; // Exit the function
        }

        p[x] = p[x] - 1;

        remainingValues = remainingValues + 1;

        while (remainingValues > p[x]) {
            p[x + 1] = p[x];
            remainingValues = remainingValues - p[x];
            x = x + 1;
        }
        p[x + 1] = remainingValues;

        x = x + 1;
    }
}

int main() {
    int x;
    cout << "Enter the number whose partitions you want to find : ";
    cin >> x;
    system("CLS");
    cout << "All Partitions of " << x << "\n\n";
    findPartitions(x);
    return 0;
}

