#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

// Function to display the menu and get user choice
int getUserChoice(const string category[], const string itemCode[], const string description[], const double price[], int itemCount) {
    cout << "Choose one item from the following categories:" << endl;

    // Display the menu
    for (int i = 0; i < itemCount; ++i) {
        cout << i + 1 << ". " << category[i] << ": " << itemCode[i] << " - " << description[i] << " ($" << price[i] << ")" << endl;
    }

    // Get user choice
    int choice;
    cout << "Enter the number corresponding to your choice (or 0 to skip): ";
    cin >> choice;

    // Validate user input
    while (choice < 0 || choice > itemCount) {
        cout << "Invalid choice. Please enter a number between 0 and " << itemCount << ": ";
        cin >> choice;
    }

    return choice - 1; // Adjust for 0-based indexing
}

int main() {
    const int itemCount = 15;
    string category[itemCount] = {"Case", "Case", "RAM", "RAM", "RAM", "Main Hard Disk Drive", "Main Hard Disk Drive", "Main Hard Disk Drive", "Solid State Drive", "Solid State Drive", "Second Hard Disk Drive", "Second Hard Disk Drive", "Second Hard Disk Drive", "Optical Drive", "Optical Drive"};
    string itemCode[itemCount] = {"A1", "A2", "B1", "B2", "B3", "C1", "C2", "C3", "D1", "D2", "E1", "E2", "E3", "F1", "F2"};
    string description[itemCount] = {"Compact", "Tower", "8 GB", "16 GB", "32 GB", "1 TB HDD", "2 TB HDD", "4 TB HDD", "240 GB SSD", "480 GB SSD", "1 TB HDD", "2 TB HDD", "4 TB HDD", "DVD/Blu-Ray Player", "DVD/Blu-Ray Re-writer"};
    double price[itemCount] = {75.00, 150.00, 79.99, 149.99, 299.99, 49.99, 89.99, 129.99, 59.99, 119.99, 49.99, 89.99, 129.99, 50.00, 100.00};

    const double basicSetPrice = 200.00;
    const int requiredItemsCount = 3;

    // Initialize variables to store user choices
    string chosenCase, chosenRAM, chosenHDD;
    double totalPrice = basicSetPrice;

    // Get user choices for case, RAM, and HDD
    cout << "Welcome to the Online Computer Shop!" << endl;

    cout << "\nSelect a case:" << endl;
    int caseIndex = getUserChoice(category, itemCode, description, price, itemCount);
    chosenCase = itemCode[caseIndex];
    totalPrice += price[caseIndex];

    cout << "\nSelect RAM:" << endl;
    int ramIndex = getUserChoice(category, itemCode, description, price, itemCount);
    chosenRAM = itemCode[ramIndex];
    totalPrice += price[ramIndex];

    cout << "\nSelect Main Hard Disk Drive:" << endl;
    int hddIndex = getUserChoice(category, itemCode, description, price, itemCount);
    chosenHDD = itemCode[hddIndex];
    totalPrice += price[hddIndex];

    
    cout << "\nDo you want to purchase additional items from other categories? (y/n): ";
    char additionalItemsChoice;
    cin >> additionalItemsChoice;

    vector<string> additionalItems;
    double additionalItemsPrice = 0.0;

   
    if (additionalItemsChoice == 'y' || additionalItemsChoice == 'Y') {
        int additionalItemsCount;
        cout << "Enter the number of additional items you want to purchase: ";
        cin >> additionalItemsCount;

        for (int i = 0; i < additionalItemsCount; ++i) {
            int additionalItemIndex = getUserChoice(category, itemCode, description, price, itemCount);
            additionalItems.push_back(itemCode[additionalItemIndex]);
            additionalItemsPrice += price[additionalItemIndex];
        }

        totalPrice += additionalItemsPrice;
    }

    
    double discount = 0.0;
    if (additionalItems.size() == 1) {
        discount = 0.05; // 5% discount for one additional item
    } else if (additionalItems.size() >= 2) {
        discount = 0.10; // 10% discount for two or more additional items
    }

    double discountAmount = totalPrice * discount;
    double discountedPrice = totalPrice - discountAmount;

   
    cout << "\nChosen Items:" << endl;
    cout << "Case: " << chosenCase << endl;
    cout << "RAM: " << chosenRAM << endl;
    cout << "Main Hard Disk Drive: " << chosenHDD << endl;

    if (!additionalItems.empty()) {
        cout << "\nAdditional Items:" << endl;
        for (const string& item : additionalItems) {
            cout << item << endl;
        }
    }

    cout << fixed << setprecision(2);
    cout << "\nTotal Price: $" << totalPrice << endl;

   
    if (discount > 0.0) {
        cout << "\nDiscount Applied:" << endl;
        cout << "Discount Amount: $" << discountAmount << endl;
        cout << "Discounted Price: $" << discountedPrice << endl;
    }

    return 0;
}
