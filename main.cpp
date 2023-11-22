#include <iostream>
#include <cstring>
Using namespace std;
// Node structure for linked list
struct ContactNode {
char name[100];
char number[20];
ContactNode* next;
};
// Function to insert a contact into the linked list
void addContact(ContactNode*& head, const char* name, const char* number) {
ContactNode* newNode = new ContactNode;
strncpy(newNode->name, name, sizeof(newNode->name) - 1);
newNode->name[sizeof(newNode->name) - 1] = '\0'; // Ensure null-terminated
strncpy(newNode->number, number, sizeof(newNode->number) - 1);
newNode->number[sizeof(newNode->number) - 1] = '\0'; // Ensure nullterminated
newNode->next = head;
head = newNode;
}
// Function to delete a contact from the linked list
void deleteContact(ContactNode*& head, const char* name) {
ContactNode* current = head;
ContactNode* previous = nullptr;
while (current != nullptr && strcmp(current->name, name) != 0) {
previous = current;
current = current->next;
}
if (current != nullptr) {
if (previous != nullptr) {
previous->next = current->next;
} else {
head = current->next;
}
delete current;
} else {
cout << "Contact not found." << endl;
}
}
// Function to display all contacts in alphabetical order
void displayContactsAlphabetical(const ContactNode* head) {
// TODO: Implement alphabetical sorting and display
}
// Function to display all contacts in the linked list
void displayAllContacts(const ContactNode* head) {
const ContactNode* current = head;
while (current != nullptr) {
cout << "Name: " << current->name << ", Number: " << current->number 
<< endl;
current = current->next;
}
}
int main() {
ContactNode* contactList = nullptr;
int choice;
do {
cout << "\nContact Directory\n";
cout << "1. Add Contact\n";
cout << "2. Delete Contact\n";
cout << "3. View All Contacts\n";
cout << "4. View Contacts in Alphabetical Order\n";
cout << "5. Exit\n";
cout << "Enter your choice: ";
cin >> choice;
switch (choice) {
case 1: {
char name[100], number[20];
cout << "Enter Name: ";
cin.ignore(); // Ignore newline character in buffer
cin.getline(name, sizeof(name));
cout << "Enter Number: ";
cin.getline(number, sizeof(number));
addContact(contactList, name, number);
break;
}
case 2: {
char name[100];
cout << "Enter Name: ";
cin.ignore(); // Ignore newline character in buffer
cin.getline(name, sizeof(name));
deleteContact(contactList, name);
break;
}
case 3:
displayAllContacts(contactList);
break;
case 4:
displayContactsAlphabetical(contactList);
break;
case 5:
// TODO: Free allocated memory for the linked list before 
exiting
break;
default:
cout << "Invalid choice. Please enter a valid option." << 
endl;
break;
}
} while (choice != 5);
return 0;
}
