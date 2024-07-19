#include <iostream>
#include<cmath>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = nullptr;

// for inserting
void insertAtBeginning();
void insertAtEnd();
void insertAtRandom();
void insertAtMid();

// for deleting
void deleteFromBeginning();
void deleteFromEnd();
void deleteAfterPosition();
void deleteAtMid();

// for searching
void searchElement();
void showList();

// for reverse list
void reverseList();

// additional functions
void getLength();
void findMiddle();


void detectCycle();
void removeCycle();
void sortList();
// void mergeSortedLists(Node* list1, Node* list2);

int main()
{
    int choice;
    while (1)
    {

        cout << "\n\n********* Main Menu *********\n";
        cout << "Choose one option from the following list ...\n";
        cout << "===============================================\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert at any position\n";
        cout << "4. Insert at mid\n";
        cout << "5. Delete from beginning\n";
        cout << "6. Delete from end\n";
        cout << "7. Delete node after specified position\n";
        cout << "8. Delete mid node\n";
        cout << "9. Show list\n";
        cout << "10. Search for an element\n";
        cout << "11. Get Length of Linked List\n";
        cout << "12. Get Middle Node\n";
        cout << "13. Detect Cycle in Linked List\n";
        cout << "16. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            insertAtBeginning();
            break;
        case 2:
            insertAtEnd();
            break;
        case 3:
            insertAtRandom();
            break;
        case 4:
            insertAtMid();
            break;
        case 5:
            deleteFromBeginning();
            break;
        case 6:
            deleteFromEnd();
            break;
        case 7:
            deleteAfterPosition();
            break;
        case 8:
            deleteAtMid();
            break;
        case 9:
            showList();
            break;
        case 10:
            searchElement();
            break;
        case 11:
            getLength();
            break;
        case 12:
            findMiddle();
            break;
        case 13:
            detectCycle();
            break;
        case 16:
            exit(0);
            break;
        default:
            cout << "Enter a valid a choice: ";
        };
    }

    return 0;
}

void insertAtBeginning()
{
    Node *newNode = new Node;

    if (newNode == nullptr)
    {
        cout << "Memory allocation failed\n";
        return;
    }

    int data;
    cout << "Enter element: ";
    cin >> data;

    newNode->data = data;
    newNode->next = head;
    head = newNode;
    cout << "Element Inserted: " << head->data << endl;
}

void insertAtEnd()
{
    Node *newNode = (Node *)malloc(sizeof(struct Node));
    if (newNode == nullptr)
    {
        cout << "Memory allocation failed\n";
        return;
    }

    int data;
    cout << "Enter Element: ";
    cin >> data;

    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
        cout << "Element Inserted: " << head->data << endl;
    }
    else
    {
        Node *ptr = head;
        while (ptr->next != nullptr)
        {
            ptr = ptr->next;
        }

        ptr->next = newNode;
        cout << "Element Inserted: " << ptr->next->data << endl;
    }
}

void insertAtRandom()
{
    int data, position;
    Node *newNode = (Node *)malloc(sizeof(struct Node));

    if (newNode == nullptr)
    {
        cout << "Memory allocation failed\n";
        return;
    }

    cout << "Enter Element: " << endl;
    cin >> data;
    cout << "Enter Position where want to insert: ";
    cin >> position;

    newNode->data = data;

    if (position == 1)
    {
        newNode->next = head;
        head = newNode;
        cout << "Element Inserted at position " << position << ": " << newNode->data << endl;
        return;
    }

    Node *current = head;
    for (int i = 1; current != nullptr && i <= position - 1; i++)
    {
        current = current->next;
    }

    if (current == nullptr)
    {
        cout << "Position out of range\n";
        free(newNode);
    }
    else
    {
        newNode->next = current->next;
        current->next = newNode;
    }
}

void insertAtMid()
{
    Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == nullptr)
    {
        cout << "Memory allocation failed\n";
        return;
    }

    Node *ptr = head;
    int data, size = 0;

    while (ptr != nullptr)
    {
        size++;
        ptr = ptr->next;
    }

    if (size >= 2)
    {
        cout << "Enter Element: ";
        cin >> data;
        newNode->data = data;

        int mid = size / 2;
        ptr = head;
        for (int i = 1; i < mid; i++)
        {
            ptr = ptr->next;
        }

        newNode->next = ptr->next;
        ptr->next = newNode;
        cout << "Element Inserted: " << newNode->data << endl;
    }
    else
    {
        cout << "Please insert more than two elements, then insert in the middle." << endl;
    }
}

