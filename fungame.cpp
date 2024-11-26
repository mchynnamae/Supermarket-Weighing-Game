#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm> // For std::make_heap

using namespace std;

// List of fruits and vegetables
vector<string> items = {
    "Apple", "Banana", "Carrot", "Tomato", "Watermelon", "Cabbage", "Pumpkin", "Grapes", "Lettuce", "Potato"
};

// Function to insert into a Min-Heap
void insertIntoMinHeap(priority_queue<int, vector<int>, greater<int>>& minHeap, int weight) {
    minHeap.push(weight);

    // Randomly select a fruit or vegetable from the list
    srand(time(0));  // Seed the random number generator
    int randomIndex = rand() % items.size();  // Select a random index
    string itemName = items[randomIndex];  // Get the fruit or vegetable name

    cout << "Added " << itemName << " weighing " << weight << "kg to the Min-Heap!" << endl;

    // Display the Min-Heap
    cout << "Min-Heap: ";
    priority_queue<int, vector<int>, greater<int>> tempMinHeap = minHeap;
    while (!tempMinHeap.empty()) {
        cout << tempMinHeap.top() << " ";
        tempMinHeap.pop();
    }
    cout << endl << endl;
}

// Function to delete the root (lightest item) from the Min-Heap
void deleteFromMinHeap(priority_queue<int, vector<int>, greater<int>>& minHeap) {
    if (!minHeap.empty()) {
        int removedItem = minHeap.top();
        minHeap.pop();
        cout << "Removed the lightest item (" << removedItem << "kg) from the Min-Heap!" << endl;

        // Display the Min-Heap
        cout << "Min-Heap: ";
        priority_queue<int, vector<int>, greater<int>> tempMinHeap = minHeap;
        while (!tempMinHeap.empty()) {
            cout << tempMinHeap.top() << " ";
            tempMinHeap.pop();
        }
        cout << endl << endl;
    } else {
        cout << "Min-Heap is empty!" << endl << endl;
    }
}

// Function to heapify a list into a Max-Heap
void heapifyToMaxHeap(vector<int>& arr) {
    // Convert the array into a Max-Heap using make_heap
    make_heap(arr.begin(), arr.end());  // Max-Heap by default

    cout << "Heapifying the scattered weights into a Max-Heap!" << endl;

    // Display the Max-Heap
    cout << "Max-Heap: ";
    for (int weight : arr) {
        cout << weight << " ";
    }
    cout << endl << endl;
}

int main() {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    int choice;
    bool exit = false;

    while (!exit) {
        cout << "Supermarket Weighing Game\n";
        cout << "1. Insert an item into the Min-Heap\n";
        cout << "2. Remove the lightest item from the Min-Heap\n";
        cout << "3. Heapify a random list of weights into a Max-Heap\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Insert an item into Min-Heap
                int weight;
                cout << "Enter the weight of the item (in kg): ";
                cin >> weight;
                insertIntoMinHeap(minHeap, weight);
                break;
            }
            case 2: {
                // Remove the lightest item from Min-Heap
                deleteFromMinHeap(minHeap);
                break;
            }
            case 3: {
                // Heapify a random list of weights into a Max-Heap
                vector<int> randomWeights;
                int n;
                cout << "Enter the number of weights to heapify: ";
                cin >> n;
                cout << "Enter the weights: ";
                for (int i = 0; i < n; ++i) {
                    int weight;
                    cin >> weight;
                    randomWeights.push_back(weight);
                }
                heapifyToMaxHeap(randomWeights);
                break;
            }
            case 4:
                exit = true;
                cout << "Exiting the game. Thank you!" << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }

    return 0;
}
