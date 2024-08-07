#include <iostream>
using namespace std;


struct Node{
    int data;
    struct Node* next;
};

class Stack
{
    private:
        Node* head;

    public:

        Stack() : head(nullptr) {} // Constructor to initialize head to nullptr

        // Destructor to clean up memory
        // ~Stack() {
        //     while (!isEmpty()) {
        //         pop();
        //     }
        // }

        void push(int data){
            Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            if (!newNode) {
                cout << "Memory Allocation failed." << endl;
                return;
            }

            newNode->data = data;
            newNode->next = head;
            head = newNode;
            cout << "Element Inserted: " << head->data << endl;
        }

        void pop(){
            if(head == nullptr){
                cout<<"Stack is empty: "<<endl;
                return;
            }

            cout<<"Element deleted: "<<head->data<<endl;
            Node *temp = head;
            head = head->next;
            delete temp;
        }

        void display(){
            if(head == nullptr){
                cout<<"Stack is Empty: "<<endl;
                return;
            }

            Node* ptr = head;
            cout<<"Element are: "<<endl;
            while(ptr != nullptr){
                cout<<ptr->data<<" ";
                ptr = ptr->next;
            }
        }

        bool isEmpty(){
            if(head == nullptr){
                return true;;
            }else{
                return false;
            }

        }
        bool isFull(){
            Node* newNode = new Node;
            if(!newNode){
                return true;
            }else{
                return false;
            }
        }

        void stackEmpty(){
            if(head == nullptr){
                cout<<"Stack is UnderFlow: "<<endl;
                return;
            }else{
                cout<<"Stack is not Empty: "<<endl;
            }
        }
        void stackFull(){
            Node* newNode = new Node;
            if(!newNode){
                cout<<"Stack is Overflow: "<<endl;
                return;
            }else{
                cout<<"Stack is not Full: "<<endl;
            }
        }

        void peek(){
            if(isEmpty()){
               cout<<"Stack is Empty: "<<endl;
               return;
            }
           
            cout<<"Element is: "<<head->data<<endl;
        }

        void stackBottomElemnt(){
            if(isEmpty()){
               cout<<"Stack is Empty: "<<endl;
               return;
            }

            Node *ptr = head;
            while(ptr->next != nullptr){
                ptr = ptr->next;
            }
            cout<<"Element is: "<<ptr->data<<endl;
        }

        void stackSize(){
            if(isEmpty()){
               cout<<"Stack is Empty: "<<endl;
               return;
            }

            Node *ptr = head;
            int i =0 ;
            while(ptr != nullptr){
                i++;
                ptr = ptr->next;
            }
            cout<<"Stack Total Size/Element: "<<i<<endl;
        }
    
};

int main()
{
    Stack s;
    int choice, value;

    while (1)
    {
        cout << "\n\n********* Stack Operations Menu *********\n";
        cout << "Choose one option from the following list ...\n";
        cout << "===============================================\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek/Top Element\n";
        cout << "4. Lower Element\n";
        cout << "5. Stack is Empty\n";
        cout << "6. Stack is Full\n";
        cout << "7. Stack Total Size\n";
        cout << "8. Stack Current Size\n";
        cout << "9. Stack Print\n";
        cout << "10. Stack Total Element\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the value to push into the stack: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.peek();
            break;
        case 4:
            s.stackBottomElemnt();
            break;
        case 5:
            s.stackEmpty();
            break;
        case 6:
            s.stackFull();
            break;
        case 7:
            s.stackSize();
            break;
        case 8:
            s.stackSize();
            break;
        case 9:
            s.display();
            break;
        case 10:
            s.stackSize();
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
