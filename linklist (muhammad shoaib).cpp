#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void insertAtStart(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void insertAtPoint(int position, int data) {
        if (position == 0) {
            insertAtStart(data);
            return;
        }

        Node* newNode = new Node(data);
        Node* current = head;
        for (int i = 0; i < position - 1 && current != NULL; ++i) {
            current = current->next;
        }

        if (current == NULL) {
            cout << "Position out of bounds." << endl;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    void deleteFromStart() {
        if (head == NULL) {
            cout << "List is empty. Cannot delete from the beginning." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteFromEnd() {
        if (head == NULL) {
            cout << "List is empty. Cannot delete from the end." << endl;
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node* current = head;
        while (current->next->next != NULL) {
            current = current->next;
        }
        delete current->next;
        current->next = NULL;
    }

    void deleteAtPoint(int position) {
        if (head == NULL) {
            cout << "List is empty. Cannot delete from the position." << endl;
            return;
        }
        if (position == 0) {
            deleteFromStart();
            return;
        }
        Node* current = head;
        for (int i = 0; i < position - 1; ++i) {
            if (current == NULL || current->next == NULL) {
                cout << "Position out of bounds." << endl;
                return;
            }
            current = current->next;
        }
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    void search(int searchData) {
        Node* current = head;
        while (current != NULL) {
            if (current->data == searchData) {
                cout << "Data found: " << current->data << endl;
                return;
            }
            current = current->next;
        }
        cout << "Data not found." << endl;
    }

    void update(int searchData, int newData) {
        Node* current = head;
        while (current != NULL) {
            if (current->data == searchData) {
                current->data = newData;
                cout << "Data updated successfully." << endl;
                return;
            }
            current = current->next;
        }
        cout << "Data not found." << endl;
    }

    void display() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void menu() {
        int choice, position, data;
        while (true) {
            cout << "\nLinked List Operations:\n";
            cout << "1. Insert at beginning\n";
            cout << "2. Insert at position\n";
            cout << "3. Delete from beginning\n";
            cout << "4. Delete from end\n";
            cout << "5. Delete from position\n";
            cout << "6. Display list\n";
            cout << "7. Search\n";
            cout << "8. Update\n";
            cout << "9. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter data to insert at beginning: ";
                    cin >> data;
                    insertAtStart(data);
                    break;
                case 2:
                    cout << "Enter position to insert data: ";
                    cin >> position;
                    cout << "Enter data to insert at position " << position << ": ";
                    cin >> data;
                    insertAtPoint(position, data);
                    break;
                case 3:
                    deleteFromStart();
                    break;
                case 4:
                    deleteFromEnd();
                    break;
                case 5:
                    cout << "Enter position to delete data: ";
                    cin >> position;
                    deleteAtPoint(position);
                    break;
                case 6:
                    cout << "Linked List: ";
                    display();
                    break;
                case 7:
                    cout << "Enter number to search: ";
                    cin >> data;
                    search(data);
                    break;
                case 8:
                    cout << "Enter number to update: ";
                    cin >> data;
                    cout << "Enter new data: ";
                    cin >> position;
                    update(data, position);
                    break;
                case 9:
                    cout << "Exiting program...\n";
                    exit(0);
                default:
                    cout << "Invalid choice! Please enter a valid option.\n";
            }
        }
    }
};

int main() {
    LinkedList list;
    list.insertAtStart(5);
    list.insertAtStart(10);
    list.insertAtStart(15);
    list.insertAtStart(20);
    list.insertAtStart(25);

    list.menu();
    return 0;
}
