#include <iostream>



using namespace std;

const int TABLE_SIZE = 11; // Example table size; you can modify as needed

struct CuckooHashing {
    int table1[TABLE_SIZE];
    int table2[TABLE_SIZE];

    CuckooHashing() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table1[i] = -1;
            table2[i] = -1;
        }
    }

    int hash1(int key) {
        return key % TABLE_SIZE;
    }

    int hash2(int key) {
        return (key / TABLE_SIZE) % TABLE_SIZE;
    }

    bool insert(int key) {
        int pos1 = hash1(key);
        int pos2 = hash2(key);
        int count = 0;
        int currentKey = key;
        int currentTable = 1;

        while (count < TABLE_SIZE) {
            if (currentTable == 1) {
                if (table1[pos1] == -1) {
                    table1[pos1] = currentKey;
                    return true;
                } else {
                    swap(currentKey, table1[pos1]);
                    currentTable = 2;
                    pos2 = hash2(currentKey);
                }
            } else {
                if (table2[pos2] == -1) {
                    table2[pos2] = currentKey;
                    return true;
                } else {
                    swap(currentKey, table2[pos2]);
                    currentTable = 1;
                    pos1 = hash1(currentKey);
                }
            }
            count++;
        }

        cout << "Cycle detected! Rehashing needed." << endl;
        return false;
    }

    bool search(int key) {
        int pos1 = hash1(key);
        int pos2 = hash2(key);

        if (table1[pos1] == key) return true;
        if (table2[pos2] == key) return true;

        return false;
    }

    bool remove(int key) {
        int pos1 = hash1(key);
        int pos2 = hash2(key);

        if (table1[pos1] == key) {
            table1[pos1] = -1;
            return true;
        }
        if (table2[pos2] == key) {
            table2[pos2] = -1;
            return true;
        }

        return false;
    }

    void display() {
        cout << "Table 1: ";
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (table1[i] != -1)
                cout << table1[i] << " ";
            else
                cout << "- ";
        }
        cout << endl;

        cout << "Table 2: ";
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (table2[i] != -1)
                cout << table2[i] << " ";
            else
                cout << "- ";
        }
        cout << endl;
    }
};

int main() {
    CuckooHashing hashTable;
    int choice, key;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Delete\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                if (hashTable.insert(key))
                    cout << "Inserted successfully.\n";
                else
                    cout << "Failed to insert.\n";
                break;
            case 2:
                cout << "Enter key to search: ";
                cin >> key;
                if (hashTable.search(key))
                    cout << "Key found.\n";
                else
                    cout << "Key not found.\n";
                break;
            case 3:
                cout << "Enter key to delete: ";
                cin >> key;
                if (hashTable.remove(key))
                    cout << "Key deleted.\n";
                else
                    cout << "Key not found.\n";
                break;
            case 4:
                hashTable.display();
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice.\n";
        }
    }

    return 0;
}

