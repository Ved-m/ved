#include <iostream>
#include <stack>
#include <queue>
using namespace std;

const int SIZE = 5;
int circularQueue[SIZE]; 
int front = -1, rear = -1;

void enqueue(int value) {
    if ((rear + 1) % SIZE == front) {
        cout << "Queue is full\n";
        return;
    }

    if (front == -1) { // Queue is empty
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }

    circularQueue[rear] = value; 
    cout << "Enqueued " << value << endl;
}

int dequeue() {
    if (front == -1) {
        cout << "Queue is empty\n";
        return -1;
    }

    int value = circularQueue[front]; 
    if (front == rear) { 
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }

    cout << "Dequeued " << value << endl;
    return value;
}

void displayQueue() {
    if (front == -1) {
        cout << "Queue is empty\n";
        return;
    }

    int i = front;
    cout << "Queue elements: ";
    while (i != rear) {
        cout << circularQueue[i] << " "; 
        i = (i + 1) % SIZE;
    }
    cout << circularQueue[i] << endl; 
}


void reverseStack(stack<int>& s) {
    queue<int> q;

    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }
}

void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

// Main function
int main() {
    int choice;

    do {
        cout << "Enter Your Choice: " << endl;
        cout << "1. Implementation of Circular Queue" << endl;
        cout << "2. Reversing Stack using Queue" << endl;
        cout << "3. Exit" << endl;
        cin >> choice;

        switch (choice) {
        case 1: {
            int queueChoice;
            do {
                cout << "1. Enqueue Element" << endl;
                cout << "2. Dequeue Element" << endl;
                cout << "3. Display Queue" << endl;
                cout << "4. Exit to Main Menu" << endl;
                cin >> queueChoice;

                switch (queueChoice) {
                case 1: {
                    int value;
                    cout << "Enter value to enqueue: ";
                    cin >> value;
                    enqueue(value);
                } break;

                case 2:
                    dequeue();
                    break;

                case 3:
                    displayQueue();
                    break;

                case 4:
                    cout << "Exiting to Main Menu" << endl;
                    break;

                default:
                    cout << "Invalid choice! Please select again." << endl;
                }
            } while (queueChoice != 4);
        } break;

        case 2: {
            stack<int> s;
            int stackChoice, value;

            do {
                cout << "1. Push Element to Stack" << endl;
                cout << "2. Reverse Stack" << endl;
                cout << "3. Display Stack" << endl;
                cout << "4. Exit to Main Menu" << endl;
                cin >> stackChoice;

                switch (stackChoice) {
                case 1:
                    cout << "Enter value to push onto stack: ";
                    cin >> value;
                    s.push(value);
                    break;

                case 2:
                    reverseStack(s);
                    cout << "Stack reversed." << endl;
                    break;

                case 3:
                    cout << "Stack elements: ";
                    printStack(s);
                    break;

                case 4:
                    cout << "Exiting to Main Menu" << endl;
                    break;

                default:
                    cout << "Invalid choice! Please select again." << endl;
                }
            } while (stackChoice != 4);
        } break;

        case 3:
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice! Please select again." << endl;
        }
    } while (choice != 3);

    return 0;
}

