#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Contact {
    string name;
    string phoneNumber;
    string emailAddress;
};

class ContactManager {
private:
    vector<Contact> contacts;

public:
    void addContact(const Contact& contact) {
        contacts.push_back(contact);
        cout << "Contact added successfully!\n";
    }

    void viewContacts() {
        if (contacts.empty()) {
            cout << "No contacts available.\n";
            return;
        }

        cout << "Contact List:\n";
        for (const auto& contact : contacts) {
            cout << "Name: " << contact.name << "\n";
            cout << "Phone Number: " << contact.phoneNumber << "\n";
            cout << "Email Address: " << contact.emailAddress << "\n\n";
        }
    }

    void editContact(const string& name) {
        auto it = find_if(contacts.begin(), contacts.end(),
                          [&name](const Contact& contact) {
                              return contact.name == name;
                          });

        if (it != contacts.end()) {
            cout << "Enter new information for the contact:\n";
            cout << "New Name: ";
            cin.ignore();
            getline(cin, it->name);
            cout << "New Phone Number: ";
            getline(cin, it->phoneNumber);
            cout << "New Email Address: ";
            getline(cin, it->emailAddress);
            cout << "Contact updated successfully!\n";
        } else {
            cout << "Contact not found.\n";
        }
    }

    void deleteContact(const string& name) {
        auto it = remove_if(contacts.begin(), contacts.end(),
                            [&name](const Contact& contact) {
                                return contact.name == name;
                            });

        if (it != contacts.end()) {
            contacts.erase(it, contacts.end());
            cout << "Contact deleted successfully!\n";
        } else {
            cout << "Contact not found.\n";
        }
    }
};

int main() {
    ContactManager contactManager;
    int choice;

    do {
        cout << "\nContact Management System\n";
        cout << "1. Add Contact\n";
        cout << "2. View Contacts\n";
        cout << "3. Edit Contact\n";
        cout << "4. Delete Contact\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Contact newContact;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, newContact.name);
                cout << "Enter Phone Number: ";
                getline(cin, newContact.phoneNumber);
                cout << "Enter Email Address: ";
                getline(cin, newContact.emailAddress);
                contactManager.addContact(newContact);
                break;
            }
            case 2:
                contactManager.viewContacts();
                break;
            case 3: {
                string editName;
                cout << "Enter the name of the contact to edit: ";
                cin.ignore();
                getline(cin, editName);
                contactManager.editContact(editName);
                break;
            }
            case 4: {
                string deleteName;
                cout << "Enter the name of the contact to delete: ";
                cin.ignore();
                getline(cin, deleteName);
                contactManager.deleteContact(deleteName);
                break;
            }
            case 0:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
