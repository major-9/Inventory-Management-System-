#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Item {
public:
    int id;
    char name[50];
    int qty;
    float price;
};

// Function to Add Item
void addItem() {
    Item it;
    ofstream fout("inventory.txt", ios::app);

    cout << "Enter Product ID: ";
    cin >> it.id;
    cout << "Enter Product Name: ";
    cin >> it.name;
    cout << "Enter Quantity: ";
    cin >> it.qty;
    cout << "Enter Price: ";
    cin >> it.price;

    fout << it.id << " " << it.name << " " << it.qty << " " << it.price << endl;
    fout.close();

    cout << "Item Added Successfully.\n";
}

// Function to Display Items
void displayItems() {
    Item it;
    ifstream fin("inventory.txt");

    cout << "\n--------------------------------------------------\n";
    cout << left << setw(10) << "ID" << setw(15) << "Name" << setw(10) << "Qty" << "Price\n";
    cout << "--------------------------------------------------\n";

    while (fin >> it.id >> it.name >> it.qty >> it.price) {
        cout << left << setw(10) << it.id << setw(15) << it.name << setw(10) << it.qty << it.price << endl;
    }

    fin.close();
}

// Function to Search Item
void searchItem() {
    Item it;
    int id, found = 0;
    ifstream fin("inventory.txt");

    cout << "Enter Product ID to Search: ";
    cin >> id;

    while (fin >> it.id >> it.name >> it.qty >> it.price) {
        if (it.id == id) {
            cout << "\nItem Found:\n";
            cout << "ID: " << it.id << "\nName: " << it.name << "\nQuantity: " << it.qty << "\nPrice: " << it.price << endl;
            found = 1;
            break;
        }
    }

    fin.close();
    if (!found) cout << "Item Not Found.\n";
}

// Function to Update Item
void updateItem() {
    Item it;
    int id, found = 0;
    ifstream fin("inventory.txt");
    ofstream fout("temp.txt");

    cout << "Enter Product ID to Update: ";
    cin >> id;

    while (fin >> it.id >> it.name >> it.qty >> it.price) {
        if (it.id == id) {
            cout << "Enter New Name: ";
            cin >> it.name;
            cout << "Enter New Quantity: ";
            cin >> it.qty;
            cout << "Enter New Price: ";
            cin >> it.price;
            found = 1;
        }
        fout << it.id << " " << it.name << " " << it.qty << " " << it.price << endl;
    }

    fin.close();
    fout.close();
    remove("inventory.txt");
    rename("temp.txt", "inventory.txt");

    if (found) cout << "Item Updated Successfully.\n";
    else cout << "Item Not Found.\n";
}

// Function to Delete Item
void deleteItem() {
    Item it;
    int id, found = 0;
    ifstream fin("inventory.txt");
    ofstream fout("temp.txt");

    cout << "Enter Product ID to Delete: ";
    cin >> id;

    while (fin >> it.id >> it.name >> it.qty >> it.price) {
        if (it.id != id) {
            fout << it.id << " " << it.name << " " << it.qty << " " << it.price << endl;
        } else {
            found = 1;
        }
    }

    fin.close();
    fout.close();
    remove("inventory.txt");
    rename("temp.txt", "inventory.txt");

    if (found) cout << "Item Deleted Successfully.\n";
    else cout << "Item Not Found.\n";
}

// Main Menu
int main() {
    int choice;
    while (true) {
        cout << "\n----- Inventory Management System -----\n";
        cout << "1. Add Item\n2. Display Items\n3. Search Item\n4. Update Item\n5. Delete Item\n6. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addItem(); break;
            case 2: displayItems(); break;
            case 3: searchItem(); break;
            case 4: updateItem(); break;
            case 5: deleteItem(); break;
            case 6: exit(0);
            default: cout << "Invalid Choice.\n";
        }
    }
}
