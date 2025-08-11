#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
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
    }

    void insertAtPosition(int position, int data) {
        if (position == 0) {
            insertAtBeginning(data);
            return;
        }

        Node* newNode = new Node(data);
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

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteAtBeginning() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
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
        while (temp->next->next) temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
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
        for (int i = 0; i < position - 1; i++) {
            if (!temp || !temp->next) {
                cout << "Position out of range.\n";
                return;
            }
            temp = temp->next;
        }

        Node* toDelete = temp->next;
        if (!toDelete) {
            cout << "Position out of range.\n";
            return;
        }

        temp->next = toDelete->next;
        delete toDelete;
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
        Node* temp = head;
        cout << "Linked List: ";
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};
int main() {
    LinkedList list;
    int choice, subChoice, data, position;

    while (true) {
        cout << "\n==== Linked List Menu ====\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Display\n";
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
                        list.insertAtBeginning(data);
                        break;
                    case 2:
                        cout << "Enter value to insert at end: ";
                        cin >> data;
                        list.insertAtEnd(data);
                        break;
                    case 3:
                        cout << "Enter position and value to insert: ";
                        cin >> position >> data;
                        list.insertAtPosition(position, data);
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
                        list.deleteAtBeginning();
                        break;
                    case 2:
                        list.deleteAtEnd();
                        break;
                    case 3:
                        cout << "Enter position to delete: ";
                        cin >> position;
                        list.deleteAtPosition(position);
                        break;
                    default:
                        cout << "Invalid deletion choice.\n";
                }
                break;

            case 3:
                cout << "Enter value to search: ";
                cin >> data;
                list.search(data);
                break;

            case 4:
                list.display();
                break;

            case 5:
                cout << "Exiting program.\n";
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
