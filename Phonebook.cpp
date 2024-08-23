#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct Contact {
    string name;
    string phoneNumber;
    string emailAddress;
};

vector<Contact> contactList;

void addContact() {
    Contact newContact;
    cout << "Enter name: ";
    getline(cin, newContact.name);
    cout << "Enter phone number: ";
    getline(cin, newContact.phoneNumber);
    cout << "Enter email address: ";
    getline(cin, newContact.emailAddress);
    contactList.push_back(newContact);
    cout << "Contact added successfully!" << endl;
}

void viewContacts() {
    cout << "Contact List:" << endl;
    for (int i = 0; i < contactList.size(); i++) {
        cout << "Name: " << contactList[i].name << endl;
        cout << "Phone Number: " << contactList[i].phoneNumber << endl;
        cout << "Email Address: " << contactList[i].emailAddress << endl;
        cout << "------------------------" << endl;
    }
}

void editContact() {
    int contactIndex;
    cout << "Enter the index of the contact to edit (1-" << contactList.size() << "): ";
    cin >> contactIndex;
    contactIndex--; // adjust for 0-based indexing
    if (contactIndex >= 0 && contactIndex < contactList.size()) {
        cout << "Enter new name: ";
        getline(cin, contactList[contactIndex].name);
        cout << "Enter new phone number: ";
        getline(cin, contactList[contactIndex].phoneNumber);
        cout << "Enter new email address: ";
        getline(cin, contactList[contactIndex].emailAddress);
        cout << "Contact updated successfully!" << endl;
    } else {
        cout << "Invalid contact index." << endl;
    }
}

void deleteContact() {
    int contactIndex;
    cout << "Enter the index of the contact to delete (1-" << contactList.size() << "): ";
    cin >> contactIndex;
    contactIndex--; // adjust for 0-based indexing
    if (contactIndex >= 0 && contactIndex < contactList.size()) {
        contactList.erase(contactList.begin() + contactIndex);
        cout << "Contact deleted successfully!" << endl;
    } else {
        cout << "Invalid contact index." << endl;
    }
}

void saveContactsToFile() {
    ofstream file("contacts.txt");
    if (file.is_open()) {
        for (int i = 0; i < contactList.size(); i++) {
            file << contactList[i].name << "," << contactList[i].phoneNumber << "," << contactList[i].emailAddress << endl;
        }
        file.close();
        cout << "Contacts saved to file successfully!" << endl;
    } else {
        cout << "Unable to open file for writing." << endl;
    }
}

void loadContactsFromFile() {
    ifstream file("contacts.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            size_t comma1 = line.find(",");
            size_t comma2 = line.find(",", comma1 + 1);
            Contact newContact;
            newContact.name = line.substr(0, comma1);
            newContact.phoneNumber = line.substr(comma1 + 1, comma2 - comma1 - 1);
            newContact.emailAddress = line.substr(comma2 + 1);
            contactList.push_back(newContact);
        }
        file.close();
        cout << "Contacts loaded from file successfully!" << endl;
    } else {
        cout << "Unable to open file for reading." << endl;
    }
}

int main() {
    loadContactsFromFile();
    int choice;
    do {
        cout << "Contact Management System" << endl;
        cout << "------------------------" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. View Contacts" << endl;
        cout << "3. Edit Contact" << endl;
        cout << "4. Delete Contact" << endl;
        cout << "5. Save Contacts to File" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                viewContacts();
                break;
            case 3:
                editContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                saveContactsToFile();
                break;
            case 6:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice!= 6);
    return 0;
}