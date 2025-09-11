#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Insert at head
void insertAtHead(Node* &head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

// Insert at tail
void insertAtTail(Node* &head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert at specific position (1-based index)
void insertAtPosition(Node* &head, int pos, int val) {
    if (pos == 1) {
        insertAtHead(head, val);
        return;
    }
    Node* newNode = new Node(val);
    Node* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Position out of range!" << endl;
        delete newNode;
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete by value
void deleteByValue(Node* &head, int val) {
    if (head == NULL) return;

    if (head->data == val) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->data != val) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        cout << "Value not found!" << endl;
        return;
    }
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

// Delete at position (1-based index)
void deleteAtPosition(Node* &head, int pos) {
    if (head == NULL) return;

    if (pos == 1) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }

    Node* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        cout << "Position out of range!" << endl;
        return;
    }

    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

// Search value
bool search(Node* head, int key) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) return true;
        temp = temp->next;
    }
    return false;
}

// Find length of list
int length(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Print list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    // Insert operations
    insertAtHead(head, 10);
    insertAtHead(head, 20);
    insertAtTail(head, 30);
    insertAtPosition(head, 2, 25);

    cout << "List after insertions: ";
    printList(head); // 20 25 10 30

    // Delete operations
    deleteByValue(head, 25);
    cout << "After deleting 25: ";
    printList(head); // 20 10 30

    deleteAtPosition(head, 2);
    cout << "After deleting position 2: ";
    printList(head); // 20 30

    // Search
    cout << "Search 30: " << (search(head, 30) ? "Found" : "Not Found") << endl;
    cout << "Search 40: " << (search(head, 40) ? "Found" : "Not Found") << endl;

    // Length
    cout << "Length of list: " << length(head) << endl;

    return 0;
}
