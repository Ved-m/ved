#include <iostream>
using namespace std;

// Node structure for the AVL Tree
struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};

int height(Node* node) {
    if (node == NULL) {
        return 0;
    } else {
        return node->height;
    }
}


// Function to create a new node
Node* createNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

// Function to update the height of a node
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Right rotate
Node* rightRotate(Node* root) {
    Node* newRoot = root->left;
    Node* subtree = newRoot->right;

    newRoot->right = root;
    root->left = subtree;

    root->height = max(height(root->left), height(root->right)) + 1;
    newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;

    return newRoot;
}

// Left rotate
Node* leftRotate(Node* root) {
    Node* newRoot = root->right;
    Node* subtree = newRoot->left;

    newRoot->left = root;
    root->right = subtree;

    root->height = max(height(root->left), height(root->right)) + 1;
    newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;

    return newRoot;
}

int getBalance(Node* node) {
    if (node == NULL) {
        return 0;
    } else {
        return height(node->left) - height(node->right);
    }
}


// Function to find the minimum node in a subtree
Node* findMinNode(Node* node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}

// Function to insert a node into the AVL tree
Node* insertNode(Node* node, int data) {
    if (!node) return createNode(data);

    if (data < node->data)
        node->left = insertNode(node->left, data);
    else if (data > node->data)
        node->right = insertNode(node->right, data);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Function to delete a node from the AVL tree
Node* deleteNode(Node* root, int data) {
    if (!root) return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
    	//Node with one child or no child
        if ((root->left == NULL) || (root->right == NULL)) {
            Node* temp = root->left ? root->left : root->right;

			//no child
            if (!temp) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;

            delete temp;
        } else {
        	//Node with 2 children
            Node* temp = findMinNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (!root) return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Function to display nodes with even values (in-order traversal)
void displayEvenNodes(Node* root) {
    if (!root) return;

    displayEvenNodes(root->left);

    if (root->data % 2 == 0)
        cout << root->data << " ";

    displayEvenNodes(root->right);
}

// Function to display the tree (in-order traversal)
void displayTree(Node* root) {
    if (!root) return;

    displayTree(root->left);
    cout << root->data << " ";
    displayTree(root->right);
}

// Main menu-driven program
int main() {
    Node* root = NULL;
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert a node\n";
        cout << "2. Delete a node\n";
        cout << "3. Display even nodes\n";
        cout << "4. Display the tree\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                root = insertNode(root, value);
                cout << "Node with value " << value << " inserted.\n";
                break;
            case 2:
                cout << "Enter the value to delete: ";
                cin >> value;
                root = deleteNode(root, value);
                cout << "Node with value " << value << " deleted (if it existed).\n";
                break;
            case 3:
                cout << "Even numbers in the AVL Tree: ";
                displayEvenNodes(root);
                cout << endl;
                break;
            case 4:
                cout << "AVL Tree (In-Order Traversal): ";
                displayTree(root);
                cout << endl;
                break;
            case 5:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}

