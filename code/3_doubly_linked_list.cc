#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    
    // Constructor for creating a new node
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
    private:
        Node* head;

    public:
        DoublyLinkedList() : head(nullptr) {}

        void insertAtBeginning(int data){
            Node *newNode = new Node(data);
            if(head != nullptr){
                head->prev = newNode;
                newNode->next = head;
            }
            head = newNode;
            cout << "Element inserted at beginning: " << data << endl;
        }

        void insertAtEnd(int data){
            Node *newNode = new Node(data);
            if(newNode == nullptr){
                cout<<"Failed to allocate memory: "<<endl;
                return;
            }

            if(head == nullptr){
                head = newNode;
                cout<<"Element inserted: "<<newNode->data<<endl;
                return;
            }

            Node *ptr = head;
            while (ptr->next != nullptr)
            {
                ptr = ptr->next;
            }

            ptr->next = newNode;
            newNode->prev = ptr;
            cout << "Element inserted at end: " << data << endl;
            
        }

        void insertAtRandom(int data){
            int position;
            cout<<"Enter Position where do you want to insert: ";
            cin>>position;

            if(position == 1){
                insertAtBeginning(data);
                return;
            }

            Node *newNode = new Node(data);
            Node *ptr = head;

            for (int i = 1; i < position - 1 && ptr != nullptr; i++) {
                ptr = ptr->next;
            }

             if (ptr == nullptr) {
                cout << "Position out of range" << endl;
                return;
            }

            newNode->next = ptr->next;

            if(ptr->next != nullptr){
                ptr->next->prev = newNode;
            }
            
            ptr->next = newNode;
            newNode->prev = ptr;
            cout << "Element inserted at position " << position << ": " << data << endl;
        }

        // this function automated takes abs value then insert after that value 
        void insertAtMid(int data){
            if(head == nullptr){
                insertAtBeginning(data);
                return;
            }

            Node *newNode = new Node(data);
            if(newNode == nullptr){
                cout<<"Memeory allocation failed: "<<endl;
                return;
            }

            int size = 1;
            Node *slow = head;
            Node *fast = head->next;

             while (fast != nullptr && fast->next != nullptr) {   
                size++;
                slow = slow->next;
                fast = fast->next->next;
            }


            if(size < 2){
                cout<<"Node less than 2 please instert atleat two node then insert it? "<<endl;
                return;
            }

            // 10 20 30 40 
            //       s  f


            // cout<<slow->data;

            newNode->next = slow->next;
             if (slow->next != nullptr) {
                slow->next->prev = newNode;
            }
            slow->next = newNode;
            newNode->prev = slow;
            cout<<"Element Inserted: "<<newNode->data<<endl;

            
        }

        void deleteFromBeginning(){
             if (head == nullptr) {
                cout << "Doubly Linked list is empty." << endl;
                return;
            }

            
            Node *temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }

            cout<<"Node Deleted: "<<temp->data;
            free(temp);
        }
        
        void deleteFromEnd(){
            if (head == nullptr) {
                cout << "Doubly Linked list is empty." << endl;
                return;
            }

            Node *temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }

            cout<<"Node Deleted: "<<temp->data;

            if(temp->prev == nullptr){
                head = nullptr;
            }else{
                temp->prev->next = nullptr;
            }
            
            delete temp;

        }

        void deleteAfterPosition(){
            if (head == nullptr) {
                cout << "Doubly Linked list is empty." << endl;
                return;
            }

            int position;
            cout << "Enter position after which to delete node: ";
            cin >> position;

            if(position == 1){
                cout<<"Node Deleted: "<<head->data;
                Node *temp = head;
                head = head->next;
                free(temp);
                head->prev = nullptr;
                return;
            }

            Node *temp = head;
            for(int i=1; i <= position-1; i++){

                 if (temp == nullptr) {
                    cout << "Position out of range." << endl;
                    return;
                }
                temp = temp->next;
            }

            cout<<"Node Deleted: "<<temp->data;

            if(temp->next == nullptr){
                temp->prev->next = nullptr;
            }

            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            delete temp;

        }

        void deleteAtMid(){
            if (head == nullptr) {
                cout << "Doubly Linked list is empty." << endl;
                return;
            }

            int size = 0;
            Node* slow = head;
            Node* fast = head->next;
            while(fast != nullptr && fast->next != nullptr){
                slow = slow->next;
                fast = fast->next->next;
                // size++;
            }

            cout<<"Node Deleted: "<<slow->data;
            slow->prev->next = slow->next;
            slow->next->prev = slow->prev;

            delete slow;
        }

        void showList(){
            if(head == nullptr){
                cout << "Doubly Linked List is Empty!" << endl;
                return;
            }

            Node *ptr = head;
            cout<<"Element are: "<<endl;
            while(ptr != nullptr){
                cout<<ptr->data<<" ";
                ptr = ptr->next;
            }
            cout<<endl;
        }

        void searchElement(){
            if(head == nullptr){
                cout << "Doubly Linked List is Empty!" << endl;
                return;
            }

            int element, pos = 0;
            cout<<"Enter Element which you want to search: ";
            cin>>element;

            Node *ptr = head;

            while (ptr != nullptr)
            {   
                pos++;
                if(element == ptr->data){
                    cout << "Element " << element << " found at position " << pos << endl;
                    return;
                }
                ptr = ptr->next;
            }

            cout << "Element not found: " << element << endl;
            
        }

        void getLength(){
            if(head == nullptr){
                cout << "Doubly Linked List is Empty!" << endl;
                return;
            }

            Node* ptr = head;
            int size=0;
            while(ptr != nullptr){
                ptr = ptr->next;
                size++;
            }

            cout << "Size Of Linked List: " << size << endl;
        }

        void findMiddle(){
            if(head == nullptr){
                cout << "Doubly Linked List is Empty!" << endl;
                return;
            }

            Node* slow = head;
            Node* fast = head->next;

            while (fast != nullptr && fast->next != nullptr)
            {
                slow = slow->next;
                fast = fast->next;
            }

            cout<<"Middle Node is: "<<slow->data;
            
        }

        void traverseBackward(){
            if(head == nullptr){
                cout << "Doubly Linked List is Empty!" << endl;
                return;
            }

            cout << "Doubly Linked List in reverse order: "<<endl;
            Node *ptr = head;
            while (ptr->next != nullptr)
            {
                ptr = ptr->next;
            }

            Node *current = ptr;
            while (current != nullptr)
            {
                cout<<current->data<<" ";
                current = current->prev;
            }

        }
        
        void detectCycle(){
            if(head == nullptr){
                cout << "Doubly Linked List is Empty!" << endl;
                return;
            }

            Node *slow = head;
            Node *fast = head;

            while (fast != nullptr && fast->next != nullptr)
            {
                slow = slow->next;
                fast = fast->next->next;

                if(slow == fast){
                    cout << "Cycle detected at node with data: " << slow->data << endl;
                    return;
                }
            }

            cout << "No cycle detected" << endl;
        }
        
        void detectCycleStart(){
            if(head == nullptr){
                cout << "Doubly Linked List is Empty!" << endl;
                return;
            }

            Node *slow = head;
            Node *fast = head;

            while (fast != nullptr && fast->next != nullptr)
            {
                slow = slow->next;
                fast = fast->next->next;

                if(slow == fast){
                    slow = head;
                    while (slow != fast)
                    {
                        slow = slow->next;
                        fast = fast->next;
                    }

                    cout << "Cycle starts at node with data: " << slow->data << endl;
                    return;
                    
                }
                
            }

            cout << "No cycle detected" << endl;
            

        }

        void removeCycle(){
            if(head == nullptr){
                cout << "Doubly Linked List is Empty!" << endl;
                return;
            }

            Node *slow = head;
            Node *fast = head;

            while (fast != nullptr && fast->next != nullptr)
            {
                slow = slow->next;
                fast = fast->next->next;

                if(slow == fast){
                    slow = head;
                    Node *lastNode = nullptr;
                    while (slow != fast)
                    {
                        lastNode = fast;
                        slow = slow->next;
                        fast = fast->next;
                    }

                    lastNode->next = nullptr;
                    cout << "Cycle removed" << endl;
                    return;
                    
                }
            }
            
            cout << "No cycle detected" << endl;
        }

        void reverseList(){
            if(head == nullptr){
                cout << "Doubly Linked List is Empty!" << endl;
                return;
            }

            Node* currentNode = head;
            Node* temp = nullptr;

            while (currentNode != nullptr)
            {
                temp = currentNode->prev;
                currentNode->prev = currentNode->next;
                currentNode->next = temp;
                
                currentNode = currentNode->prev;
            }

            if (temp != nullptr) {
                head = temp->prev;
            }

            cout << "Linked List Reversed!" << endl;
            
        }

};



