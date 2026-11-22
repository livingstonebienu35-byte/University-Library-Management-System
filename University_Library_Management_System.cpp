#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Structure of a book (Doubly Linked List Node)
struct Node {
    int bookID;
    string title;
    string author;

    Node* next;
    Node* prev;
};

class Library {
private:
    Node* head;
    Node* tail;

public:
    // Constructor
    Library() {
        head = NULL;
        tail = NULL;
    }

    // Add Book
    void addBook() {
        Node* newBook = new Node;

        cout << "\nEnter Book ID: ";
        cin >> newBook->bookID;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter Book Title: ";
        getline(cin, newBook->title);

        cout << "Enter Author Name: ";
        getline(cin, newBook->author);

        newBook->next = NULL;
        newBook->prev = NULL;

        if (head == NULL) {
            head = tail = newBook;
        }
        else {
            tail->next = newBook;
            newBook->prev = tail;
            tail = newBook;
        }

        cout << "\nBook added successfully!\n";
    }

    // Remove Book
    void removeBook() {
        int id;

        cout << "\nEnter Book ID to remove: ";
        cin >> id;

        Node* temp = head;

        while (temp != NULL && temp->bookID != id) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "\nBook not found!\n";
            return;
        }

        if (temp == head) {
            head = temp->next;
        }

        if (temp == tail) {
            tail = temp->prev;
        }

        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        }

        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }

        delete temp;

        cout << "\nBook removed successfully!\n";
    }

    // Search Book
    void searchBook() {
        int id;

        cout << "\nEnter Book ID to search: ";
        cin >> id;

        Node* temp = head;

        while (temp != NULL) {
            if (temp->bookID == id) {
                cout << "\nBook Found!\n";
                cout << "Book ID: " << temp->bookID << endl;
                cout << "Title: " << temp->title << endl;
                cout << "Author: " << temp->author << endl;
                return;
            }

            temp = temp->next;
        }

        cout << "\nBook not found!\n";
    }

    // Display Books Forward
    void displayForward() {
        if (head == NULL) {
            cout << "\nLibrary is empty!\n";
            return;
        }

        Node* temp = head;

        cout << "\n===== BOOKS FORWARD =====\n";

        while (temp != NULL) {
            cout << "\nBook ID: " << temp->bookID;
            cout << "\nTitle: " << temp->title;
            cout << "\nAuthor: " << temp->author << endl;

            temp = temp->next;
        }
    }

    // Display Books Backward
    void displayBackward() {
        if (tail == NULL) {
            cout << "\nLibrary is empty!\n";
            return;
        }

        Node* temp = tail;

        cout << "\n===== BOOKS BACKWARD =====\n";

        while (temp != NULL) {
            cout << "\nBook ID: " << temp->bookID;
            cout << "\nTitle: " << temp->title;
            cout << "\nAuthor: " << temp->author << endl;

            temp = temp->prev;
        }
    }

    // Update Book Details
    void updateBook() {
        int id;

        cout << "\nEnter Book ID to update: ";
        cin >> id;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        Node* temp = head;

        while (temp != NULL && temp->bookID != id) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "\nBook not found!\n";
            return;
        }

        cout << "\nEnter New Book Title: ";
        getline(cin, temp->title);

        cout << "Enter New Author Name: ";
        getline(cin, temp->author);

        cout << "\nBook details updated successfully!\n";
    }

    // Main Menu
    void menu() {
        int choice;

        do {
            cout << "\n\n================================";
            cout << "\n UNIVERSITY LIBRARY MANAGEMENT SYSTEM";
            cout << "\n================================";
            cout << "\n1. Add Book";
            cout << "\n2. Remove Book";
            cout << "\n3. Search Book";
            cout << "\n4. Display Books Forward";
            cout << "\n5. Display Books Backward";
            cout << "\n6. Update Book Details";
            cout << "\n7. Exit";
            cout << "\n================================";
            cout << "\nEnter your choice: ";

            if (!(cin >> choice)) {
                cout << "\nInvalid input! Enter a number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            switch (choice) {
                case 1:
                    addBook();
                    break;

                case 2:
                    removeBook();
                    break;

                case 3:
                    searchBook();
                    break;

                case 4:
                    displayForward();
                    break;

                case 5:
                    displayBackward();
                    break;

                case 6:
                    updateBook();
                    break;

                case 7:
                    cout << "\nThank you for using the Library System!\n";
                    break;

                default:
                    cout << "\nInvalid choice! Try again.\n";
            }

        } while (choice != 7);
    }

    // Destructor
    ~Library() {
        Node* temp;

        while (head != NULL) {
            temp = head;
            head = head->next;
            delete temp;
        }

        tail = NULL;
    }
};

// Main Function
int main() {
    Library library;

    library.menu();

    return 0;
}
