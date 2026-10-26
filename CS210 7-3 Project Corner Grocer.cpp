// CS210 7-3 Project Corner Grocer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <cctype>
#include <utility>

    using namespace std;

    // Function declarations
    void displayMenu();
    void searchItem(const map<string, int>&itemFrequency);
    void printFrequencies(const map<string, int>&itemFrequency);
    void printHistogram(const map<string, int>&itemFrequency);
    void saveBackup(const map<string, int>&itemFrequency);

    int main() {
        // Store each item and the number of times it appears
        map<string, int> itemFrequency;

        // Open the input file
        ifstream inputFile("CS210_Project_Three_Input_File.txt");

        if (!inputFile.is_open()) {
            cout << "Error: Could not open the input file." << endl;
            cout << "Place CS210_Project_Three_Input_File.txt "
                << "in the project's working directory." << endl;
            return 1;
        }

        // Read the items and count their occurrences
        string item;

        while (getline(inputFile, item)) {
            if (!item.empty()) {
                itemFrequency[item]++;
            }
        }

        inputFile.close();

        if (itemFrequency.empty()) {
            cout << "Error: The input file is empty or contains no items."
                << endl;
            return 1;
        }

        // Create a backup of the item frequencies
        saveBackup(itemFrequency);

        int choice = 0;

        // Continue displaying the menu until the user exits
        while (choice != 4) {
            displayMenu();

            cout << "Enter your choice (1-4): ";

            if (!(cin >> choice)) {
                cout << "Invalid input. Please enter a number." << endl;

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            switch (choice) {
            case 1:
                searchItem(itemFrequency);
                break;

            case 2:
                printFrequencies(itemFrequency);
                break;

            case 3:
                printHistogram(itemFrequency);
                break;

            case 4:
                cout << "Thank you for using the Corner Grocer "
                    << "item-tracking program!" << endl;
                break;

            default:
                cout << "Invalid choice. Please select 1, 2, 3, or 4."
                    << endl;
                break;
            }

            cout << endl;
        }

        return 0;
    }

    // Display the menu
    void displayMenu() {
        cout << "====================================" << endl;
        cout << "       CORNER GROCER TRACKER        " << endl;
        cout << "====================================" << endl;
        cout << "1. Search for an item" << endl;
        cout << "2. Display all item frequencies" << endl;
        cout << "3. Display item histogram" << endl;
        cout << "4. Exit" << endl;
        cout << "====================================" << endl;
    }

    // Option 1: Search for an item
    void searchItem(const map<string, int>&itemFrequency) {
        string item;

        cout << "Enter the item you wish to search for: ";
        cin >> item;

        auto it = itemFrequency.find(item);

        if (it != itemFrequency.end()) {
            cout << item << " was purchased "
                << it->second << " time(s)." << endl;
        }
        else {
            cout << item << " was not found in the records." << endl;
        }
    }

    // Option 2: Display the frequency of each item
    void printFrequencies(const map<string, int>&itemFrequency) {
        cout << "\nITEM FREQUENCIES" << endl;
        cout << "--------------------" << endl;

        for (const auto& entry : itemFrequency) {
            cout << entry.first << " "
                << entry.second << endl;
        }
    }

    // Option 3: Display the histogram
    void printHistogram(const map<string, int>&itemFrequency) {
        cout << "\nITEM HISTOGRAM" << endl;
        cout << "--------------------" << endl;

        for (const auto& entry : itemFrequency) {
            cout << entry.first << " ";

            for (int i = 0; i < entry.second; i++) {
                cout << "*";
            }

            cout << endl;
        }
    }

    // Save the frequencies to frequency.dat
    void saveBackup(const map<string, int>&itemFrequency) {
        ofstream outputFile("frequency.dat");

        if (!outputFile.is_open()) {
            cout << "Warning: Could not create frequency.dat." << endl;
            return;
        }

        for (const auto& entry : itemFrequency) {
            outputFile << entry.first << " "
                << entry.second << endl;
        }

        outputFile.close();
    }


    void saveBackup(const map<string, int>& itemFrequency)
    {
        ofstream outputFile("frequency.dat");

        if (!outputFile.is_open()) {
            cout << "Warning: Could not create frequency.dat." << endl;
            return;
        }

        for (const auto& entry : itemFrequency) {
            outputFile << entry.first << " "
                << entry.second << endl;
        }

        outputFile.close();

        cout << "Backup saved to frequency.dat." << endl;
    }