int main() {
    DoublyLinkedList dll;
    int choice, data;

    while (1) {
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
        cout << "10. Traverse forward list\n";
        cout << "11. Traverse backward list\n";
        cout << "12. Search for an element\n";
        cout << "13. Get Length of Linked List\n";
        cout << "14. Get Middle Node\n";
        cout << "15. Detect Cycle in Linked List\n";
        cout << "16. Detect Cycle From Start Node\n";
        cout << "17. Remove Cycle\n";
        cout << "18. Reverse Linked List\n";
        // cout << "19. Sort Linked List\n";
        cout << "20. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to insert at beginning: ";
                cin >> data;
                dll.insertAtBeginning(data);
                break;
            case 2:
                cout << "Enter element to insert at end: ";
                cin >> data;
                dll.insertAtEnd(data);
                break;
            case 3:
                cout << "Enter element and position to insert at: ";
                cin >> data;
                dll.insertAtRandom(data);
                break;
            case 4:
                cout << "Enter element to insert at end: ";
                cin >> data;
                dll.insertAtMid(data);
                break;
            case 5:
                dll.deleteFromBeginning();
                break;
            case 6:
                dll.deleteFromEnd();
                break;
            case 7:
                dll.deleteAfterPosition();
                break;
            case 8:
                dll.deleteAtMid();
                break;
            case 9:
                dll.showList();
                break;
            case 10:
                dll.showList();
                break;
            case 11:
                dll.traverseBackward();
                break;
            case 12:
                dll.searchElement();
                break;
            case 13:
                dll.getLength();
                break;
            case 14:
                dll.findMiddle();
                break;
            case 15:
                dll.detectCycle();
                break;
            case 16:
                dll.detectCycleStart();
                break;
            case 17:
                dll.removeCycle();
                break;
            case 18:
                dll.reverseList();
                break;
            case 20:
                exit(0);
            default:
                cout << "Enter a valid choice: ";
        }
    }

    return 0;
}