void showList()
{
    if (head == nullptr)
    {
        cout << "Linked List Empty:";
        return;
    }

    cout << "Elements are: " << endl;
    Node *ptr = head;
    while (ptr != nullptr)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

void deleteFromBeginning()
{
    if (head == nullptr)
    {
        cout << "Linked List is Empty." << endl;
        return;
    }

    Node *currentNode = head;
    head = head->next;

    cout << "Node Deleted successfully! " << currentNode->data << endl;
    free(currentNode);
}

void deleteFromEnd()
{
    if (head == nullptr)
    {
        cout << "Linked List is Empty." << endl;
        return;
    }

    if (head->next == nullptr)
    {
        cout << "Node Deleted successfully! " << head->data << endl;
        free(head);
        head = nullptr;
        return;
    }

    Node *ptr = head;
    while (ptr->next->next != nullptr)
    {
        ptr = ptr->next;
    }

    Node *currentNode = ptr->next;
    ptr->next = nullptr;
    cout << "Node Deleted successfully! " << currentNode->data << endl;
    free(currentNode);
}

void deleteAfterPosition()
{
    if (head == nullptr)
    {
        cout << "Linked List is Empty." << endl;
        return;
    }

    int position;
    cout << "Enter position: ";
    cin >> position;

    // Check if position is valid
    if (position < 1)
    {
        cout << "Invalid position." << endl;
        return;
    }

    Node *ptr = head;

    if (position == 1)
    {
        head = head->next;
        cout << "Node Deleted successfully! " << ptr->data << endl;
        free(ptr);
        return;
    }

    for (int i = 1; i < position - 1 && ptr != nullptr; i++)
    {
        ptr = ptr->next;
    }

    if (ptr == nullptr || ptr->next == nullptr)
    {
        cout << "Position out of range." << endl;
        return;
    }

    Node *nodeToDelete = ptr->next;
    ptr->next = nodeToDelete->next;
    cout << "Node Deleted successfully! " << nodeToDelete->data << endl;
    free(nodeToDelete);
}

void deleteAtMid() {
    if (head == nullptr) {
        cout << "Linked List is Empty." << endl;
        return;
    }

    int size = 0;
    Node *ptr = head;
    while (ptr != nullptr) {
        size++;
        ptr = ptr->next;
    }

    if (size <= 2) {
        cout << "Node less than 3, no middle node to delete." << endl;
        return;
    }

    int mid = size / 2;
    ptr = head;

    for (int i = 1; i < mid; i++) {
        ptr = ptr->next;
    }

    Node* deleteNode = ptr->next;
    cout << "Node deleted: " << deleteNode->data << endl;
    ptr->next = deleteNode->next;
    free(deleteNode);
}

void searchElement() {
    if (head == nullptr) {
        cout << "Linked List Empty!" << endl;
        return;
    }

    cout << "Enter Node which you want to search: ";
    int data, i = 1;
    cin >> data;

    Node *ptr = head;
    while (ptr != nullptr) {
        if (ptr->data == data) {
            cout << "Element " << data << " found at position " << i << endl;
            return;
        }

        ptr = ptr->next;
        i++;
    }

    // If we exit the loop without finding the element
    cout << "Element not found: " << data << endl;
}

void getLength() {
    Node *ptr = head;
    int size = 0;
    while (ptr != nullptr) {
        ptr = ptr->next;
        size++;
    }

    cout << "Size of Linked List: " << size << endl;
}

/*void findMiddle(){
    if (head == nullptr) {
        cout << "Linked List Empty!" << endl;
        return;
    }

    Node *ptr = head;
    int size = 0;
    while(ptr != nullptr){
        ptr = ptr->next;
        size++;
    }

    int mid = abs(size/2);
    ptr = head;

    int i = 0;
    while (i <mid)
    {
        ptr = ptr->next;
        i++;
    }

    cout<<"Middle Node "<<ptr->data;
    
}*/

void findMiddle(){
    if (head == nullptr) {
        cout << "Linked List Empty!" << endl;
        return;
    }

    Node *slow = head;
    Node *fast = head;

    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }

    cout << "Middle Node: " << slow->data << endl;

}

void detectCycle(){
    if (head == nullptr) {
        cout << "Linked List Empty!" << endl;
        return;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            cout << "Cycle detected" <<slow->data<< endl;
            return;
        }
    }

    cout << "No cycle detected" << endl;
    
}