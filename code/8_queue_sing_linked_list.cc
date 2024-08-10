#include<iostream>
#include<unordered_set>
using namespace std;

struct Node{
    int data;
    struct Node *next;
    Node(int data){
        this->data = data;
        next = nullptr;
    }
};

class Queue{
    private:
        Node* head;
    public:
        Queue(){
            head = nullptr;
        }

        void enqueue(int data){
            Node *newNode = new Node(data);
            if(!newNode){
                cout<<"Memory Allocation failed: "<<endl;
                return;
            }

            if(head == nullptr){
                head = newNode;
                cout<<"Node Inserted: "<<data<<endl;
                return;
            }

            Node *ptr = head;
            while(ptr->next != nullptr){
                ptr = ptr->next;
            }

            ptr->next = newNode;
            cout<<"Node Inserted: "<<data<<endl;
        }

        void dequeue(){
            if(head == nullptr){
                cout<<"Queue is Empty: "<<endl;
                return;
            }

            Node *temp = head;
            head = head->next;
            cout<<"Node deleted: "<<temp->data<<endl;
            delete temp;
        }

        void display(){
            if(head == nullptr){
                cout<<"Queue is Empty: "<<endl;
                return;
            }
            Node *ptr = head;
            cout<<"Element are: "<<endl;
            while (ptr != nullptr)
            {
                cout<<ptr->data<<" ";
                ptr = ptr->next;
            }
            
        }

        void queueBottomElement(){
            if(head == nullptr){
                cout<<"Queue is Empty: "<<endl;
                return;
            }
            cout<<"Fist Node in the linked list: "<<head->data<<endl;
        }
        void queueTopElement(){
            if(head == nullptr){
                cout<<"Queue is Empty: "<<endl;
                return;
            }

            if(head->next == nullptr){
                cout<<"Last Node in the linked list: "<<head->data<<endl;
                return;
            }

            Node *ptr = head;
            while(ptr->next != nullptr){
                ptr = ptr->next;
            }
            cout<<"Last Node in the linked list: "<<ptr->data<<endl;
        }

        void isEmpty(){
            if(head == nullptr){
                cout<<"Queue is Empty: "<<endl;
            }else{
                cout<<"Queue is not Empty: "<<endl;
            }
        }
        void isFull(){
            if(head == nullptr){
                cout<<"Queue is Full: "<<endl;
            }else{
                cout<<"Queue is not Full: "<<endl;
            }
        }

        void queueElement(){
            if(head == nullptr){
                cout<<"Queue is Empty: "<<endl;
                return;
            }

            int i = 0;
            Node *ptr = head;
            while (ptr != nullptr)
            {
                i++;
                ptr = ptr->next;
            }

            cout<<"Total Node in the Linked list is: "<<i<<endl;
        }

        void findElement(){
            if(head == nullptr){
                cout<<"Queue is Empty: "<<endl;
                return;
            }
            int i =0, data;
            cout<<"Enter Element which you want to find: ";
            cin>>data;

            bool flag = false;
            Node *ptr = head;
            while (ptr != nullptr)
            {
                i++;
                if(ptr->data == data){
                    flag = true;
                    return;
                }
                ptr = ptr->next;
            }

            if(flag)
            {
                cout<<"Element found in the linked list at: "<<i<<" "<<data<<endl;
            }else{
                cout<<"Element not found in the linked list: "<<endl;
            }        
        }

        void duplicateElement() {
        if (head == nullptr) {
            cout << "Queue is Empty." << endl;
            return;
        }

        unordered_set<int> elementSet;  // Corrected spelling
        bool foundDuplicate = false;
        Node* ptr = head;

        while (ptr != nullptr) {
            if (elementSet.find(ptr->data) != elementSet.end()) {
                cout << "Duplicate Element found: " << ptr->data << endl;
                foundDuplicate = true;
            } else {
                elementSet.insert(ptr->data);
            }
            ptr = ptr->next;
        }

        if (!foundDuplicate) {
            cout << "No duplicate elements found in the queue." << endl;
        }
        
    }

};



int main()
{
    Queue q;
    int choice, value;

    while (1)
    {
        cout << "\n\n********* Queue Operations Menu *********\n";
        cout << "Choose one option from the following list ...\n";
        cout << "===============================================\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Front Element\n";
        cout << "5. Rear Element\n";
        cout << "6. Queue is Empty\n";
        cout << "7. Queue is Full\n";
        cout << "8. Total Element in the Queue \n";
        cout << "9. Find Element in the Queue \n";
        cout << "10. Duplicate Element in the Queue \n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the value to push into the Queue: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            q.queueBottomElement();
            break;
        case 5:
            q.queueTopElement();
            break;
        case 6:
            q.isEmpty();
            break;
        case 7:
            q.isFull();
            break;
        case 8:
            q.queueElement();
            break;
        case 9:
            q.findElement();
            break;
        case 10:
            q.duplicateElement();
            break;
        case 11:
            exit(0);
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}