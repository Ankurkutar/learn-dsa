#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int data) : data(data), next(nullptr) {}
};

class SingleCircularList
{
    private:
        Node *head;

    public:
        SingleCircularList() : head(nullptr) {}

        void insertAtBeginning(int data)
        {
           Node* newNode = new Node(data);
           if(!newNode){
                cout << "Memory allocation failed" << endl;
                return;
           }

           if(head == nullptr){
                head = newNode;
                head->next = head;
                // newNode->next = head;
           }else{
                Node *temp = head;
                while (temp->next != head)
                {
                    temp = temp->next;
                }

                newNode->next = temp->next;
                temp->next = newNode;
                head = newNode;
           }
           cout << "Node inserted at the beginning: " << data << endl;
        }

        void insertAtEnd(int data){
            Node* newNode = new Node(data);
            if(!newNode){
                cout << "Memory allocation failed" << endl;
                return;
            }

            if(head == nullptr){
                head = newNode;
                newNode->next = head;
            }

            Node* ptr = head;
            while (ptr->next != head)
            {
                ptr = ptr->next;
            }

            newNode->next = head;
            ptr->next = newNode;

            cout << "Node inserted at the end: " << data << endl;
            
        }

        void insertAtRandom(int data, int position){
            Node* newNode = new Node(data);
            if(!newNode){
                cout << "Memory allocation failed" << endl;
                return;
            }

            if(head == nullptr){
                if(position != 1){
                    cout << "Position out of range" << endl;
                    delete newNode;
                    return;
                }
                head = newNode;
                newNode->next = head;
                cout << "Node inserted at position " << position << ": " << data << endl;
                return;
            }

            if(position == 1){
                Node *ptr = head;
                while (ptr->next != head)
                {
                    ptr = ptr->next;
                }

                ptr->next = newNode;
                newNode->next = head;
                head = newNode;
                cout << "Node inserted at position " << position << ": " << data << endl;
                return;
            }

            Node* current = head;
            for(int i=1; i<position-1; i++){
                current = current->next;
                if (current == head) {
                    cout << "Position out of range" << endl;
                    delete newNode;
                    return;
                }
            }

            cout<<current->data;
            newNode->next = current->next;
            current->next = newNode;
            cout << "Node inserted at position " << position << ": " << data << endl;

        }

        void insertAtMid(int data){
            Node* newNode = new Node(data);
            if(!newNode){
                cout << "Memory allocation failed" << endl;
                return;
           }   

            if (head == nullptr) {
                head = newNode;
                newNode->next = head;
                cout << "Node inserted at start: " << data << endl;
                return;
            }


           Node* slow = head;
           Node* fast = head;

           while(fast->next != head && fast->next->next != head)
           {
                slow = slow->next;
                fast = fast->next->next;
           } 

        //    cout<<slow->data<<" "<<fast->data;
           newNode->next = slow->next;
           slow->next = newNode;
           cout << "Node inserted at middle: " << data << endl;
            
        }

        void deleteFromBeginning(){
            if(head == nullptr){
                cout << "Circular Linked List is empty." << endl;
                return;
            }

            Node* temp = head;
            if(head->next == head){
                head = nullptr;
            }else{
                Node* last = head;
                while(last->next != head){
                    last = last->next;
                }

                head = head->next;
                last->next = head;
                
            }
            
            cout << "Node Deleted: " << temp->data << endl;
            delete temp;
        }

        void deleteFromEnd(){
            if(head == nullptr){
                cout << "Circular Linked List is empty." << endl;
                return;
            }

            Node* temp = head;
            if(head->next == head){
                head = nullptr;
            }else{
                Node *last = head;
                while (last->next->next != head)
                {
                    last = last->next;
                }

                temp = last->next;
                last->next = head;
                
            }

            cout << "Node Deleted: " << temp->data << endl;
            delete temp;
        }

        void deleteAfterPosition(){
            if(head == nullptr){
                cout << "Circular Linked List is empty." << endl;
                return;
            }
        }

        void showList()
        {
            if(head == nullptr){
                cout << "List is empty" << endl;
                return;
            }

            Node *ptr  = head;
            do{
                cout<<ptr->data<<" ";
                ptr = ptr->next;
            }while (ptr != head);
            
            cout<<endl;
        }


};

// for inserting
// void insertAtBeginning();
// void insertAtEnd();
// void insertAtRandom();
// void insertAtMid();

// for deleting
// void deleteFromBeginning();
// void deleteFromEnd();
// void deleteAfterPosition();
// void deleteAtMid();

// for searching
// void searchElement();
// void showList();

// for reverse list
// void reverseList();

// additional functions
// void getLength();
// void findMiddle();

// void detectCycle();
// void detectCycleStart();
// void removeCycle();

// void sortList();
// Node *merge(Node *, Node *);
// Node *getMiddle(Node *);
// Node *mergeSort(Node *);
// void mergeSortedLists(Node* list1, Node* list2);

int main()
{
    SingleCircularList ll;
    int choice, data, position;
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
        cout << "14. Detect Cycle From Start Node\n";
        cout << "15. Remove Cycle\n";
        cout << "16. Reverse Linked List\n";
        cout << "17. Sort Linked List\n";
        cout << "18. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter element to insert at beginning: ";
            cin >> data;
            ll.insertAtBeginning(data);
            break;
        case 2:
            cout << "Enter element to insert at beginning: ";
            cin >> data;
            ll.insertAtEnd(data);
            break;
        case 3:
            cout << "Enter element to insert at beginning: ";
            cin >> data;
            cout << "Enter Position where want to insert: ";
            cin >> position;
            ll.insertAtRandom(data, position);
            break;
        case 4:
            cout << "Enter element to insert at beginning: ";
            cin >> data;
            ll.insertAtMid(data);
            break;
        case 5:
            ll.deleteFromBeginning();
            break;
        case 6:
            ll.deleteFromEnd();
            break;
        // case 7:
            ll.deleteAfterPosition();
        //     break;
        // case 8:
        //     deleteAtMid();
        //     break;
        case 9:
            ll.showList();
            break;
        // case 10:
        //     searchElement();
        //     break;
        // case 11:
        //     getLength();
        //     break;
        // case 12:
        //     findMiddle();
        //     break;
        // case 13:
        //     detectCycle();
        //     break;
        // case 14:
        //     detectCycleStart();
        //     break;
        // case 15:
        //     removeCycle();
        //     break;
        // case 16:
        //     reverseList();
        //     break;
        // case 17:
        //     sortList();
        //     break;
        case 18:
            exit(0);
            break;
        default:
            cout << "Enter a valid a choice: ";
        };
    }

    return 0;
}
