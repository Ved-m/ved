#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


void inorderRecursive(Node* root) {
    if (root == NULL) return;
    inorderRecursive(root->left);
    cout << root->data << " ";
    inorderRecursive(root->right);
}

void preorderRecursive(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorderRecursive(root->left);
    preorderRecursive(root->right);
}

void postorderRecursive(Node* root) {
    if (root == NULL) return;
    postorderRecursive(root->left);
    postorderRecursive(root->right);
    cout << root->data << " ";
}


void inorderNonRecursive(Node* root) {
    stack<Node*> s;
    Node* curr = root;

    while (curr != NULL || !s.empty()) {
        while (curr != NULL) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

void preorderNonRecursive(Node* root) {
    if (root == NULL) return;

    stack<Node*> s;
    s.push(root);

    while (!s.empty()) {
        Node* curr = s.top();
        s.pop();
        cout << curr->data << " ";

        if (curr->right) s.push(curr->right);
        if (curr->left) s.push(curr->left);
    }
}

void postorderNonRecursive(Node* root) {
    if (root == NULL) return;

    stack<Node*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        Node* curr = s1.top();
        s1.pop();
        s2.push(curr);

        if (curr->left) s1.push(curr->left);
        if (curr->right) s1.push(curr->right);
    }

    while (!s2.empty()) {
        Node* curr = s2.top();
        s2.pop();
        cout << curr->data << " ";
    }
}

Node* mirror(Node* root) {
    if (root == NULL) return NULL;

    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);

    return root;
}

int countNodes(Node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void insertNodeDynamic(Node*& root) {
    Node* current = root;
    char direction;
    int val;

    while (true) {
        cout << "You are at node with value: " << current->data << endl;
        cout << "Enter 'l' to go left, 'r' to go right, 'p' to go back to root, 'i' to insert left, 'd' to insert right, 'q' to finish: ";
        cin >> direction;

        switch (direction) {
            case 'l':
                if (current->left != NULL) {
                    current = current->left;
                } else {
                    cout << "Left child is empty. Enter a value to insert on the left: ";
                    cin >> val;
                    current->left = new Node(val);
                }
                break;
            case 'r':
                if (current->right != NULL) {
                    current = current->right;
                } else {
                    cout << "Right child is empty. Enter a value to insert on the right: ";
                    cin >> val;
                    current->right = new Node(val);
                }
                break;
            case 'p':
                current = root;  // go back to root
                break;
            case 'i':
                if (current->left == NULL) {
                    cout << "Enter value to insert on the left: ";
                    cin >> val;
                    current->left = new Node(val);
                } else {
                    cout << "Left child already exists. Try another action." << endl;
                }
                break;
            case 'd':
                if (current->right == NULL) {
                    cout << "Enter value to insert on the right: ";
                    cin >> val;
                    current->right = new Node(val);
                } else {
                    cout << "Right child already exists. Try another action." << endl;
                }
                break;
            case 'q':
                return;  // Exit the insertion loop
            default:
                cout << "Invalid input. Try again." << endl;
        }
    }
}



int main() {
    Node* root = NULL;
    int choice, val;

    cout << "Enter the root node value: ";
    cin >> val;
    root = new Node(val);

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Nodes Dynamically\n";
        cout << "2. Recursive Inorder Traversal\n";
        cout << "3. Recursive Preorder Traversal\n";
        cout << "4. Recursive Postorder Traversal\n";
        cout << "5. Non-Recursive Inorder Traversal\n";
        cout << "6. Non-Recursive Preorder Traversal\n";
        cout << "7. Non-Recursive Postorder Traversal\n";
        cout << "8. Mirror Image of Tree\n";
        cout << "9. Count Nodes in Tree\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
            	insertNodeDynamic(root);
                break;
            case 2:
                cout << "\nRecursive Inorder Traversal: ";
                inorderRecursive(root);
                cout << endl;
                break;
            case 3:
                cout << "\nRecursive Preorder Traversal: ";
                preorderRecursive(root);
                cout << endl;
                break;
            case 4:
                cout << "\nRecursive Postorder Traversal: ";
                postorderRecursive(root);
                cout << endl;
                break;
            case 5:
                cout << "\nNon-Recursive Inorder Traversal: ";
                inorderNonRecursive(root);
                cout << endl;
                break;
            case 6:
                cout << "\nNon-Recursive Preorder Traversal: ";
                preorderNonRecursive(root);
                cout << endl;
                break;
            case 7:
                cout << "\nNon-Recursive Postorder Traversal: ";
                postorderNonRecursive(root);
                cout << endl;
                break;
            case 8:
                root = mirror(root);
                cout << "\nMirror Image Applied. Inorder Traversal: ";
                inorderRecursive(root);
                cout << endl;
                break;
            case 9:
                cout << "\nNumber of nodes in the tree: " << countNodes(root) << endl;
                break;
            case 10:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
                break;
        }
    } while (choice != 10);

    return 0;
}

