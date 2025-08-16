#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        if (head) {
            newNode->next = head;
            head->prev = newNode;
        }
        head = newNode;
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAtPosition(int position, int data) {
        if (position == 0) {
            insertAtBeginning(data);
            return;
        }
        Node* temp = head;
        for (int i = 0; i < position - 1; i++) {
            if (!temp) {
                cout << "Position out of range.\n";
                return;
            }
            temp = temp->next;
        }
        if (!temp) {
            cout << "Position out of range.\n";
            return;
        }
        Node* newNode = new Node(data);
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next) temp->next->prev = newNode;
        temp->next = newNode;
    }

    void deleteAtBeginning() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        delete temp;
    }

    void deleteAtEnd() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->prev->next = nullptr;
        delete temp;
    }

    void deleteAtPosition(int position) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        if (position == 0) {
            deleteAtBeginning();
            return;
        }
        Node* temp = head;
        for (int i = 0; i < position; i++) {
            if (!temp) {
                cout << "Position out of range.\n";
                return;
            }
            temp = temp->next;
        }
        if (!temp) {
            cout << "Position out of range.\n";
            return;
        }
        if (temp->prev) temp->prev->next = temp->next;
        if (temp->next) temp->next->prev = temp->prev;
        delete temp;
    }

    void search(int key) {
        Node* temp = head;
        int index = 0;
        while (temp) {
            if (temp->data == key) {
                cout << "Element " << key << " found at position " << index << ".\n";
                return;
            }
            temp = temp->next;
            index++;
        }
        cout << "Element not found.\n";
    }

    void display() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }

        // Forward display
        cout << "Forward: ";
        Node* temp = head;
        Node* last = nullptr;
        while (temp) {
            cout << temp->data << " <-> ";
            last = temp;
            temp = temp->next;
        }
        cout << "NULL\n";

        // Backward display
        cout << "Backward: ";
        while (last) {
            cout << last->data << " <-> ";
            last = last->prev;
        }
        cout << "NULL\n";
    }
};

int main() {
    DoublyLinkedList dll;
    int choice, subChoice, data, position;

    while (true) {
        cout << "\n==== Doubly Linked List Menu ====\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Display (Forward & Backward)\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\n-- Insertion Menu --\n";
                cout << "1. Insert at beginning\n";
                cout << "2. Insert at end\n";
                cout << "3. Insert at position\n";
                cout << "Enter your insertion choice: ";
                cin >> subChoice;

                switch (subChoice) {
                    case 1:
                        cout << "Enter value to insert at beginning: ";
                        cin >> data;
                        dll.insertAtBeginning(data);
                        break;
                    case 2:
                        cout << "Enter value to insert at end: ";
                        cin >> data;
                        dll.insertAtEnd(data);
                        break;
                    case 3:
                        cout << "Enter position and value to insert: ";
                        cin >> position >> data;
                        dll.insertAtPosition(position, data);
                        break;
                    default:
                        cout << "Invalid insertion choice.\n";
                }
                break;

            case 2:
                cout << "\n-- Deletion Menu --\n";
                cout << "1. Delete at beginning\n";
                cout << "2. Delete at end\n";
                cout << "3. Delete at position\n";
                cout << "Enter your deletion choice: ";
                cin >> subChoice;

                switch (subChoice) {
                    case 1:
                        dll.deleteAtBeginning();
                        break;
                    case 2:
                        dll.deleteAtEnd();
                        break;
                    case 3:
                        cout << "Enter position to delete: ";
                        cin >> position;
                        dll.deleteAtPosition(position);
                        break;
                    default:
                        cout << "Invalid deletion choice.\n";
                }
                break;

            case 3:
                cout << "Enter value to search: ";
                cin >> data;
                dll.search(data);
                break;

            case 4:
                dll.display();
                break;

            case 5:
                cout << "Exiting program.\n";
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
