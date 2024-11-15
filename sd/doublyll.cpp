#include <iostream>
using namespace std;

// Node structure for the doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Function to insert a node at the end of the list
void insertNode(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    cout << "Node with value " << value << " inserted.\n";
}

// Function to display nodes with even values
void displayEvenNodes(Node* head) {
    Node* temp = head;
    bool foundEven = false;
    cout << "Even numbers in the list: ";
    while (temp != NULL) {
        if (temp->data % 2 == 0) {
            cout << temp->data << " ";
            foundEven = true;
        }
        temp = temp->next;
    }
    if (!foundEven) {
        cout << "No even numbers found in the list.";
    }
    cout << endl;
}

// Function to display all nodes in the list
void displayList(Node* head) {
    Node* temp = head;
    cout << "Doubly Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Main menu-driven program
int main() {
    Node* head = NULL;
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert a node\n";
        cout << "2. Display even nodes\n";
        cout << "3. Display the list\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                insertNode(head, value);
                break;
            case 2:
                displayEvenNodes(head);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}

